// Более сложное применение классов на примере динамического массива.

#include <iostream>
#include <assert.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

// Более сложное применение классов на примере динамического массива.
// В дальнейшем этот класс будет развиваться, поэтому я добавил суфикс V1 (первая версия) к имени класса.
class CArrayV1 {
public:
	// Конструктор по умолчанию.
	CArrayV1();
	~CArrayV1();

	// Размер массива
	int Size() const { return size; }

	// Добавление элемента в массив.
	// В конец массива добавляется count копий element. Размер массива увеличивается на count.
	// Если нужно буфер массива переалокируется.
	void Add( int element, int count = 1 );

	// Удалить count элементов начиная с позиции pos.
	void DeleteAt( int pos, int count = 1 );

	// Доступ к элементу массива по индексу.
	int& GetAt( int index );

	// Доступ к элементу массива по индексу.
	int& operator[]( int index ) { return GetAt( index ); }

	// Задать новый размер массива.
	// В методе выполняется необходимая переаллокация буффера.
	// Осторожно, если новый размер больше старого, хвост заполняется случайными значениями.
	// Для заполнения массива нулями нужно использовать Add( 0, count ).
	void SetSize( int newSize );

	// Для развлечения сделаем добавление элемента в конец массива в стиле std::cout <<
	// Оператор возвращает CArrayV1& (ссылку на себя), чтобы можно было писать так:
	//   a << 1 << 2 << 3;
	// Где a - массив.
	// Такое выражение эквивалентно выражению
	//   ( ( a << 1 ) << 2 ) << 3;
	CArrayV1& operator<<( int element );

private:
	// Буфер на куче.
	int* buffer;
	// Размер буфера (поле size не должно превышать bufferSize).
	int bufferSize;
	// Количество элементов в массиве.
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

	// Если надо, расширяем буфер.
	const int oldSize = size;
	SetSize( size + count );

	// Записываем element в буфер.
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

	// Перемещаем содержимое парвой половины буфера на count позиций влево.
	// Для простых типов эффективней использовать не цикл, а функцию memcpy.
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

	// В буфере достаточно места для newSize.
	// Оставляем старый буфер, просто меняем size.
	if( newSize <= bufferSize ) {
		size = newSize;
		return;
	}

	// Полная очистка массива.
	if( newSize == 0 ) {
		delete[] buffer;
		bufferSize = 0;
		size = 0;
		return;
	}

	// Выделяем буфер с запасом.
	const int newBufferSize = newSize * 2;
	int* newBuffer = new int[newBufferSize];

	// Копируем содержимое старого буфера в новый буфер.
	for( int i = 0; i < size; i++ ) {
		newBuffer[i] = buffer[i];
	}
	delete[] buffer;

	// Переключаемся на новый буфер.
	buffer = newBuffer;
	bufferSize = newBufferSize;
	size = newSize;
}

// Для развлечения сделаем добавление элемента в конец массива в стиле std::cout <<
// Оператор возвращает CArrayV1& (ссылку на себя), чтобы можно было писать так:
//   a << 1 << 2 << 3;
// Где a - массив.
// Такое выражение эквивалентно выражению
//   ( ( a << 1 ) << 2 ) << 3;
CArrayV1& CArrayV1::operator<<( int element )
{
	Add( element );
	// Возвращаем ссылку на себя.
	// this - ключевое слово, обозначающее указатель на объект, для которого вызван метод.
	// Обычно в нём нет необходимости, так как проще писать не так:
	//   this->buffer
	// А просто:
	//   buffer
	// Но иногда, как например здесь, возникает необходимость использовать this.
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

	// Использование CArrayV1::operator[]
	a[5] = 10;

	// Использование CArrayV1::operator<<
	a << 20 << 21 << 23;

	for( int i = 0; i < a.Size(); i++ ) {
		cout << a[i] << " ";
	}

	cin.ignore();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
