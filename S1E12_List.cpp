// Работа с указателями на примере списка.
// Разобрать:
//  1) значение аргумента по умолчанию (строка 32)
//  2) оператор ->
//  3) inline функции
//  4) что делает assert
//  5) передача параметра по ссылке / указателю
//  6) new / delete (4 вида памяти: статическая, константная, куча, стек)

#include <iostream>
#include <assert.h>

using namespace std;

struct CNode {
	CNode* next;
	int data;
};

struct CList {
	CNode* root;
	CNode* last;
};

inline void initializeList( CList& list )
{
	list.root = nullptr;
	list.last = nullptr;
}

inline void initializeNode( CNode& node, int data = 0 )
{
	node.data = data;
	node.next = nullptr;
}

void pushBack( CList& list, int data )
{
	CNode* node = new CNode;
	initializeNode( *node, data );
	if( list.last == 0 ) {
		list.root = node;
	} else {
		list.last->next = node; // (*(list.last)).next
	}
	list.last = node;
}

void popFront( CList& list )
{
	assert( list.root != nullptr );
	CNode* first = list.root;
	list.root = first->next;
	delete first;
	if( list.root == nullptr ) {
		list.last = nullptr;
	}
}

int getFirst( CList& list )
{
	assert( list.root != nullptr );
	return list.root->data;
}

// main
int main_List()
{
	CList list;
	initializeList( list );
	pushBack( list, 1 );
	pushBack( list, 2 );
	popFront( list );
	popFront( list );
	return 0;
}
