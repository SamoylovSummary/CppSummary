// ����� ������� ���������� ������� �� ������� ������������� �������.

#include <iostream>
#include <assert.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

// ����� ������� ���������� ������� �� ������� ������������� �������.
// � ���������� ���� ����� ����� �����������, ������� � ������� ������ V1 (������ ������) � ����� ������.
class CArrayV1 {
public:
	// ����������� �� ���������.
	CArrayV1();
	~CArrayV1();

	// ������ �������
	int Size() const { return size; }

	// ���������� �������� � ����� �������.
	void Add( int element );

	// ������� count ��������� ������� � ������� pos.
	void DeleteAt( int pos );

	// ������� ��� �������� �������.
	void DeleteAll();

	// ������ � �������� ������� �� �������.
	int& GetAt( int index );

	// ������ � �������� ������� �� �������.
	int& operator[]( int index ) { return GetAt( index ); }

	// ��� ����������� ������� ���������� �������� � ����� ������� � ����� std::cout <<
	// �������� ���������� CArrayV1& (������ �� ����), ����� ����� ���� ������ ���:
	//   a << 1 << 2 << 3;
	// ��� a - ������.
	// ����� ��������� ������������ ���������
	//   ( ( a << 1 ) << 2 ) << 3;
	CArrayV1& operator<<( int element );

private:
	// ����� �� ����.
	int* buffer;
	// ������ ������ (���� size �� ������ ��������� capacity).
	int capacity;
	// ���������� ��������� � �������.
	int size;

	void grow();
};

////////////////////////////////////////////////////////////////////////////////////////////////////

CArrayV1::CArrayV1() :
	buffer( 0 ),
	capacity( 0 ),
	size( 0 )
{
}

CArrayV1::~CArrayV1()
{
	delete[] buffer;
}

void CArrayV1::Add( int element )
{
	// ���� ����, ��������� �����.
	if( size + 1 > capacity ) {
		grow();
	}

	// ���������� element � �����.
	assert( size < capacity );
	buffer[size] = element;
	size++;
}

void CArrayV1::DeleteAt( int pos )
{
	assert( pos >= 0 );
	assert( buffer != nullptr );

	// ���������� ���������� ������ �������� ������ �� count ������� �����.
	// ��� ������� ����� ����������� ������������ �� ����, � ������� memcpy.
	for( int i = pos + 1; i < size; i++ ) {
		buffer[i - 1] = buffer[i];
	}
	size--;
}

// ������� ��� �������� �������.
void CArrayV1::DeleteAll()
{
	delete[] buffer;
	buffer = 0;
	capacity = 0;
	size = 0;
}

// ������ � �������� ������� �� �������.
int& CArrayV1::GetAt( int index )
{
	assert( index >= 0 );
	assert( index < size );
	assert( buffer != nullptr );

	return buffer[index];
}

// ����������� ������ ������.
void CArrayV1::grow()
{
	// �������� ����� � �������.
	const int newCapacity = ( size == 0 ) ? 8 : size * 2;
	int* newBuffer = new int[newCapacity];

	// �������� ���������� ������� ������ � ����� �����.
	for( int i = 0; i < size; i++ ) {
		newBuffer[i] = buffer[i];
	}
	delete[] buffer;

	// ������������� �� ����� �����.
	buffer = newBuffer;
	capacity = newCapacity;
}

// ��� ����������� ������� ���������� �������� � ����� ������� � ����� std::cout <<
// �������� ���������� CArrayV1& (������ �� ����), ����� ����� ���� ������ ���:
//   a << 1 << 2 << 3;
// ��� a - ������.
// ����� ��������� ������������ ���������
//   ( ( a << 1 ) << 2 ) << 3;
CArrayV1& CArrayV1::operator<<( int element )
{
	Add( element );
	// ���������� ������ �� ����.
	// this - �������� �����, ������������ ��������� �� ������, ��� �������� ������ �����.
	// ������ � �� ��� �������������, ��� ��� ����� ������ �� ���:
	//   this->buffer
	// � ������:
	//   buffer
	// �� ������, ��� �������� �����, ��������� ������������� ������������ this.
	return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int main_ClassArrayV1()
{
	CArrayV1 a;

	for( int i = 0; i < 10; i++ ) {
		a.Add( i );
	}

	a.DeleteAt( 2 );

	// ������������� CArrayV1::operator[]
	a[5] = 100;

	// ������������� CArrayV1::operator<<
	a << 20 << 21 << 23;

	for( int i = 0; i < a.Size(); i++ ) {
		cout << a[i] << " ";
	}

	cin.ignore();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
