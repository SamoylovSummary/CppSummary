// Простейшие шаблонные функции.

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

// Пример оператора >, который вызывает оператор <
bool operator>( const CPoint& point1, const CPoint& point2 )
{
	return point2 < point1;
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

template<class T>
void bubbleSort( T* a, int n )
{
	for( int i = 1; i < n; i++ ) {
		for( int j = 0; j < n - i; j++ ) {
			if( a[j] > a[j + 1] ) {
				const T tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

// main
int main_TemplateFunction()
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

	// Пример шаблонной сортировки.
	const int length = 4;
	CPoint points[length] = { { 2, 5 }, { 3, 2}, { 1, 11 }, { 1, 10 } };
	bubbleSort( points, length );

	cout << "bubbleSort result:" << endl;
	for( int i = 0; i < length; i++ ) {
		cout << points[i] << endl;
	}

	system( "Pause" );
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
