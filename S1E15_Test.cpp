// �������� ����� ������.

#include <iostream>
#include <assert.h>

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
	// ��� ������������ ����� ������� ������� �������� ������� ������ �� ����� �������, � �� �����.
	// ��� ����� ����� ���� �� ����� �������� std::cin/std::cout �� ������ �� ������. �� ����� 
	// ������� ����� - ������������ freopen.

	// ���������� ���������� ����� Input.txt � ����������� ����� �����.
	// ������ ���������� Input.txt ����� �������� ����� std::cin.
	freopen( "Input.txt", "r", stdin );

	// �������������� ����������� ����� ������ � ���� Output.txt.
	// ������ ���������� Output.txt ����� �������� ����� std::cout.
	freopen( "Output.txt", "w", stdout );

	// ������ ������ �� Input.txt.
	int length = 0;
	cin >> length;
	assert( length >= 0 );
	int* a = new int[length];
	for( int i = 0; i < length; i++ ) {
		cin >> a[i];
	}

	// ���-�� ������ � ��������.
	const int mid = length / 2;
	for( int i = 0; i < mid; i++ ) {
		swap( a[i], a[length - 1 - i] );
	}

	// ������� ������ � Output.txt.
	for( int i = 0; i < length; i++ ) {
		cout << a[i] << " ";
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
