// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
    private:
    enum { MAX = 10 };
    Item items[MAX];
    int top;

    public:
    Stack();
    bool is_empty() const;
    bool is_full() const;
    bool push(const Item &);
    bool pop(Item &);
};

#endif