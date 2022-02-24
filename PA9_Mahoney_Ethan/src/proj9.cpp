/**
 * @brief  CS-202 Test Driver
 * @author Ethan Mahoney
 *
 * This file is the Test Driver for the purposes of CS-202.
 */
#include <iostream>
#include "NodeQueue/NodeQueue.h"
#include "ArrayQueue/ArrayQueue.h"

using namespace std;

int main()
{
	//Tests for Node and Array based Queue
	cout << "BEGINNING OF TESTS\n" << "===========================" << endl;
	cout << "Constructor Tests:\n" << endl;

	//Test for the Default Constructor
	cout << "Default Ctor Test:" << endl;
	ArrayQueue aq;
	NodeQueue nq;

	//Test for the Parameterized Constructor
	cout << "\nParameterized Ctor Test:" << endl;
	DataType dt1(35, 345.24);
	DataType dt2(87, 129.04);
	ArrayQueue aparamq(15, dt1);
	cout << aparamq << endl;

	NodeQueue nparamq(8, dt2);
	cout << nparamq << endl;

	//Test for the Copy Constructor
	cout << "Copy Ctor Test:" << endl;
	ArrayQueue copyArr(aparamq);
	cout << copyArr << endl;

	NodeQueue copyNode(nparamq);
	cout << copyNode << endl;
	
	//Test for the Destructor
	cout << "Dtor Test:" << endl;
	{
		ArrayQueue darr;
		NodeQueue dnode;
	}

	//Test for the Assignment Operator
	cout << "\nAssignment Operator Test:" << endl;
	DataType dt3(583, 0.234);
	DataType dt4(123, 543.98);
	ArrayQueue assignArr = ArrayQueue(10, dt3);
	cout << assignArr << endl;

	NodeQueue assignNode = NodeQueue(5, dt4);
	cout << assignNode << endl;

	//Test for the Front Function
	cout << "Front Function Test:" << endl;
	cout << assignArr.front() << endl;
	cout << assignNode.front() << endl << endl;
	
	//Test for the Back Function
	cout << "Back Function Test:" << endl;
	cout << assignArr.back() << endl;
	cout << assignNode.back() << endl << endl;

	//Test for the Push Function
	cout << "Push Function Test:" << endl;
	DataType dt5(98, 88.17);
	
	cout << "Pushing " << dt5 << " into the back of the Array Queue" << endl << endl;
	assignArr.push(dt5);
	cout << assignArr << endl;

	cout << "Pushing " << dt5 << " into the back of the Node Queue" << endl << endl;
	assignNode.push(dt5);
	cout << assignNode << endl;

	//Test for the Pop Function
	cout << "Pop Function Test:" << endl;
	cout << "Popping the first value from the Array Queue" << endl << endl;
	assignArr.pop();
	cout << assignArr << endl;

	cout << "Popping the first value from the Node Queue" << endl << endl;
	assignNode.pop();
	cout << assignNode << endl;

	//Test for the Size Function
	cout << "Size Function Test:" << endl;
	cout << "Displaying the size of the Array Queue" << endl;
	cout << assignArr.size() << endl;
	
	cout << "Displaying the size of the Node Queue" << endl;
	cout << assignNode.size() << endl << endl;
	
	//Test for the Empty Function
	cout << "Empty Funciton Test:" << endl;
	cout << "Checking to see if the Array Queue is empty:" << endl;
	cout << boolalpha << assignArr.empty() << endl;
	
	cout << "Checking to see if the Node Queue is empty:" << endl;
	cout << boolalpha << assignNode.empty() << endl << endl;

	//Test for the Full Function
	cout << "Full Function Test:" << endl;
	cout << "Checking to see if the Array Queue is full:" << endl;
	cout << boolalpha << assignArr.full() << endl;
	
	cout << "Checking to see if the Node Queue is full:" << endl;
	cout << boolalpha << assignNode.full() <<  endl << endl;

	//Test for the Clear Function
	cout << "Clear Function Test:" << endl;
	cout << "Clearing the Array Queue:" << endl;
	assignArr.clear();
	cout << assignArr << endl;

	cout << "Clearing the Node Queue:" << endl;
	assignNode.clear();
	cout << assignNode << endl;

	//End of Test Driver
	cout << "END OF TESTS\n" << "===========================" << endl;
	return 0;
}


