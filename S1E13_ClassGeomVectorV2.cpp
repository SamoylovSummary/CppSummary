// Простой класс на примере вектора на плоскости.

#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

// Перепишем вектор на плоскости (см. CGeomVectorV1) с применением классов.
class CGeomVectorV2 {
public:
	// Публичная секция. Поля (данные и методы), определённые в этой секции, доступны внешним 
	// пользователям класса.

	// Два поля типа int.
	int x;
	int y;

	// Конструктор по умолчанию.
	CGeomVectorV2();

	// Конструктор с параметрами.
	CGeomVectorV2( int x, int y );

	// Вычисление длины вектора.
	// const в конце означает, что метод не может менять объект. То есть может только читать поля x и y.
	double CalculateLength() const;

	// Вывод вектора в cout.
	void Print() const;

	// Оператор минус для векторов.
	CGeomVectorV2 operator-( const CGeomVectorV2& other ) const;

	// Оператор плюс для векторов.
	CGeomVectorV2 operator+( const CGeomVectorV2& other ) const;

	// Оператор умножить используем для вычисления скалярного произведения.
	int operator*( const CGeomVectorV2& other ) const;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

// Конструктор по умолчанию.
CGeomVectorV2::CGeomVectorV2()
{
	x = 0;
	y = 0;
}

// Конструктор с параметрами.
CGeomVectorV2::CGeomVectorV2( int _x, int _y )
{
	x = _x;
	y = _y;
}

// Вычисление длины вектора.
double CGeomVectorV2::CalculateLength() const
{
	return sqrt( x * x + y * y );
}

// Вывод вектора в cout.
void CGeomVectorV2::Print() const
{
	cout << "( " << x << ", " << y << " )" << endl;
}

// Оператор минус для векторов.
CGeomVectorV2 CGeomVectorV2::operator-( const CGeomVectorV2& other ) const
{
	return CGeomVectorV2( x - other.x, y - other.y );
}

// Оператор плюс для векторов.
CGeomVectorV2 CGeomVectorV2::operator+( const CGeomVectorV2& other ) const
{
	return CGeomVectorV2( x + other.x, y + other.y );
}

// Скалярное произведение.
int CGeomVectorV2::operator*( const CGeomVectorV2& other ) const
{
	return x * other.x + y * other.y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

// main
int main_ClassGeomVectorV2()
{
	// Создаём вектор v1.
	// Поля v1 инициализируются в его конструкторе без параметров.
	CGeomVectorV2 v1;

	// Вызываем метод Print.
	// Внутри этого метода x и y будут интерпретироваться как v1.x, v1.y.
	v1.Print();

	// Используем конструктор с параметрами.
	CGeomVectorV2 v2( 4, 6 );
	v2.Print();

	// Копирование.
	CGeomVectorV2 v3 = CGeomVectorV2( 1, 2 );
	v3.Print();

	// Пример вызова оператора минус.
	v1 = v2 - v3;
	v1.Print();

	// Более сложные вычисления.
	const int x = ( v2 + v3 ) * v1;
	cout << x << endl;

	// Вызов метода временного объекта.
	// Временный объект, возвращаемый из operator+ существует пока вычисляется всё выражение.
	// У этого временного объекта можно вызвать метод Print.
	( v2 + v3 ).Print();

	cin.ignore();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
