/**
 * @brief  CS-202 ArrayQueue class Implementation
 * @author Ethan Mahoney
 *
 * This file is the implementation of the general ArrayQueue class for the purposes of CS-202.
 */
#include <iostream>
#include "ArrayQueue/ArrayQueue.h"


ArrayQueue::ArrayQueue()
{
  m_front = 0;
  m_back = 0;
  m_size = 0;

  std::cout << "Array Default Ctor Successfully Called" << std::endl;
}

ArrayQueue::ArrayQueue(size_t count, const DataType & value)
{
  m_front = 0;
  m_back = 0;
  m_size = 0;

  for(size_t i = 0; i < count; i++)
  {
    push(value);
  }

  std::cout << "Array Parameterized Ctor Successfully Called" << std::endl;
}

ArrayQueue::ArrayQueue(const ArrayQueue & other)
{
  m_size = 0;
  m_front = other.m_front;
  m_back = other.m_front;

  for(size_t i = 0; i < other.m_size; i++)
  {
    push(other.m_array[other.m_front + i]);
  }

  std::cout << "Array Copy Ctor Successfully Called" << std::endl;
}

ArrayQueue::~ArrayQueue()
{
  std::cout << "Array Dtor Successfully Called" << std::endl;
}

ArrayQueue & ArrayQueue::operator=(const ArrayQueue & rhs)
{
  if(this != &rhs)
  {
    m_size = 0;
    m_front = rhs.m_front;
    m_back = rhs.m_front;

    for(size_t i = 0; i < rhs.m_size; i++)
    {
      push(rhs.m_array[rhs.m_front + i]);
    }
  }

  return *this;
}

DataType & ArrayQueue::front()
{
  return m_array[m_front];
}

const DataType & ArrayQueue::front() const
{
  return m_array[m_front];
}

DataType & ArrayQueue::back()
{
  return m_array[m_back];
}

const DataType & ArrayQueue::back() const
{
  return m_array[m_back];
}

void ArrayQueue::push(const DataType & value)
{
  if(!full())
  {
    if(empty())
    {
      m_array[m_back] = value;
      m_size++;
    }
    else
    {
      m_back = (m_back + 1) % ARRAY_CAPACITY;
      m_array[m_back] = value;
      m_size++;
    }
  }
}

void ArrayQueue::pop()
{
  if(!empty())
  {
    m_front = (m_front + 1) % ARRAY_CAPACITY;
    m_size--;
  }
}

size_t ArrayQueue::size() const
{
  return m_size;
}

bool ArrayQueue::empty() const
{
  if(m_size == 0)
  {
    return true;
  }

  return false;
}

bool ArrayQueue::full() const
{
  if(m_size == ARRAY_CAPACITY)
  {
    return true;
  }

  return false;
}

void ArrayQueue::clear()
{
  m_size = 0;
  m_front = 0;
  m_back = 0;
}

void ArrayQueue::serialize(std::ostream & os) const
{
  for(size_t i = 0; i < m_size; i++)
  {
    os << m_array[(i + m_front) % ARRAY_CAPACITY] << std::endl;
  }
}

std::ostream & operator<<(std::ostream & os, const ArrayQueue & arrayQueue)
{
  arrayQueue.serialize(os);
  return os;
}

