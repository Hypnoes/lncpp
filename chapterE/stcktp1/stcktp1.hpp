// stcktp1.h -- modified Stack template
#ifndef STACKTP1_H_
#define STACKTP1_H_

template<typename T>
class Stack
{
  private:
    enum {SIZE = 10};
    int _stack_size;
    T * _items;
    int _top;

  public:
    explicit Stack(int ss = SIZE);
    Stack(const Stack & st);
    ~Stack() { delete [] _items; }

    bool is_empty() { return _top == 0; }
    bool is_full() { return _top == _stack_size; }
    bool push(const T & item);
    bool pop(T & item);
    Stack & operator=(const Stack & st);
};

template<typename T>
Stack<T>::Stack(int ss) : _stack_size(ss), _top(0)
{
    _items = new T[_stack_size];
}

template<typename T>
Stack<T>::Stack(const Stack & st)
{
    _stack_size = st._stack_size;
    _top = st._top;
    _items = new T[_stack_size];
    for (int i = 0; i < _top; i++)
        _items[i] = st._items[i]
}

template<typename T>
bool Stack<T>::push(const T & i)
{
    if (_top < _stack_size)
    {
        _items[_top++] = i;
        return true;
    }
    else
        return false;
}

template<typename T>
bool Stack<T>::pop(T & i)
{
    if (_top > 0)
    {
        i = _items[--_top];
        return true;
    }
    else
        return false;
}

template<typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & st)
{
    if (this == &st)
        return *this;
    delete [] _items;
    _stack_size = st._stack_size;
    _top = st._top;
    _items = new T[_stack_size];
    for (int i = 0; i < _top; i++)
        _items[i] = st._items[i];
    return *this;
}

#endif