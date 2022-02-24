/**
 * @brief  CS-202 Project 10 Test Driver
 * @author Ethan Mahoney
 *
 * This file contains a test driver for a Node/Array-based Stack for the purposes of CS-202.
 */
#include <iostream>
#include "ArrayStack/ArrayStack.hpp"
#include "NodeStack/NodeStack.hpp"

using namespace std;

int main() 
{
 	cout << "Node/Array Stack Test\n" << "=======================" << endl;

	cout << "Default Ctor Test" << endl;
    	ArrayStack<char> asDefault;
    	NodeStack<float> nsDefault;

    	cout << "\nParameterized Ctor Test\n" << "=======================" << endl;

    	ArrayStack<char> asParam(9, 'v');
	cout << asParam << endl << endl;

    	NodeStack<float> nsParam(6, 9.8);    	
    	cout << nsParam << endl << endl;

    	cout << "Copy Ctor Test\n" << "=======================" << endl;

   	ArrayStack<char> asCopy(asParam);
	cout << asCopy << endl << endl;

   	NodeStack<float> nsCopy(nsParam);
    	cout << nsCopy << endl << endl;

    	cout << "Assigment Operator Test\n" << "=======================" << endl;

    	ArrayStack<char> asAssign;
	asAssign = asParam;
	cout << asAssign << endl << endl;

   	NodeStack<float> nsAssign;    
   	nsAssign = nsParam;
    	cout << nsAssign << endl << endl;

    	cout << "Push Test\n" << "=======================" << endl;

    	asAssign.push('d');
	cout << "Array-Based Stack Push" << endl << asAssign << endl << endl;

	nsAssign.push(12.45);
	cout << "Node-Based Stack Push" << endl << nsAssign << endl << endl;

	cout << "Pop Test\n" << "=======================" << endl;

    	asAssign.pop();
	cout << "Array-Based Stack Pop" << endl << asAssign << endl << endl;

	nsAssign.pop();
	cout << "Node-Based Stack Pop" << endl << nsAssign << endl << endl;
    
	cout << "Empty Test\n" << "=======================" << endl;

	cout << "Checking to see if the Array-Based Stack is Empty:" << endl;
	cout << boolalpha << asAssign.empty() << endl << endl;

	cout << "Checking to see if the Node-Based Stack is Empty:" << endl;
	cout << boolalpha << nsAssign.empty() << endl << endl;
    
	cout << "Top Test\n" << "=======================" << endl;
	
	cout << "Displaying the top of the Array-Based Stack:" << endl;
	cout << asAssign.top() << endl << endl;

	cout << "Displaying the top of the Node-Based Stack:" << endl;
	cout << nsAssign.top() << endl << endl;

	cout << "Clear Test\n" << "=======================" << endl;
	
	cout << "Clearing the Array-Based Stack:" << endl;
	asAssign.clear();
	cout << asAssign << endl;

	cout << "Clearing the Node-Based Stack:" << endl;
	nsAssign.clear();
	cout << nsAssign << endl;

	cout << "End of Tests" << endl;

	return 0;
}
