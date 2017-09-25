// Массивы в стиле C.

#include <iostream>

using namespace std;

// main
int main_BasicArray()
{
	// Массив 10 целых чисел.
	// Массив неинициализирован, в нём сейчас мусор.
	int a[10];

	// Запись в массив.
	a[2] = 10;

	// Чтение из массива.
	cout << "a[2] = " << a[2] << endl;

	// Инициализированный массив.
	int b[10] = { 0, 1, 2, 3, 4, 5 };

	// Хвост дополняется нулями, поэтому чтобы получить массив, заполненый нулями, 
	// можно было написать так:
	// int z[10] = {};

	// Вывод содержимого массива.
	cout << "b:";
	for( int i = 0; i < 10; i++ ) {
		cout << " " << b[i];
	}
	cout << endl;

	// Решето Эратосфена
	cout << "Eratosthenes:";
	const int length = 100;
	bool sieve[length] = {};
	for( int i = 2; i < length; i++ ) {
		if( sieve[i] ) {
			continue;
		}
		cout << " " << i;
		for( int j = i * 2; j < length; j += i ) {
			sieve[j] = true;
		}
	}
	cout << endl;

	cin.ignore();
	return 0;
}
