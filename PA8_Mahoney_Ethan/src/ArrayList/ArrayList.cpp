/**
 * @brief  CS-202 ArrayList class Implementation
 * @author Ethan Mahoney
 *
 * This file contains a class implementation for a Array-based Forward List for the purposes of CS-202.
 */
#include <iostream>
#include "ArrayList/ArrayList.h"

ArrayList::ArrayList() : m_array(nullptr), m_size(0), m_maxsize(0)
{
	std::cout << "Successfully Called Array Default Ctor" << std::endl;
}

ArrayList::ArrayList(size_t count, const DataType & value)
{
	m_array = new DataType [count];
	m_size = count;
	m_maxsize = count;

	for(size_t i = 0; i < count; i++)
	{
		m_array[i] = value;
	}	

	std::cout << "Successfully Called Array Paramterized Ctor" << std::endl;
}

ArrayList::ArrayList(const ArrayList & other)
{
	m_array = new DataType [other.m_maxsize];
	m_size = other.m_size;
	m_maxsize = other.m_maxsize;

	for(size_t i = 0; i < other.m_size; i++)
	{
		m_array[i].intVal() = other.m_array[i].intVal();
		m_array[i].doubleVal() = other.m_array[i].doubleVal();
	}

	std::cout << "Successfully Called Array Copy Ctor" << std::endl;
}

ArrayList::~ArrayList()
{
	delete [] m_array;

	std::cout << "Successfully Called Array Dtor" << std::endl;
}

DataType * ArrayList::front()
{
	if(m_array)
	{
		return m_array;
	}
	
	return nullptr;
}

DataType * ArrayList::back()
{
	if(m_array)
	{
		return &m_array[m_size - 1];
	}
	
	return nullptr;
}

DataType * ArrayList::find(const DataType & target, DataType * & previous, const DataType * start)
{
	DataType* curr = m_array;
	size_t i = 0;
	
	while(curr != nullptr)
	{
		if(m_array[i] == target && i == 0)
		{
			previous = nullptr;
			return &m_array[i];
		}
		else if(m_array[i] == target)
		{
			previous = &m_array[i - 1];
			return &m_array[i];
		}
		
		i++;
		curr = &m_array[i];
	}

	previous = nullptr;
	return nullptr;
}

DataType * ArrayList::insertAfter(const DataType * target, const DataType & value)
{
	size_t positionChange = 0;
	size_t position;
	DataType* newElement = nullptr;

	if(m_array)
	{
		if(target)
		{	
			if(m_size + 1 > m_maxsize)
			{
				for(size_t i = 0; i < m_size; i++)
				{
					if(target == &m_array[i])
					{
						position = i;
						break;
					}
				}
				resize(m_size + 1); 
				target = &m_array[position]; 
			}
			
			DataType* tempArr = new DataType [m_maxsize];
	
			for(size_t i = 0; i < m_size; i++)
			{
				if(target == &m_array[i])
				{
					tempArr[i] = m_array[i];
					positionChange = 1;
					tempArr[i + positionChange] = value;
				}
				else
				{
					tempArr[i + positionChange] = m_array[i];
				}
			}

			m_size += 1;
	
			for(size_t i = 0; i < m_size; i++)
			{
				m_array[i] = tempArr[i];
				
				
			}
			
			for(size_t i = 0; i < m_size; i++)
			{
				if(target == &m_array[i])
				{
					newElement = &m_array[i+1];
				}
			}
		}
	}	
	
	return newElement;
}

DataType * ArrayList::insertBefore(const DataType * target, const DataType & value)
{
	DataType* newElement = nullptr;
	size_t position;
	size_t newPosition = 0;
	size_t positionChange = 0;

	if(m_array)
	{
		if(target)
		{
			if(m_size + 1 > m_maxsize)
			{
				for(size_t i = 0; i < m_size; i++)
				{
					if(target == &m_array[i])
					{
						position = i;
						break;
					}
				}
	
				resize(m_size + 1); 
				target = &m_array[position];
	
			}
	
			DataType* tempArr = new DataType [m_maxsize];
	
			for(size_t i = 0; newPosition < m_size; i++)
			{
				if(target == &m_array[i + 1])
				{
					tempArr[i] = m_array[i];
					positionChange = 1;
					tempArr[i + positionChange] = value;
				}
				else
				{
					tempArr[i + positionChange] = m_array[i];
				}
	
				newPosition = i + positionChange;
			}

			m_size += 1;

			for(size_t i = 0; i < m_size; i++)
			{
				m_array[i] = tempArr[i];		
			}
		
			for(size_t i = 0; i < m_size; i++)
			{
				if(target == &m_array[i + 1])
				{
					newElement = &m_array[i];
				}
			}	 
		}
	}

	return newElement;
}

DataType * ArrayList::erase(const DataType * target)
{
	DataType* delArr = new DataType [m_size];
	size_t positionChange = 0;

	if(target)
	{
		for(size_t i = 0; i < m_size; i++)
		{
			if(target == &m_array[i])
			{
				positionChange = 1;	
			}
			else
			{
				delArr[i - positionChange] = m_array[i];
			}
		}
	
		for(size_t i = 0; i < m_size; i++)
		{
			m_array[i] = delArr[i];
		}

		resize(m_size - 1);
	}

	return &m_array[0];
}


DataType & ArrayList::operator[] (size_t position)
{
	return m_array[position];
}

size_t ArrayList::size() const	
{
	return m_size;
}
	
bool ArrayList::empty() const
{
	if(m_array)
	{
		return false;
	}

	return true;
}

void ArrayList::clear()
{
	delete [] m_array;
	m_array = nullptr;
	m_size = 0;
	m_maxsize = 0;
}

void ArrayList::resize(size_t count)
{
	DataType* copy = new DataType [count];
	size_t counter = 0;

	for(size_t i = 0; i < m_size; i++)
	{
		copy[i] = m_array[i];
	}

	delete [] m_array;
	m_array = new DataType [count];

	if(count > m_maxsize)
	{
		m_maxsize = count;
		
		for(size_t i = 0; i < m_maxsize; i++)
		{
			if(i >= m_size)
			{
				m_array[i].intVal() = 0;
				m_array[i].doubleVal() = 0;
			}
			else
			{
				m_array[i] = copy[i];
			}
		}
	}
	else
	{
		m_maxsize = count;

		for(size_t i = 0; i < m_maxsize; i++)
		{
			
				m_array[i] = copy[i];	
				counter++;
			
		}

		m_size = count;
	}
}
	

std::ostream & operator<<(std::ostream & os, const ArrayList & arrayList)
{
	for(size_t i = 0; i < arrayList.m_size; i++)
	{
		os << arrayList.m_array[i] << std::endl;
	}

	return os;
}


				
		
		
