/**
 * @brief  CS-202 NodeQueue class Implementation
 * @author Ethan Mahoney
 *
 * This file is the implementation of the general NodeQueue class for the purposes of CS-202.
 */
#include <iostream>
#include "NodeQueue/NodeQueue.h"

NodeQueue::NodeQueue() : m_front(nullptr), m_back(nullptr)
{
  std::cout << "Node Default Ctor Successfully Called" << std::endl;
}

NodeQueue::NodeQueue(size_t size, const DataType & value)
{
  m_front = nullptr;
  m_back = nullptr;

  for(size_t i = 0; i < size; i++)
  {
    push(value);
  }

  std::cout << "Node Parameterized Ctor Successfully Called" << std::endl;
}

NodeQueue::NodeQueue(const NodeQueue & other)
{
  m_front = nullptr;
  m_back = nullptr;

  if(!other.empty())
  {
    for(Node* curr = other.m_front; curr != nullptr; curr = curr->m_next)
    {
      push(curr->m_data);
    }
  }
  else
  {
    m_front = m_back = nullptr;
  }

  std::cout << "Node Copy Ctor Successfully Called" << std::endl;
}

NodeQueue::~NodeQueue()
{
  Node* del_node;
  Node* curr = m_front;

  while(curr != nullptr)
  {
    del_node = curr;
    curr = curr->m_next;
    delete del_node;
  }
 
  std::cout << "Node Dtor Successfully Called" << std::endl;
}

NodeQueue & NodeQueue::operator=(const NodeQueue & rhs)
{
  if(this != &rhs)
  {
    if(m_front)
    {
      clear();
    }

    for(Node* curr = rhs.m_front; curr != nullptr; curr = curr->m_next)
    {
      push(curr->m_data);
    }
  }

  return *this;
}

DataType & NodeQueue::front()
{
  return m_front->m_data;
}

const DataType & NodeQueue::front() const
{
  return m_front->m_data;
}

DataType & NodeQueue::back()
{
  return m_back->m_data;
}

const DataType & NodeQueue::back() const
{
  return m_back->m_data;
}

void NodeQueue::push(const DataType & value)
{
  if(empty())
  {
    m_front = m_back = new Node(value);
  }
  else
  {
    Node* newNode = new Node(value);
    m_back->m_next = newNode;
    m_back = newNode;
  }
}

void NodeQueue::pop()
{
  Node* del_node = m_front;
  m_front = m_front->m_next;
  delete del_node;
}

size_t NodeQueue::size() const
{
  size_t count = 0;

  for(Node* curr = m_front; curr != nullptr; curr = curr->m_next)
  {
    count++;
  }

  return count;
}

bool NodeQueue::empty() const
{
  if(m_front)
  {
    return false;
  }

  return true;
}

bool NodeQueue::full() const
{
  return false;
}

void NodeQueue::clear()
{
  Node* del_node;
  Node* curr = m_front;

  while(curr != nullptr)
  {
    del_node = curr;
    curr = curr->m_next;
    delete del_node;
  }

  m_front = m_back = nullptr;
}

void NodeQueue::serialize(std::ostream & os) const
{
  for(Node* curr = m_front; curr != nullptr; curr = curr->m_next)
  {
    os << curr->m_data << std::endl;
  }
}

std::ostream & operator<<(std::ostream & os, const NodeQueue & nodeQueue)
{
  nodeQueue.serialize(os);
  return os;
}

