/**
 * @brief  CS-202 Project 7 MyString class Implementation
 * @Author Ethan Mahoney
 *
 * This file is the Implementation file with the implementation of the Dynamic Allocation MyString class prescribed in Project 7 of CS-202
 */

#include "MyString/MyString.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

//Default Constructor
MyString::MyString() : m_size(0)
{
  std::cout << "Default Constructor Called" << std::endl;
  m_buffer = NULL;
}

//Parameterized Constructor
MyString::MyString(const char * str)
{
  std::cout << "Parameterized Constructor Called" << std::endl;

//Error handling to check for correct allocation of memory
  try
  {
    m_size = strlen(str) + 1;
    buffer_allocate(m_size);
    strcpy(m_buffer, str);   
  }
  catch(const std::bad_alloc & e)   //Catch to check for bad_alloc and display error message
  {
    std::cerr << "Failure To Create Parameterized Constructor" << std::endl << std::endl;
    e.what();
    throw;
  } 
}

//Copy Constructor
MyString::MyString(const MyString & other_myStr)
{
  std::cout << "Copy Constructor Called" << std::endl;

  try
  {
    m_size = other_myStr.size();
    buffer_allocate(m_size);
    strcpy(m_buffer, other_myStr.c_str());
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Failure To Create Copy Constructor" << std::endl << std::endl;
    e.what();
    throw;
  } 
}

//Destructor to call deallocate function
MyString::~MyString()
{
  std::cout << "Destructor Called" << std::endl;

  buffer_deallocate();
}

//Allocation function which used new to allocate desired memory
void MyString::buffer_allocate(size_t size)
{
  try
  {
    m_buffer = new char[size];
    m_size = size;
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Failure To Properly Allocate Memory" << std::endl << std::endl;
    e.what();
    throw;
  } 
}
 
//Deallocate to delete memory in said pointer and set to NULL 
void MyString::buffer_deallocate()
{
  delete [] m_buffer; 
  m_buffer = NULL;
  m_size = 0;
}

//Get size function
size_t MyString::size() const
{
  return m_size;
}

//Get length function
size_t MyString::length() const
{
  return strlen(m_buffer);
}

//Get string function
const char* MyString::c_str() const
{
  return m_buffer;
}

//Operator comparison overload to compare strings
bool MyString::operator== (const MyString & other_myStr) const
{
  if(!strcmp(m_buffer, other_myStr.c_str()))
    return true;

  return false;
}

//Operator assign overload to assign strings to other objects
MyString & MyString::operator= (const MyString & other_myStr)
{
  if(this != &other_myStr) //Check for self assignment
  {
    strcpy(m_buffer, other_myStr.c_str());
    m_size = other_myStr.size();

    return *this;
  }
  return *this;
}

//Operator overlaod to add a string to another string like concatenate
MyString MyString::operator+ (const MyString & other_myStr) const
{
  char wholeStr[m_size + other_myStr.m_size];
  
  strcpy(wholeStr, m_buffer);
  strcat(wholeStr, other_myStr.m_buffer);

  
  return MyString (wholeStr);
}

//Operator overload to return index to string location
char & MyString::operator[] (size_t index)
{ 
  return m_buffer[index];
}

//Another operator overload to return index to string location
const char & MyString::operator[] (size_t index) const
{
  return m_buffer[index];
}

//Insertion operator overload to display string contents of a class object
std::ostream & operator<<(std::ostream & os, const MyString & myStr)
{
  os << myStr.c_str() << std::endl;
  
  return os;
}

