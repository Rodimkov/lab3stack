#pragma once

template <class T>

class Tstack
{
private:
	T *array;
	int size;								// текущий размер
	int Max;								// максимальный размер 
public:
	Tstack(int _size = 100);
	~Tstack();
	Tstack(const Tstack& ts);
	Tstack& operator=(const Tstack& ts);
	int isfull();							// проверка пустоты
	int isempty();							// проверка полноты
	T top();								// получение верхнего элемента
	T pop();								// получение и удаление верхнего элемента
	void push(T el);						// устновка элемента
	void clear();							// очистка стека
};

template <class T>
Tstack<T>::Tstack(int _size)
{
	if( _size <= 0) throw _size;
	array = new T[_size];
	Max = _size;
	size = 0;
}

template <class T>
Tstack<T>::~Tstack()
{
	delete[] array; 
}

template <class T>
Tstack<T>::Tstack(const Tstack& ts)
{
	size = ts.size;
	Max = ts.Max;
	array = new T[Max];
	for(int i = 0 ; i < size ; i++) 
	{
		array[i] = ts.array[i];
	}
}

template <class T>
Tstack<T>& Tstack<T>::operator=(const Tstack& ts)
{
	if( this == &ts ) return *this;
		if( Max != ts.Max )
		{
			delete[] array ;
			Max = ts.Max;
			array = new T[Max];
		}
		size = ts.size;
		for( int i = 0 ; i <size ; i++)
			array[i] = ts.array[i];
	return *this;
}

template <class T>
int Tstack<T>::isfull()
{
	if(size == Max)
		return 1;
	else
		return 0;
}

template <class T>
int Tstack<T>::isempty()
{
	if(size == 0)
		return 1;
	else
		return 0;
}

template <class T>
T Tstack<T>::top()
{
	if(isempty()) throw -1;
	return array[size-1];
}


template <class T>
T Tstack<T>::pop()
{
	if(isempty()) throw -1;
	size--;
	return array[size];
}

template <class T>
void Tstack<T>::push(T el)
{
	if(isfull()) throw -1;
	array[size] = el;
	size++;
}

template <class T>
void Tstack<T>::clear()
{
	size = 0;
}