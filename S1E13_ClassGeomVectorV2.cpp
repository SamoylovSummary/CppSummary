// ������� ����� �� ������� ������� �� ���������.

#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

// ��������� ������ �� ��������� (��. CGeomVectorV1) � ����������� �������.
class CGeomVectorV2 {
public:
	// ��������� ������. ���� (������ � ������), ����������� � ���� ������, �������� ������� 
	// ������������� ������.

	// ��� ���� ���� int.
	int x;
	int y;

	// ����������� �� ���������.
	CGeomVectorV2();

	// ����������� � �����������.
	CGeomVectorV2( int x, int y );

	// ���������� ����� �������.
	// const � ����� ��������, ��� ����� �� ����� ������ ������. �� ���� ����� ������ ������ ���� x � y.
	double CalculateLength() const;

	// ����� ������� � cout.
	void Print() const;

	// �������� ����� ��� ��������.
	CGeomVectorV2 operator-( const CGeomVectorV2& other ) const;

	// �������� ���� ��� ��������.
	CGeomVectorV2 operator+( const CGeomVectorV2& other ) const;

	// �������� �������� ���������� ��� ���������� ���������� ������������.
	int operator*( const CGeomVectorV2& other ) const;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

// ����������� �� ���������.
CGeomVectorV2::CGeomVectorV2()
{
	x = 0;
	y = 0;
}

// ����������� � �����������.
CGeomVectorV2::CGeomVectorV2( int _x, int _y )
{
	x = _x;
	y = _y;
}

// ���������� ����� �������.
double CGeomVectorV2::CalculateLength() const
{
	return sqrt( x * x + y * y );
}

// ����� ������� � cout.
void CGeomVectorV2::Print() const
{
	cout << "( " << x << ", " << y << " )" << endl;
}

// �������� ����� ��� ��������.
CGeomVectorV2 CGeomVectorV2::operator-( const CGeomVectorV2& other ) const
{
	return CGeomVectorV2( x - other.x, y - other.y );
}

// �������� ���� ��� ��������.
CGeomVectorV2 CGeomVectorV2::operator+( const CGeomVectorV2& other ) const
{
	return CGeomVectorV2( x + other.x, y + other.y );
}

// ��������� ������������.
int CGeomVectorV2::operator*( const CGeomVectorV2& other ) const
{
	return x * other.x + y * other.y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

// main
int main_ClassGeomVectorV2()
{
	// ������ ������ v1.
	// ���� v1 ���������������� � ��� ������������ ��� ����������.
	CGeomVectorV2 v1;

	// �������� ����� Print.
	// ������ ����� ������ x � y ����� ������������������ ��� v1.x, v1.y.
	v1.Print();

	// ���������� ����������� � �����������.
	CGeomVectorV2 v2( 4, 6 );
	v2.Print();

	// �����������.
	CGeomVectorV2 v3 = CGeomVectorV2( 1, 2 );
	v3.Print();

	// ������ ������ ��������� �����.
	v1 = v2 - v3;
	v1.Print();

	// ����� ������� ����������.
	const int x = ( v2 + v3 ) * v1;
	cout << x << endl;

	// ����� ������ ���������� �������.
	// ��������� ������, ������������ �� operator+ ���������� ���� ����������� �� ���������.
	// � ����� ���������� ������� ����� ������� ����� Print.
	( v2 + v3 ).Print();

	cin.ignore();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
