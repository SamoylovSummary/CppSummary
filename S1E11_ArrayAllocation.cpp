// Динамическая аллокация массивов.

#include <iostream>

using namespace std;

// Массив в области статических переменных.
int arrayStatic[10];

// main
int main_ArrayAllocation()
{
	// Массив на стеке.
	int arrayLocal[10];
	arrayLocal[1] = 10;

	// Обычно размер массива заранее неизвестен.
	int length = 0;
	cout << "Enter array length: ";
	cin >> length;

	// Некоторые компиляторы позволяют создавать такие массивы:
	//   int arrayLocal[length];
	// Но во-первых, это расширение не включено в стандарт C++, поэтому пользоваться им нельзя.
	// А во-вторых, размер стека ограничен, поэтому на нём нельзя создавать большие массивы.

	// Создаём массив на куче.
	bool* arrayOnHeap = new bool[length];

	// Как-то используем массив. Например, решето Эратосфена.
	// Изначально такой массив содержит мусор, поэтому его нужно инициализировать.
	for( int i = 0; i < length; i++ ) {
		arrayOnHeap[i] = false;
	}
	cout << "Eratosthenes:";
	for( int i = 2; i < length; i++ ) {
		if( arrayOnHeap[i] ) {
			continue;
		}
		cout << " " << i;
		for( int j = i * 2; j < length; j += i ) {
			arrayOnHeap[j] = true;
		}
	}
	cout << endl;

	// В конце нужно не забыть вернуть память в кучу.
	// Массив нужно удалять оператором delete[], а не просто delete.
	delete[] arrayOnHeap;

	cin.ignore();
	cin.ignore();
	return 0;
}
