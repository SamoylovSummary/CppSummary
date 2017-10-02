// Операторы.

#include <iostream>

using namespace std;

// main
int main_Operators()
{
	// Целочисленная арифметика:
	const int a = 5;
	const int b = 2;
	cout << "a       " << a << endl;
	cout << "b       " << b << endl;
	cout << "-b      " << -b << endl;
	cout << "a + b   " << ( a + b ) << endl;
	cout << "a - b   " << ( a - b ) << endl;
	cout << "a * b   " << ( a * b ) << endl;
	cout << "a / b   " << ( a / b ) << endl; // Целочисленное деление
	cout << "a % b   " << ( a % b ) << endl; // Взятие остатка
	cout << endl;

	// Деление чисел с плавающей запятой:
	const double x = 5;
	const double y = 2;
	cout << "x       " << x << endl;
	cout << "y       " << y << endl;
	cout << "x / y   " << ( x / y ) << endl;
	cout << endl;

	// Сравнение:
	cout << "a == b  " << ( a == b ) << endl;
	cout << "a != b  " << ( a != b ) << endl;
	cout << "a < b   " << ( a < b ) << endl;
	cout << "a > b   " << ( a > b ) << endl;
	cout << "a <= b  " << ( a <= b ) << endl;
	cout << "a >= b  " << ( a >= b ) << endl;
	cout << endl;

	// Логические операции:
	const bool t = ( a > b ); // = true
	const bool f = ( a == b ); // = false
	cout << "t       " << t << endl;
	cout << "f       " << f << endl;
	cout << "t && f  " << ( t && f ) << endl; // Логическое и
	cout << "t || f  " << ( t || f ) << endl; // Логическое или
	cout << "!t      " << !t << endl; // Логическое не
	cout << endl;

	// Побитовые операции (обычно не нужны):
	cout << "a | b   " << ( a | b ) << endl; // Побитовое или
	cout << "a & b   " << ( a & b ) << endl; // Побитовое и
	cout << "a ^ b   " << ( a ^ b ) << endl; // Побитовое исключающее или
	cout << "~a      " << ~a  << endl; // Побитовое не
	cout << "a << b  " << ( a << b ) << endl; // Сдвиг влево
	cout << "a >> b  " << ( a >> b ) << endl; // Сдвиг вправо
	cout << endl;

	// Тернарная условная операция (обычно не нужна):
	cout << "a < b ? a : b    " << ( a < b ? a : b ) << endl;
	cout << "a > b ? a : b    " << ( a > b ? a : b ) << endl;

	// Составное присваивание:
	int c = 5;
	c++; // c = c + 1;
	++c; // c = c + 1;
	c--; // c = c - 1;
	--c; // c = c - 1;
	c += 5; // c = c + 5;
	c /= 2; // c = c / 2;
	// ...

	cin.ignore();
	return 0;
}
