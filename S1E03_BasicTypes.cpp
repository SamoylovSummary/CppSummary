// Базовые типы.

#include <iostream>

using namespace std;

// main
int main_BasicTypes()
{
	// Распространённые:
	int a = 10;        // 4 байта
	bool b = true;     // 1 байт
	char c = 'A';      // 1 байт
	double d = -1.5;    // 8 байт

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	// Менее распространённые:
	short s = -5;      // 2 байта
	long l = 20;       // 4 байта
	long long ll = 40; // 8 байт
	__int64 i64 = 100; // 8 байт
	wchar_t w = L'B';  // 2 или 4 байта
	float f = 3.2f;    // 4 байта

	cout << "s = " << s << endl;
	cout << "l = " << l << endl;
	cout << "ll = " << ll << endl;
	cout << "i64 = " << i64 << endl;
	cout << "w = " << w << endl;
	cout << "f = " << f << endl;

	// Беззнаковые варианты типов:
	unsigned short us = -1;
	unsigned int ui = -1;
	unsigned long ul = -1;
	unsigned __int64 ui64 = -1;

	cout << "us = " << us << endl;
	cout << "ui = " << ui << endl;
	cout << "ul = " << ul << endl;
	cout << "ui64 = " << ui64 << endl;

	// Константы:
	const int ci = 20;
	// Ошибка компиляции:
	// ci = 10;

	cin.ignore();
	return 0;
}
