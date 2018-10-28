// stacktp -- enhanced stack
#ifndef STACKTP_H_
#define STACKTP_H_

template<typename T>
class Stack
{
  private:
    enum {MAX = 10};
    T _items[MAX];
    int _top;

  public:
    Stack();
    bool is_empty();
    bool is_full();
    bool push(const T & _item);
    bool pop(T & _item);
};

template<typename T>
Stack<T>::Stack()
{
    _top = 0;
}

template<typename T>
bool Stack<T>::is_empty()
{
    return _top == 0;
}

template<typename T>
bool Stack<T>::is_full()
{
    return _top == MAX;
}

template<typename T>
bool Stack<T>::push(const T & i)
{
    if (_top < MAX)
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

#endif