/**
 * @brief  CS-202 Project 10 ArrayStack Template Class
 * @author Ethan Mahoney
 *
 * This file contains a template class for a Array-based Stack for the purposes of CS-202.
 */
#ifndef ARRAYSTACK_HPP_
#define ARRAYSTACK_HPP_
#include <iostream>

using namespace std;

template <typename T, size_t ARRAY_CAPACITY = 1000> class ArrayStack;
template <typename T, size_t ARRAY_CAPACITY> ostream & operator<< (ostream & os, const ArrayStack<T , ARRAY_CAPACITY> & arrayStack);

template <typename T, size_t ARRAY_CAPACITY>
class ArrayStack {
  friend ostream & operator<< <>(ostream & os, const ArrayStack<T, ARRAY_CAPACITY> & arrayStack);

  public:
    ArrayStack();
    ArrayStack(size_t count, const T & value);
    ArrayStack(const ArrayStack<T, ARRAY_CAPACITY> & other);
    ~ArrayStack();

    ArrayStack<T, ARRAY_CAPACITY> & operator= (const ArrayStack<T, ARRAY_CAPACITY> & rhs);

    T & top();
    const T & top() const;

    void push(const T & value);
    void pop();

    size_t size() const;
    bool empty() const;
    bool full() const;
    void clear();
    void serialize(ostream & os) const;

    private:
      T m_container[ARRAY_CAPACITY];
      size_t m_top;
};

template <typename T, size_t ARRAY_CAPACITY>
ArrayStack<T, ARRAY_CAPACITY>::ArrayStack() : m_top(0)
{
  cout << "Array-Based Stack Default Ctor Called" << endl;
}

template <typename T, size_t ARRAY_CAPACITY>
ArrayStack<T, ARRAY_CAPACITY>::ArrayStack(size_t count, const T & value)
{
  m_top = 0;

  for(size_t i = 0; i < count; i++)
  {
    push(value);
  }

  cout << "Array-Based Stack Parameterized Ctor Called" << endl;
}

template <typename T, size_t ARRAY_CAPACITY>
ArrayStack<T, ARRAY_CAPACITY>::ArrayStack(const ArrayStack<T, ARRAY_CAPACITY> & other) : m_top(0)
{
  if(!other.empty())
  {
    for(size_t i = 0; i < other.size(); i++)
    {
      push(other.m_container[i]);
    }
  }
 
  cout << "Array-Based Stack Copy Ctor Called" << endl;
}

template <typename T, size_t ARRAY_CAPACITY>
ArrayStack<T, ARRAY_CAPACITY>::~ArrayStack()
{
  cout << "Array-Based Stack Dtor Called" << endl;
}

template <typename T, size_t ARRAY_CAPACITY>
ArrayStack<T, ARRAY_CAPACITY> & ArrayStack<T, ARRAY_CAPACITY>::operator= (const ArrayStack<T, ARRAY_CAPACITY> & rhs)
{
  if(!rhs.empty())
  {
    clear();

    for(size_t i = 0; i < rhs.size(); i++)
    {
      push(rhs.m_container[i]);
    }
  }

  cout << "Array-Based Stack Assignment Operator Called" << endl;

  return *this;
}

template <typename T, size_t ARRAY_CAPACITY>
T & ArrayStack<T, ARRAY_CAPACITY>::top()
{
  return m_container[m_top - 1];
}

template <typename T, size_t ARRAY_CAPACITY>
const T & ArrayStack<T, ARRAY_CAPACITY>::top() const
{
  return m_container[m_top - 1];
}

template <typename T, size_t ARRAY_CAPACITY>
void ArrayStack<T, ARRAY_CAPACITY>::push(const T & value)
{
  if(!full())
  {
    m_container[m_top] = value;
    m_top++;
  }
  else
  {
    cout << "Can't push, the Stack is full" << endl;
  }
}

template <typename T, size_t ARRAY_CAPACITY>
void ArrayStack<T, ARRAY_CAPACITY>::pop()
{
  if(!empty())
  {
    --m_top;
  }
  else
  {
    cout << "Can't pop, the Stack is empty" << endl;
  }
}

template <typename T, size_t ARRAY_CAPACITY>
size_t ArrayStack<T, ARRAY_CAPACITY>::size() const
{
  return m_top;
}

template <typename T, size_t ARRAY_CAPACITY>
bool ArrayStack<T, ARRAY_CAPACITY>::empty() const
{
  if(m_top == 0)
  {
    return true;
  }

  return false;
}

template <typename T, size_t ARRAY_CAPACITY>
bool ArrayStack<T, ARRAY_CAPACITY>::full() const
{
  if(m_top == ARRAY_CAPACITY)
  {
    return true;
  }

  return false;
}

template <typename T, size_t ARRAY_CAPACITY>
void ArrayStack<T, ARRAY_CAPACITY>::clear()
{
  m_top = 0;
}

template <typename T, size_t ARRAY_CAPACITY>
void ArrayStack<T, ARRAY_CAPACITY>::serialize(ostream & os) const
{
  for(int i = m_top - 1; i >= 0; i--)
  {
    os << m_container[i] << endl;
  }
}

template <typename T, size_t ARRAY_CAPACITY>
ostream & operator<< (ostream & os, const ArrayStack<T, ARRAY_CAPACITY> & arrayStack)
{
  arrayStack.serialize(os);

  return os;
}

#endif
