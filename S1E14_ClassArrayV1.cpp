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

	// ���������� �������� � ������.
	// � ����� ������� ����������� count ����� element. ������ ������� ������������� �� count.
	// ���� ����� ����� ������� ���������������.
	void Add( int element, int count = 1 );

	// ������� count ��������� ������� � ������� pos.
	void DeleteAt( int pos, int count = 1 );

	// ������ � �������� ������� �� �������.
	int& GetAt( int index );

	// ������ � �������� ������� �� �������.
	int& operator[]( int index ) { return GetAt( index ); }

	// ������ ����� ������ �������.
	// � ������ ����������� ����������� ������������� �������.
	// ���������, ���� ����� ������ ������ �������, ����� ����������� ���������� ����������.
	// ��� ���������� ������� ������ ����� ������������ Add( 0, count ).
	void SetSize( int newSize );

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
	// ������ ������ (���� size �� ������ ��������� bufferSize).
	int bufferSize;
	// ���������� ��������� � �������.
	int size;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

CArrayV1::CArrayV1() :
	buffer( 0 ),
	bufferSize( 0 ),
	size( 0 )
{
}

CArrayV1::~CArrayV1()
{
	if( buffer != nullptr ) {
		delete[] buffer;
	}
}

void CArrayV1::Add( int element, int count )
{
	assert( count >= 0 );

	// ���� ����, ��������� �����.
	const int oldSize = size;
	SetSize( size + count );

	// ���������� element � �����.
	for( int i = 0; i < count; i++ ) {
		buffer[oldSize + i] = element;
	}
}

void CArrayV1::DeleteAt( int pos, int count )
{
	assert( pos >= 0 );
	assert( count >= 0 );
	assert( pos + count <= size );
	assert( buffer != nullptr );

	// ���������� ���������� ������ �������� ������ �� count ������� �����.
	// ��� ������� ����� ����������� ������������ �� ����, � ������� memcpy.
	for( int i = pos + count; i < pos; i++ ) {
		buffer[pos - count] = buffer[pos];
	}
	size = pos - count;
}

int& CArrayV1::GetAt( int index )
{
	assert( index >= 0 );
	assert( index < size );
	assert( buffer != nullptr );
	return buffer[index];
}

void CArrayV1::SetSize( int newSize )
{
	assert( newSize >= 0 );

	// � ������ ���������� ����� ��� newSize.
	// ��������� ������ �����, ������ ������ size.
	if( newSize <= bufferSize ) {
		size = newSize;
		return;
	}

	// ������ ������� �������.
	if( newSize == 0 ) {
		delete[] buffer;
		bufferSize = 0;
		size = 0;
		return;
	}

	// �������� ����� � �������.
	const int newBufferSize = newSize * 2;
	int* newBuffer = new int[newBufferSize];

	// �������� ���������� ������� ������ � ����� �����.
	for( int i = 0; i < size; i++ ) {
		newBuffer[i] = buffer[i];
	}
	delete[] buffer;

	// ������������� �� ����� �����.
	buffer = newBuffer;
	bufferSize = newBufferSize;
	size = newSize;
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

// main
int main_ClassArrayV1()
{
	CArrayV1 a;
	a.Add( 0 );
	a.Add( 1 );
	a.Add( 2 );
	a.Add( 3, 5 );
	a.DeleteAt( 2 );
	a.SetSize( 7 );

	// ������������� CArrayV1::operator[]
	a[5] = 10;

	// ������������� CArrayV1::operator<<
	a << 20 << 21 << 23;

	for( int i = 0; i < a.Size(); i++ ) {
		cout << a[i] << " ";
	}

	cin.ignore();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
