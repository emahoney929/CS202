/**
 * @brief  CS-202 NodeQueue class Declaration
 * @author Ethan Mahoney
 *
 * This file is the declaration of the general NodeQueue class for the purposes of CS-202.
 */
#include <iostream>
#include "DataType/DataType.h"
#include "NodeList/NodeList.h"

class NodeQueue {

friend std::ostream & operator<<(std::ostream & os, const NodeQueue & nodeQueue);  //(i)

public:
NodeQueue();                                             //(1)
NodeQueue(size_t size, const DataType & value);          //(2)
NodeQueue(const NodeQueue & other);                     //(3)
~NodeQueue();                                            //(4)

NodeQueue & operator=(const NodeQueue & rhs);              //(5)

DataType & front();                                         //(6a)
const DataType & front() const;                             //(6b)

DataType & back();                                          //(7a)
const DataType & back() const;                              //(7b)

void push(const DataType & value);                           //(8)
void pop();                                                //(9)

size_t size() const;                                       //(10)
bool empty() const;                                        //(11)
bool full() const;                                         //(12)
void clear();                                              //(13)
void serialize(std::ostream & os) const;                     //(14)

private:
  Node* m_front;
  Node* m_back;
};
