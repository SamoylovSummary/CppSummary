// Простейшие шаблонный класс.

#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

// Шаблонный класс точки на плоскости.
// Координатами могут быть, например, int или double.
template<class T>
class CTemplatePoint {
public:
	T X;
	T Y;

	CTemplatePoint() : X( 0 ), Y( 0 ) {}
	CTemplatePoint( const T& x, const T& y ) : X( x ), Y( y ) {}

	void Div( const T& d );
};

// Пример метода шаблонного класса.
// Делим все координаты на d.
template<class T>
void CTemplatePoint<T>::Div( const T& d )
{
	X /= d;
	Y /= d;
}

// Вывод в поток.
template<class T>
ostream& operator<<( ostream& s, const CTemplatePoint<T>& point )
{
	s << "(" << point.X << ", " << point.Y << ")";
	return s;
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
int main_TemplateClass()
{
	// Пример использования шаблонного класса:
	// Точка с целочисленными координатами.
	CTemplatePoint<int> p1( 3, 10 );
	p1.Div( 2 );
	cout << "p1 = " << p1 << endl; // p1 = (1, 5)

	// Точка с вещественными координатами.
	CTemplatePoint<double> p2( 3, 10 );
	p2.Div( 2 );
	cout << "p2 = " << p2 << endl; // p2 = (1.5, 5)

	// Пример использования шаблонного класса пара.
	CPair<int, string> myPair( 10, "Hello" );
	myPair.Print();

	// std::vector - шаблонный динамический массив.
	// Параметр шаблона - тип, хранящихся в нём объектов.
	vector<int> v;

	system( "Pause" );
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
