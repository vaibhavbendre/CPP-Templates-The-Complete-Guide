# Class Templates

This is something siimilar to function templates. In this case, classes can be parametrized with more data types. Most of **STL Containers** like _std::vector_, _std::list_ etc. are example of this type.

Let's implement a stack container as a class template.

### Class Implementation - Stack

```C++

#ifndef STACKTEMP_HPP_INCLUDED
#define STACKTEMP_HPP_INCLUDED

#include<vector>
#include<cassert>

template<typename T>
class Stack{
    public:
        void push(T const& key);
        void pop();
        T const& topElem() const;
        bool isEmpty() const{
            return stackElem.empty();
        }
    private:
        std::vector<T> stackElem;
};

template<typename T>
void Stack<T>::push(T const& key){
    stackElem.push_back(key);
}

template<typename T>
void Stack<T>::pop(){
    assert(!stackElem.empty());
    stackElem.pop_back();
}

template<typename T>
T const& Stack<T>::topElem() const{
    return stackElem.back();
}

#endif


```

This is fairly basic example to understand the concept.