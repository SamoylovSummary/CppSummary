// ������������� �������� �� ������� ������� �� ���������.

#include <iostream>

using namespace std;

// ��������� ��������� ������������� ��������� ����� � ���� ��������� ���.
// ������ ��������� ��������� ������ �� ���������.
// ��� ����� ��������:
//   struct - �������� �����.
//   CGeomVectorV1 - ��� ��������� (�� ���� ��� ����).
//   { - ������ ���� ���������.
//   int x; - ���� ���� int � ������ x.
//   int y; - ���� ���� int � ������ y.
//   } - ����� ���� ���������.
//   ; - � ����� ����������� ��������� ����� �� ������ ��������� ����� � �������.
struct CGeomVectorV1 {
	int x;
	int y;
};

// ���������� ����� �������.
// "const CGeomVectorV1& v" - ����������� ������ �� ������� ����������. ����� ���� ������������
// ��� �����������, ����� �������� ������� ����������� ����������.
double length( const CGeomVectorV1& v )
{
	return sqrt( v.x * v.x + v.y * v.y );
}

// ����� �������.
void print( const CGeomVectorV1& v )
{
	cout << "( " << v.x << ", " << v.y << " )" << endl;
}

// ��������� ��������.
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
	// ������ ������ v1.
	CGeomVectorV1 v1;
	// ���� CGeomVectorV1 ������������������ (�������� �����). ���������.
	v1.x = 4;
	v1.y = 6;
	print( v1 );

	// ��������� ����� ���������������� ���:
	CGeomVectorV1 v2 = { 1, 2 };
	print( v2 );

	// �� ����������� ����� �������� ��� � �������� ������.
	CGeomVectorV1 delta = sub( v1, v2 );
	print( delta );
	cout << length( delta ) << endl;

	// ������ ��������:
	CGeomVectorV1 a[3] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	for( int i = 0; i < 3; i++ ) {
		print( a[i] );
	}

	cin.ignore();
	return 0;
}
