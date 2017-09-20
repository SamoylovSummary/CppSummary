// ��������� � �������.

#include <iostream>

using namespace std;

// main
void main_PointersAsArrays()
{
	int a[5] = { 0, 1, 2, 3, 4 };

	// ������ ������ ���������� � ��������� �� ������ ������� �������.
	int* p = a;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;

	// � ���������� ����� �������� ��� � ��������.
	cout << "p[0] = " << p[0] << endl;
	cout << "p[1] = " << p[1] << endl;
	cout << "p[2] = " << p[2] << endl;

	// ���������� ����������.
	// � ��������� ����� ���������� � �������� ����� �����.
	// ���� ��������� � ��������� �������, �� ����� ��������� �� ��������� ������� � ������.
	// �������� ��������, ��� ����� ��������� �� �� 1, � �� 4 (������ int).
	p++;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;

	// ��� ���.
	p += 2;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;

	// ������ � ����� C - ��� ������ char, ��������������� ����.
	const char* s = "ABC";
	cout << "s = " << s << endl;
	for( int i = 0; i < 4; i++ ) {
		const char c = s[i];
		const int charValue = c;
		cout << "s[" << i << "] = " << c << " = " << charValue << endl;
	}

	cin.ignore();
}
