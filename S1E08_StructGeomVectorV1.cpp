// »спользование структур на примере вектора на плоскости.

#include <iostream>

using namespace std;

// —труктуры позвол€ют комбинировать несколько типов в один составной тип.
// ƒанна€ структура описывает вектор на плоскости.
// „то здесь написано:
//   struct - ключевое слово.
//   CGeomVectorV1 - им€ структуры (по сути им€ типа).
//   { - начало тела структуры.
//   int x; - поле типа int с именем x.
//   int y; - поле типа int с именем y.
//   } - конец тела структуры.
//   ; - в конце определени€ структуры нужно не забыть поставить точку с зап€той.
struct CGeomVectorV1 {
	int x;
	int y;
};

// ¬ычисление длины вектора.
// "const CGeomVectorV1& v" - константна€ ссылка на внешнюю переменную. “акой приЄм используетс€
// дл€ оптимизации, чтобы избежать лишнего копировани€ переменных.
double length( const CGeomVectorV1& v )
{
	return sqrt( v.x * v.x + v.y * v.y );
}

// ¬ывод вектора.
void print( const CGeomVectorV1& v )
{
	cout << "( " << v.x << ", " << v.y << " )" << endl;
}

// ¬ычитание векторов.
CGeomVectorV1 sub( const CGeomVectorV1& v1, const CGeomVectorV1& v2 )
{
	CGeomVectorV1 v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return v;
}

// main
int main_StructGeomVectorV1()
{
	// —оздаЄм вектор v1.
	CGeomVectorV1 v1;
	// ѕол€ CGeomVectorV1 неинициализированы (содержат мусор). «аполн€ем.
	v1.x = 4;
	v1.y = 6;
	print( v1 );

	// —труктуры можно инициализировать так:
	CGeomVectorV1 v2 = { 1, 2 };
	print( v2 );

	// —о структурами можно работать как с обычными типами.
	CGeomVectorV1 delta = sub( v1, v2 );
	print( delta );
	cout << length( delta ) << endl;

	// ћассив структур:
	CGeomVectorV1 a[3] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	for( int i = 0; i < 3; i++ ) {
		print( a[i] );
	}

	cin.ignore();
	return 0;
}
