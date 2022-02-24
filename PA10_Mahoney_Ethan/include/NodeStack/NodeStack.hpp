/**
 * @brief  CS-202 Project 10 NodeStack Template Class
 * @author Ethan Mahoney
 *
 * This file contains a template class for a Node-based Stack for the purposes of CS-202.
 */
#ifndef NODESTACK_HPP_
#define NODESTACK_HPP_
#include <iostream>
#include "NodeStack/Node.hpp"

using namespace std;

template <typename T> class NodeStack;
template <typename T> std::ostream & operator<< (std::ostream & os, const NodeStack<T>  & nodeStack);

template <typename T>
class NodeStack {
  friend std::ostream & operator<< <> (std::ostream & os, const NodeStack<T> & nodeStack);

  public:
    NodeStack();
    NodeStack(size_t count, const T & value);
    NodeStack(const NodeStack<T> & other);
    ~NodeStack();

    NodeStack<T> & operator= (const NodeStack<T> & rhs);

    T & top();
    const T & top() const;

    void push(const T & value);
    void pop();

    size_t size() const;
    bool empty() const;
    bool full() const;
    void clear();
    void serialize(std::ostream & os) const;

  private:
    Node<T> * m_top;
};

template <typename T>
NodeStack<T>::NodeStack() : m_top(nullptr)
{
  cout << "Node-Based Stack Default Ctor Called" << endl;
}

template <typename T>
NodeStack<T>::NodeStack(size_t count, const T & value)
{
  m_top = nullptr;

  for(size_t i = 0; i < count; i++)
  {
    push(value);
  }

  cout << "Node-Based Stack Parameterized Ctor Called" << endl;
}

template <typename T>
NodeStack<T>::NodeStack(const NodeStack<T> & other)
{
  m_top = nullptr;
  Node<T> *curr = other.m_top;
  size_t size = other.size();

  while(size > 0)
  {
    for(size_t i = 0; i < size - 1; i++)
    {
      curr = curr->m_next;
    }

    push(curr->m_data);
    curr = other.m_top;
    size--;
  }

  cout << "Node-Based Stack Copy Ctor Called" << endl;
}

template <typename T>
NodeStack<T>::~NodeStack()
{
  Node<T> *delNode;
  Node<T> *curr = m_top;

  while(curr != nullptr)
  {
    delNode = curr;
    curr = curr->m_next;
    delete delNode;
  }

  cout << "Node-Based Stack Dtor Called" << endl;
}

template <typename T>
NodeStack<T> & NodeStack<T>::operator= (const NodeStack<T> & rhs)
{
  if(this != &rhs)
  {
    if(!rhs.empty())
    {
      clear();

      Node<T> * curr = rhs.m_top;
      size_t size = rhs.size();

      while(size > 0)
      {
        for(size_t i = 0; i < size - 1; i++)
        {
          curr = curr->m_next;
        }

        push(curr->m_data);
	curr = rhs.m_top;
        size -= 1;
      }
    }
  }

  cout << "Node-Based Stack Assignment Operator Called" << endl;

  return *this;
}

template <typename T>
T & NodeStack<T>::top()
{
  return m_top->m_data; 
}

template <typename T>
const T & NodeStack<T>::top() const
{
  return m_top->m_data;
}

template <typename T>
void NodeStack<T>::push(const T & value)
{
  if(empty())
  {
    m_top = new Node<T> (value);
  }
  else
  {
    Node<T> *newNode = new Node<T> (value);
    newNode->m_next = m_top;
    m_top = newNode;
  }
}

template <typename T>
void NodeStack<T>::pop()
{
  if(!empty())
  {
    Node<T> *delNode = m_top;
    m_top = m_top->m_next;
    delete delNode;
  }
}

template <typename T>
size_t NodeStack<T>::size() const
{
  size_t count = 0;

  for(Node<T> *curr = m_top; curr != nullptr; curr = curr->m_next)
  {
    count++;
  }

  return count;
}

template <typename T>
bool NodeStack<T>::empty() const
{
  if(m_top)
  {
    return false;
  }

  return true;
}

template <typename T>
bool NodeStack<T>::full() const
{
  return false;
}

template <typename T>
void NodeStack<T>::clear()
{
  Node<T> *delNode = m_top;
  Node<T> *curr = m_top;

  while(curr != nullptr)
  {
    delNode = curr;
    curr = curr->m_next;
    delete delNode;
  }

  m_top = nullptr;
}

template <typename T>
void NodeStack<T>::serialize(std::ostream & os) const
{
  for(Node<T> *curr = m_top; curr != nullptr; curr = curr->m_next)
  {
    os << curr->m_data << endl;
  }
}

template <class T>
std::ostream & operator<< (std::ostream & os, const NodeStack<T> & nodeStack)
{
  nodeStack.serialize(os);

  return os;
}

#endif
