// Простейшие шаблоны.

#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

// Точка на плоскости.
class CPoint {
public:
	int X;
	int Y;

	CPoint() : X( 0 ), Y( 0 ) {}
	CPoint( int x, int y ) : X( x ), Y( y ) {}
};

// Определяем оператор <<, чтобы можно было писать так:
// cout << myPoint;
ostream& operator<<( ostream& s, const CPoint& point )
{
	s << "(" << point.X << ", " << point.Y << ")";
	return s;
}

// Пример оператора <
bool operator<( const CPoint& point1, const CPoint& point2 )
{
	if( point1.X != point2.X ) {
		return point1.X < point2.X;
	}
	return point1.Y < point2.Y;
}

// Наша альтернатива шаблонной функции max.
template<class T>
const T& myMax( const T& first, const T& second )
{
	if( first < second ) {
		return second;
	} else {
		return first;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

// Шаблонный класс пара.
template<class T1, class T2>
class CPair {
public:
	// Первый элемент пары.
	T1 First;
	// Второй элемент пары.
	T2 Second;

	CPair( const T1& first, const T2& second ) : First( first ), Second( second ) {}

	void Print() const;
};

// Пример метода шаблонного класса.
template<class T1, class T2>
void CPair<T1, T2>::Print() const
{
	cout << "Pair[" << First << ", " << Second << "]" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

// main
int main_Templates()
{
	// Примеры способов конструирования объектов.
	CPoint a( 1, 2 );
	CPoint b = CPoint( 3, 4 );
	CPoint c;

	// Здесь используется наш operator<< для CPoint.
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	// Вызов шаблонной функции max (определена в #include <algorithm>)
	CPoint m = max( a, b );
	cout << "m = " << m << endl;

	// Можно так (теперь для min):
	cout << "min( a, b ) = " << min( a, b ) << endl;

	// swap это тоже стандартная шаблонная функция:
	swap( a, b );
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// Вызов нашей шаблонной функции myMax.
	// Для CPoint:
	cout << "myMax( a, b ) = " << myMax( a, b ) << endl;
	// Для int:
	cout << "myMax( 10, 20 ) = " << myMax( 10, 20 ) << endl;

	// Пример использования шаблонного класса:
	CPair<CPoint, int> myPair( CPoint( 5, 6 ), 10 );
	myPair.Print();

	// std::vector - шаблонный динамический массив.
	// Параметр шаблона - тип, хранящихся в нём объектов.
	vector<CPoint> v;
	v.push_back( CPoint( 11, 12 ) );
	v.push_back( CPoint( 13, 14 ) );
	v.push_back( CPoint( 15, 16 ) );
	for( size_t i = 0; i < v.size(); i++ ) {
		cout << v[i] << endl;
	}

	system( "Pause" );
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
