// Функции.

#include <iostream>

using namespace std;

// Простейщая функция.
//   int - тип результата функции. Если функция ничего не возвращает, то void.
//   incrementFunction - имя функции.
//   int x - тип и имя первого аргумента функции.
int incrementFunction( int x )
{
	return x + 1;
}

// Пример функции с двумя аргументами:
int maxFunction( int x, int y )
{
	if( x < y ) {
		return y;
	} else {
		return x;
	}
}

// Передача аргумента по значению.
void badIncrement( int x )
{
	// Этот инкремент не повлияет на внешнюю переменную, так как x - копия внешней переменной.
	x++;
}

// Передача аргумента по ссылке.
//   int& - ссылка на переменную типа int.
void incrementByReference( int& x )
{
	// Этот инкремент изменяет внешнюю переменную, так как x - ссылка.
	x++;
}

// Глобальная переменная. Доступна для всех функций.
// Лучше не использовать глобальные переменные, так как они усложняют чтение кода.
int globalVariable = 10;

// Функция, меняющая глобальную переменную.
void changeGlobalVariable()
{
	globalVariable *= 2;
}

// main
int main_Functions()
{
	int x = 2;
	cout << "x: " << x << endl;

	// Примеры функций.

	x = incrementFunction( x );
	cout << "After incrementFunction: " << x << endl;

	x = maxFunction( x, 5 );
	cout << "After maxFunction: " << x << endl;

	badIncrement( x );
	cout << "After badIncrement: " << x << endl;

	incrementByReference( x );
	cout << "After incrementByReference: " << x << endl;

	// Использование глобальных переменных.

	cout << "globalVariable: " << globalVariable << endl;

	changeGlobalVariable();
	cout << "After changeGlobalVariable: " << globalVariable << endl;

	cin.ignore();
	return 0;
}
