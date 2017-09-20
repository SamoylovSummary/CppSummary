// Указатели и массивы.

#include <iostream>

using namespace std;

// main
void main_PointersAsArrays()
{
	int a[5] = { 0, 1, 2, 3, 4 };

	// Массив неявно приводится к указателю на первый элемент массива.
	int* p = a;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;

	// С указателем можно работать как с массивом.
	cout << "p[0] = " << p[0] << endl;
	cout << "p[1] = " << p[1] << endl;
	cout << "p[2] = " << p[2] << endl;

	// Арифметика указателей.
	// К указателю можно прибавлять и вычитать целые числа.
	// Если прибавить к указателю единицу, он будет указывать на следующий элемент в памяти.
	// Обратите внимание, что адрес изменился не на 1, а на 4 (размер int).
	p++;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;

	// Ещё раз.
	p += 2;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;

	// Строки в стиле C - это массив char, заканчивающийся нулём.
	const char* s = "ABC";
	cout << "s = " << s << endl;
	for( int i = 0; i < 4; i++ ) {
		const char c = s[i];
		const int charValue = c;
		cout << "s[" << i << "] = " << c << " = " << charValue << endl;
	}

	cin.ignore();
}
