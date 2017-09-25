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

	// Добавление элемента в конец массива.
	void Add( int element );

	// Удалить count элементов начиная с позиции pos.
	void DeleteAt( int pos );

	// Удалить все элементы массива.
	void DeleteAll();

	// Доступ к элементу массива по индексу.
	int& GetAt( int index );

	// Доступ к элементу массива по индексу.
	int& operator[]( int index ) { return GetAt( index ); }

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
	// Размер буфера (поле size не должно превышать capacity).
	int capacity;
	// Количество элементов в массиве.
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
	// Если надо, расширяем буфер.
	if( size + 1 > capacity ) {
		grow();
	}

	// Записываем element в буфер.
	assert( size < capacity );
	buffer[size] = element;
	size++;
}

void CArrayV1::DeleteAt( int pos )
{
	assert( pos >= 0 );
	assert( buffer != nullptr );

	// Перемещаем содержимое парвой половины буфера на count позиций влево.
	// Для простых типов эффективней использовать не цикл, а функцию memcpy.
	for( int i = pos + 1; i < size; i++ ) {
		buffer[i - 1] = buffer[i];
	}
	size--;
}

// Удалить все элементы массива.
void CArrayV1::DeleteAll()
{
	delete[] buffer;
	buffer = 0;
	capacity = 0;
	size = 0;
}

// Доступ к элементу массива по индексу.
int& CArrayV1::GetAt( int index )
{
	assert( index >= 0 );
	assert( index < size );
	assert( buffer != nullptr );

	return buffer[index];
}

// Увеличивает размер буфера.
void CArrayV1::grow()
{
	// Выделяем буфер с запасом.
	const int newCapacity = ( size == 0 ) ? 8 : size * 2;
	int* newBuffer = new int[newCapacity];

	// Копируем содержимое старого буфера в новый буфер.
	for( int i = 0; i < size; i++ ) {
		newBuffer[i] = buffer[i];
	}
	delete[] buffer;

	// Переключаемся на новый буфер.
	buffer = newBuffer;
	capacity = newCapacity;
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

int main_ClassArrayV1()
{
	CArrayV1 a;

	for( int i = 0; i < 10; i++ ) {
		a.Add( i );
	}

	a.DeleteAt( 2 );

	// Использование CArrayV1::operator[]
	a[5] = 100;

	// Использование CArrayV1::operator<<
	a << 20 << 21 << 23;

	for( int i = 0; i < a.Size(); i++ ) {
		cout << a[i] << " ";
	}

	cin.ignore();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
