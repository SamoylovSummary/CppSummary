// Создание своих тестов.

#include <iostream>
#include <cassert>
#include <time.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

inline void swap( int& x, int& y )
{
	const int temp = x;
	x = y;
	y = temp;
}

// main
int main_Test()
{
	// При тестировании своих решений удобней получать входные данные не через консоль, а из файла.
	// Для этого можно было бы везде заменить std::cin/std::cout на потоки из файлов. Но можно 
	// сделать проще - использовать freopen.

	// Направляем содержимое файла Input.txt в стандартный поток ввода.
	// Теперь содержимое Input.txt будет доступно через std::cin.
	freopen( "Input.txt", "r", stdin );

	// Перенаправляем стандартный поток вывода в файл Output.txt.
	// Теперь содержимое Output.txt будет доступно через std::cout.
	freopen( "Output.txt", "w", stdout );

	// Запоминаем момент старта.
	const clock_t start = clock();

	// Читаем массив из Input.txt.
	int length = 0;
	cin >> length;
	assert( length >= 0 );
	int* a = new int[length];
	for( int i = 0; i < length; i++ ) {
		cin >> a[i];
	}

	// Что-то делаем с массивом.
	const int mid = length / 2;
	for( int i = 0; i < mid; i++ ) {
		swap( a[i], a[length - 1 - i] );
	}

	// Выводим массив в Output.txt.
	for( int i = 0; i < length; i++ ) {
		cout << a[i] << " ";
	}

	// Выводим время в миллисекундах.
	const double time = ( clock() - start ) * 1000. / CLOCKS_PER_SEC;
	cout << endl << "Total time: " << time << " ms" << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
