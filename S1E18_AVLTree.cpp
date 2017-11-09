// Набросок АВЛ-дерева

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

struct CAVLNode {
public:
	int Key = 0;
	CAVLNode* Left = 0;
	CAVLNode* Right = 0;
	int Height = 0;

	explicit CAVLNode( int key ) : Key( key ), Height( 1 ) {}
};

////////////////////////////////////////////////////////////////////////////////////////////////////

// forward declaration
CAVLNode* balance( CAVLNode* tree );

////////////////////////////////////////////////////////////////////////////////////////////////////

// Высота дерева.
int safeHeight( CAVLNode* tree )
{
	if( tree == 0 ) {
		return 0;
	}
	return tree->Height;
}

// Обновляет поле Height корневого узла дерева.
void updateHeight( CAVLNode* tree )
{
	if( tree == 0 ) {
		return;
	}
	tree->Height = max(
		safeHeight( tree->Left ),
		safeHeight( tree->Right ) ) + 1;
}

// Добавление узла.
CAVLNode* add( CAVLNode* tree, int key )
{
	if( tree == 0 ) {
		return new CAVLNode( key );
	}
	if( key < tree->Key ) {
		tree->Left = add( tree->Left, key );
	} else {
		tree->Right = add( tree->Right, key );
	}
	balance( tree );
	return tree;
}

// Поиск узла по ключу.
CAVLNode* find( CAVLNode* tree, int key )
{
	if( tree == 0 ) {
		return 0;
	}
	if( tree->Key == key ) {
		return tree;
	}
	if( key < tree->Key ) {
		return find( tree->Left, key );
	} else {
		return find( tree->Right, key );
	}
}

// Балансировка узла.
CAVLNode* balance( CAVLNode* tree )
{
	if( tree == 0 ) {
		return 0;
	}
	const int imbalance = safeHeight( tree->Left ) 
		- safeHeight( tree->Right );
	if( imbalance < -1 ) {
		// Правая часть слишком высокая
		assert( imbalance == -2 );
		assert( tree->Right != 0 );
		CAVLNode* a = tree;
		CAVLNode* b = tree->Right;
		CAVLNode* L = tree->Left;
		CAVLNode* c = b->Left;
		CAVLNode* R = b->Right;
		if( safeHeight( c ) <= safeHeight( R ) ) {
			b->Left = a;
			a->Left = L;
			a->Right = c;
			b->Right = R; // лишнее
			updateHeight( a );
			updateHeight( b );
			return b;
		} else {
			CAVLNode* c1 = c->Left;
			CAVLNode* c2 = c->Right;
			a->Right = c1;
			c->Left = a;
			b->Left = c2;
			c->Right = b;
			updateHeight( a );
			updateHeight( b );
			updateHeight( c );
			return c;
		}
	} else if( imbalance > 1 ) {
		assert( false ); // ToDo...
		return 0; // Чтобы не было warning
	} else {
		return tree;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
