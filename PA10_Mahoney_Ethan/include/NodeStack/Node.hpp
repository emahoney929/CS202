/**
 * @brief  CS-202 Project 10 Node Template Class
 * @author Ethan Mahoney
 *
 * This file contains a template class for a Node helper class for NodeStack for the purposes of CS-202.
 */
#ifndef NODE_HPP_
#define NODE_HPP_
#include <iostream>

using namespace std;

template <typename T> class NodeStack;

template <typename T>
class Node {
  friend class NodeStack<T>;

  public:
    Node();
    Node(const T & data, Node<T> * next = nullptr);

    T & data();
    const T & data() const;

  private:
    Node<T> * m_next;
    T m_data;
};

template <typename T>
Node<T>::Node() : m_next(nullptr)
{}

template <typename T>
Node<T>::Node(const T & data, Node<T> * next)
{
  m_data = data;
  m_next = next;
}

template <typename T>
T & Node<T>::data()
{
  return m_data;
}

template <typename T>
const T & Node<T>::data() const
{
  return m_data();
}

#endif
