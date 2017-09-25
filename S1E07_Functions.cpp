// �������.

#include <iostream>

using namespace std;

// ���������� �������.
//   int - ��� ���������� �������. ���� ������� ������ �� ����������, �� void.
//   incrementFunction - ��� �������.
//   int x - ��� � ��� ������� ��������� �������.
int incrementFunction( int x )
{
	return x + 1;
}

// ������ ������� � ����� �����������:
int maxFunction( int x, int y )
{
	if( x < y ) {
		return y;
	} else {
		return x;
	}
}

// �������� ��������� �� ��������.
void badIncrement( int x )
{
	// ���� ��������� �� �������� �� ������� ����������, ��� ��� x - ����� ������� ����������.
	x++;
}

// �������� ��������� �� ������.
//   int& - ������ �� ���������� ���� int.
void incrementByReference( int& x )
{
	// ���� ��������� �������� ������� ����������, ��� ��� x - ������.
	x++;
}

// ���������� ����������. �������� ��� ���� �������.
// ����� �� ������������ ���������� ����������, ��� ��� ��� ��������� ������ ����.
int globalVariable = 10;

// �������, �������� ���������� ����������.
void changeGlobalVariable()
{
	globalVariable *= 2;
}

// main
int main_Functions()
{
	int x = 2;
	cout << "x: " << x << endl;

	// ������� �������.

	x = incrementFunction( x );
	cout << "After incrementFunction: " << x << endl;

	x = maxFunction( x, 5 );
	cout << "After maxFunction: " << x << endl;

	badIncrement( x );
	cout << "After badIncrement: " << x << endl;

	incrementByReference( x );
	cout << "After incrementByReference: " << x << endl;

	// ������������� ���������� ����������.

	cout << "globalVariable: " << globalVariable << endl;

	changeGlobalVariable();
	cout << "After changeGlobalVariable: " << globalVariable << endl;

	cin.ignore();
	return 0;
}
