// ���������.

#include <iostream>

using namespace std;

// main
void main_Operators()
{
	// ������������� ����������:
	const int a = 5;
	const int b = 2;
	cout << "a       " << a << endl;
	cout << "b       " << b << endl;
	cout << "-b      " << -b << endl;
	cout << "a + b   " << ( a + b ) << endl;
	cout << "a - b   " << ( a - b ) << endl;
	cout << "a * b   " << ( a * b ) << endl;
	cout << "a / b   " << ( a / b ) << endl; // ������������� �������
	cout << "a % b   " << ( a % b ) << endl; // ������ �������
	cout << endl;

	// ������� ����� � ��������� �������:
	const double x = 5;
	const double y = 2;
	cout << "x       " << x << endl;
	cout << "y       " << y << endl;
	cout << "x / y   " << ( x / y ) << endl;
	cout << endl;

	// ���������:
	cout << "a == b  " << ( a == b ) << endl;
	cout << "a != b  " << ( a != b ) << endl;
	cout << "a < b   " << ( a < b ) << endl;
	cout << "a > b   " << ( a > b ) << endl;
	cout << "a <= b  " << ( a <= b ) << endl;
	cout << "a >= b  " << ( a >= b ) << endl;
	cout << endl;

	// ���������� ��������:
	const bool t = ( a > b ); // = true
	const bool f = ( a == b ); // = false
	cout << "t       " << t << endl;
	cout << "f       " << f << endl;
	cout << "t && f  " << ( t && f ) << endl; // ���������� �
	cout << "t || f  " << ( t || f ) << endl; // ���������� ���
	cout << "!t      " << !t << endl; // ���������� ��
	cout << endl;

	// ��������� �������� (������ �� �����):
	cout << "a | b   " << ( a | b ) << endl; // ��������� ���
	cout << "a & b   " << ( a & b ) << endl; // ��������� �
	cout << "a ^ b   " << ( a ^ b ) << endl; // ��������� ����������� ���
	cout << "~a      " << ~a  << endl; // ��������� ��
	cout << "a << b  " << ( a << b ) << endl; // ����� �����
	cout << "a >> b  " << ( a >> b ) << endl; // ����� ������
	cout << endl;

	// ��������� �������� �������� (������ �� �����):
	cout << "a < b ? a : b    " << ( a < b ? a : b ) << endl;
	cout << "a > b ? a : b    " << ( a > b ? a : b ) << endl;

	// ��������� ������������:
	int c = 5;
	c++; // c = c + 1;
	++c; // c = c + 1;
	c--; // c = c - 1;
	--c; // c = c - 1;
	c += 5; // c = c + 5;
	c /= 2; // c = c / 2;
	// ...

	cin.ignore();
}
