// ���������� ��������� �����.

#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

// ��������� ����� ����� �� ���������.
// ������������ ����� ����, ��������, int ��� double.
template<class T>
class CTemplatePoint {
public:
	T X;
	T Y;

	CTemplatePoint() : X( 0 ), Y( 0 ) {}
	CTemplatePoint( const T& x, const T& y ) : X( x ), Y( y ) {}

	void Div( const T& d );
};

// ������ ������ ���������� ������.
// ����� ��� ���������� �� d.
template<class T>
void CTemplatePoint<T>::Div( const T& d )
{
	X /= d;
	Y /= d;
}

// ����� � �����.
template<class T>
ostream& operator<<( ostream& s, const CTemplatePoint<T>& point )
{
	s << "(" << point.X << ", " << point.Y << ")";
	return s;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

// ��������� ����� ����.
template<class T1, class T2>
class CPair {
public:
	// ������ ������� ����.
	T1 First;
	// ������ ������� ����.
	T2 Second;

	CPair( const T1& first, const T2& second ) : First( first ), Second( second ) {}

	void Print() const;
};

// ������ ������ ���������� ������.
template<class T1, class T2>
void CPair<T1, T2>::Print() const
{
	cout << "Pair[" << First << ", " << Second << "]" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

// main
int main_TemplateClass()
{
	// ������ ������������� ���������� ������:
	// ����� � �������������� ������������.
	CTemplatePoint<int> p1( 3, 10 );
	p1.Div( 2 );
	cout << "p1 = " << p1 << endl; // p1 = (1, 5)

	// ����� � ������������� ������������.
	CTemplatePoint<double> p2( 3, 10 );
	p2.Div( 2 );
	cout << "p2 = " << p2 << endl; // p2 = (1.5, 5)

	// ������ ������������� ���������� ������ ����.
	CPair<int, string> myPair( 10, "Hello" );
	myPair.Print();

	// std::vector - ��������� ������������ ������.
	// �������� ������� - ���, ���������� � �� ��������.
	vector<int> v;

	system( "Pause" );
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
