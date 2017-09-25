// ������� � ����� C.

#include <iostream>

using namespace std;

// main
int main_BasicArray()
{
	// ������ 10 ����� �����.
	// ������ �����������������, � �� ������ �����.
	int a[10];

	// ������ � ������.
	a[2] = 10;

	// ������ �� �������.
	cout << "a[2] = " << a[2] << endl;

	// ������������������ ������.
	int b[10] = { 0, 1, 2, 3, 4, 5 };

	// ����� ����������� ������, ������� ����� �������� ������, ���������� ������, 
	// ����� ���� �������� ���:
	// int z[10] = {};

	// ����� ����������� �������.
	cout << "b:";
	for( int i = 0; i < 10; i++ ) {
		cout << " " << b[i];
	}
	cout << endl;

	// ������ ����������
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
