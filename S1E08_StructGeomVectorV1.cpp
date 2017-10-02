// Использование структур на примере вектора на плоскости.

#include <iostream>

using namespace std;

// Структуры позволяют комбинировать несколько типов в один составной тип.
// Данная структура описывает вектор на плоскости.
// Что здесь написано:
//   struct - ключевое слово.
//   CGeomVectorV1 - имя структуры (по сути имя типа).
//   { - начало тела структуры.
//   int x; - поле типа int с именем x.
//   int y; - поле типа int с именем y.
//   } - конец тела структуры.
//   ; - в конце определения структуры нужно не забыть поставить точку с запятой.
struct CGeomVectorV1 {
	int x;
	int y;
};

// Вычисление длины вектора.
// "const CGeomVectorV1& v" - константная ссылка на внешнюю переменную. Такой приём используется
// для оптимизации, чтобы избежать лишнего копирования переменных.
double length( const CGeomVectorV1& v )
{
	return sqrt( v.x * v.x + v.y * v.y );
}

// Вывод вектора.
void print( const CGeomVectorV1& v )
{
	cout << "( " << v.x << ", " << v.y << " )" << endl;
}

// Вычитание векторов.
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
	// Создаём вектор v1.
	CGeomVectorV1 v1;
	// Поля CGeomVectorV1 неинициализированы (содержат мусор). Заполняем.
	v1.x = 4;
	v1.y = 6;
	print( v1 );

	// Структуры можно инициализировать так:
	CGeomVectorV1 v2 = { 1, 2 };
	print( v2 );

	// Со структурами можно работать как с обычными типами.
	CGeomVectorV1 delta = sub( v1, v2 );
	print( delta );
	cout << length( delta ) << endl;

	// Массив структур:
	CGeomVectorV1 a[3] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	for( int i = 0; i < 3; i++ ) {
		print( a[i] );
	}

	cin.ignore();
	return 0;
}
