// Управление исполнением программы.

#include <iostream>

using namespace std;

// main
void main_Execution()
{
	int a = 2;

	// if
	if( a < 10 ) {
		cout << "a < 10" << endl;
	}

	// if-else
	if( a < 10 ) {
		cout << "a < 10" << endl;
	} else {
		cout << "a >= 10" << endl;
	}

	// if-else-if-else
	if( a < 2 ) {
		cout << "a < 2" << endl;
	} else if( a > 2 ) {
		cout << "a > 2" << endl;
	} else {
		cout << "a == 2" << endl;
	}

	// for
	cout << "for:";
	for( int i = 0; i < 10; i++ ) {
		cout << " " << i;
	}
	cout << endl;

	// while
	cout << "Fibonacci:";
	int b1 = 1;
	int b2 = 1;
	while( b1 < 100 ) {
		cout << " " << b1;
		const int next = b1 + b2;
		b1 = b2;
		b2 = next;
	}
	cout << endl;

	// do-while
	cout << "do-while:";
	int i = 0;
	do {
		cout << " " << i;
		i++;
	} while( i < 10 ); 
	cout << endl;

	// break, continue
	cout << "break, continue:";
	for( int i = 0; i < 10; i++ ) {
		cout << " " << i;
		if( i < 4 ) {
			continue;
		}
		cout << "*";
		if( i == 7 ) {
			break;
		}
	}
	cout << endl;

	// Ещё есть switch, но обычно он не очень нужен.
	a = 1;
	switch( a ) {
		case 0:
			cout << "a == 0" << endl;
			break;
		case 1:
			cout << "a == 1" << endl;
			break;
		case 2:
			cout << "a == 2" << endl;
			break;
		default:
			cout << "other" << endl;
			break;
	}

	// Пример цикла в цикле:
	for( int i = 0; i < 10; i++ ) {
		for( int j = 0; j < i; j++ ) {
			cout << "*";
		}
		cout << endl;
	}

	cin.ignore();
}
