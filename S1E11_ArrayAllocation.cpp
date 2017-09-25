// ������������ ��������� ��������.

#include <iostream>

using namespace std;

// ������ � ������� ����������� ����������.
int arrayStatic[10];

// main
int main_ArrayAllocation()
{
	// ������ �� �����.
	int arrayLocal[10];
	arrayLocal[1] = 10;

	// ������ ������ ������� ������� ����������.
	int length = 0;
	cout << "Enter array length: ";
	cin >> length;

	// ��������� ����������� ��������� ��������� ����� �������:
	//   int arrayLocal[length];
	// �� ��-������, ��� ���������� �� �������� � �������� C++, ������� ������������ �� ������.
	// � ��-������, ������ ����� ���������, ������� �� �� ������ ��������� ������� �������.

	// ������ ������ �� ����.
	bool* arrayOnHeap = new bool[length];

	// ���-�� ���������� ������. ��������, ������ ����������.
	// ���������� ����� ������ �������� �����, ������� ��� ����� ����������������.
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

	// � ����� ����� �� ������ ������� ������ � ����.
	// ������ ����� ������� ���������� delete[], � �� ������ delete.
	delete[] arrayOnHeap;

	cin.ignore();
	cin.ignore();
	return 0;
}
