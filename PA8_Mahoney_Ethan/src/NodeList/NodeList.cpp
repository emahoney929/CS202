/**
 * @brief  CS-202 NodeList class Implementation
 * @author Ethan Mahoney
 *
 * This file contains a class implementation for a Node-based Forward List for the purposes of CS-202.
 */
#include <iostream>
#include "NodeList/NodeList.h"


NodeList::NodeList() : m_head(nullptr)
{
	std::cout << "Successfully Called Node Default Ctor" << std::endl;
}


NodeList::NodeList(size_t count, const DataType & value)
{
	m_head = new Node(value);

	Node *newNode = m_head;

	for(size_t i = 1; i < count; i++)
	{
		newNode->m_next = new Node(value);
		newNode = newNode->m_next;
	}

	newNode = nullptr;
	
	std::cout << "Successfully Called Node Parameterized Ctor" << std::endl;
}

NodeList::NodeList(const NodeList & other)
{
	if(other.m_head)
	{
		m_head = new Node(other.m_head->m_data);

		Node *newNode = m_head;

		for(size_t i = 1; i < 5; i++)
		{
			newNode->m_next = new Node(other.m_head->m_data);
			newNode = newNode->m_next;
		}	

		newNode = nullptr;
	}
	else
	{
		m_head = nullptr;
	}

	std::cout << "Successfully Called Node Copy Ctor" << std::endl;
}

NodeList::~NodeList()
{
	if(m_head)
	{
		Node* orig_node = m_head;

		while(orig_node != nullptr)
		{
			Node* next = orig_node->m_next;
			delete orig_node;
			orig_node = next;
		}

		m_head = nullptr;
	}

	std::cout << "Successfully Called Node Dtor" << std::endl;
}

NodeList & NodeList::operator= (const NodeList & rhs)
{
	if(this != &rhs)
	{
		if(m_head)
		{
			Node* orig_node = m_head;

			while(orig_node != nullptr)
			{
				Node* next = orig_node->m_next;
				delete orig_node;
				orig_node = next;
			}

			m_head = nullptr;
		}
		
		m_head = new Node(rhs.m_head->m_data);

		Node *newNode = m_head;

		for(size_t i = 1; i < 5; i++)
		{
			newNode->m_next = new Node(rhs.m_head->m_data);
			newNode = newNode->m_next;
		}	
	}
	
	return *this;
}

Node * NodeList::front()
{
	if(m_head)
	{
		return m_head;
	}
	
	return nullptr;
}

Node * NodeList::back()
{
	if(m_head)
	{
		while(m_head->m_next != nullptr)
		{
			m_head = m_head->m_next;
		}

		return m_head;
	}

	return nullptr;
}

Node * NodeList::find(const DataType & target, Node * & previous, const Node * start)
{
	Node *curr = (start == nullptr) ? m_head : start->m_next;

	while(curr != nullptr)
	{
		if(curr->m_data == target)
		{
			previous = nullptr;
			return curr;

		}
		
		previous = curr;
		curr = curr->m_next;
	}
	
	return nullptr;
}

Node * NodeList::insertAfter(const DataType * target, const DataType & value)
{
	Node *newNode = new Node(value);

	if(m_head == nullptr)
	{
		m_head = newNode;
		m_head->m_next = nullptr;		
		return m_head;
	}
	else
	{
		for(Node *curr = m_head; curr != nullptr; curr = curr->m_next)
		{
			if(curr->m_data == *target)
			{
				newNode->m_next = curr->m_next;
				curr->m_next = newNode;
				return newNode;
			}
		}
	}
	
	return nullptr;
}

Node * NodeList::insertBefore(const DataType * target, const DataType & value)
{
	Node *newNode;

	if(m_head == nullptr)
	{
		m_head = new Node(value);
		m_head->m_next = nullptr;
		return m_head;
	}
	else
	{
		for(Node *curr = m_head; curr != nullptr; curr = curr->m_next)
		{
			if(curr->m_data == *target && curr == m_head)
			{
				newNode = new Node(value);
				newNode->m_next = m_head;
				m_head = newNode;
				return m_head;
			}
			else if(curr->m_data == *target)
			{
				for(Node* temp = m_head; temp != nullptr; temp = temp->m_next)
				{
					if(temp->m_next->data() == curr->data())
					{
						newNode = new Node(value);
						newNode->m_next = curr;
						temp->m_next = newNode;
						return newNode;
					}
				}
			}
		}
	}

	return nullptr;
}

Node * NodeList::erase(const DataType * target)
{
	size_t count = 0;

	if(m_head)
	{
		for(Node* curr = m_head; curr != nullptr; curr = curr->m_next)
		{
			Node* del_node = curr->m_next;

			if(curr->m_data == *target && count == 0)
			{
				Node* orig_head = m_head;
				m_head = m_head->m_next;
				delete orig_head;
				return m_head;
			}
			else if(del_node != nullptr && del_node->m_data == *target)
			{
				curr->m_next = del_node->m_next;
				delete del_node;
				return  curr->m_next;
			}
			else if(del_node == nullptr && curr->m_data == *target)
			{
				delete curr;
				return nullptr;
			}
			
			count++;
		}
	}

	return nullptr;
}

DataType & NodeList::operator[] (size_t position)
{
	Node* curr = m_head;

	for(size_t count = 0; count < position; count++)
	{
		curr = curr->m_next;
	}

	return curr->m_data;
}

					
const DataType & NodeList::operator[] (size_t position) const 
{
	Node* curr = m_head;

	for(size_t count = 0; count < position; count++)
	{
		curr = curr->m_next;
	}

	return curr->m_data;
}

size_t NodeList::size() const
{
	size_t count = 0;

	for(Node* curr = m_head; curr != nullptr; curr = curr->m_next)
	{
		count++;
	}
		
	return count;
}

bool NodeList::empty() const
{
	if(m_head)
	{
		return false;
	}
	
	return true;
}

void NodeList::clear()
{
	Node* orig_node = m_head;

	while(orig_node != nullptr)
	{
		Node* next = orig_node->m_next;
		delete orig_node;
		orig_node = next;
	}

	m_head = nullptr;
} 	
		
std::ostream & operator<<(std::ostream & os, const NodeList & nodeList)
{
	for(size_t i = 0; i < nodeList.size(); i++)
	{
		os << nodeList[i] << std::endl;
	}

	return os;
}
