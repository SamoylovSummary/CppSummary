// ������� ����.

#include <iostream>

using namespace std;

// main
int main_BasicTypes()
{
	// ���������������:
	int a = 10;        // 4 �����
	bool b = true;     // 1 ����
	char c = 'A';      // 1 ����
	double d = -1.5;    // 8 ����

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	// ����� ���������������:
	short s = -5;      // 2 �����
	long l = 20;       // 4 �����
	long long ll = 40; // 8 ����
	__int64 i64 = 100; // 8 ����
	wchar_t w = L'B';  // 2 ��� 4 �����
	float f = 3.2f;    // 4 �����

	cout << "s = " << s << endl;
	cout << "l = " << l << endl;
	cout << "ll = " << ll << endl;
	cout << "i64 = " << i64 << endl;
	cout << "w = " << w << endl;
	cout << "f = " << f << endl;

	// ����������� �������� �����:
	unsigned short us = -1;
	unsigned int ui = -1;
	unsigned long ul = -1;
	unsigned __int64 ui64 = -1;

	cout << "us = " << us << endl;
	cout << "ui = " << ui << endl;
	cout << "ul = " << ul << endl;
	cout << "ui64 = " << ui64 << endl;

	// ���������:
	const int ci = 20;
	// ������ ����������:
	// ci = 10;

	cin.ignore();
	return 0;
}
