/**
 * @brief  CS-202 Project 8 Test Driver
 * @author Ethan Mahoney
 *
 * This file contains a test driver for a Node-based Forward List for the purposes of CS-202.
 */
#include <iostream>
#include "ArrayList/ArrayList.h"
#include "NodeList/NodeList.h"

using namespace std;

int main() {

    
//Test for the Default Constructors
	cout << "TESTS FOR ARRAY/NODE LISTS" << endl << "==================================" << endl;
	cout << "Constructor Tests:" << endl << endl;
	cout << "Default Ctors:" << endl;

	ArrayList al;
	NodeList nl;
    
//Test for the Parameterized Constructors	
	cout << "\nParameterized Ctors:" << endl;
	DataType dt1(54, 245.0);
	DataType dt2(18, 76.0);

	ArrayList paramAl(6, dt1);
	cout << paramAl << endl << endl;
    
	NodeList paramNl(6, dt2);
	cout << paramNl << endl << endl;
    
  
//Test for the Copy Constructors	
	cout << "Copy Ctors:" << endl;
	ArrayList copyAl(paramAl);
	cout << copyAl << endl;
    
	NodeList copyNl(paramNl);
	cout << copyNl << endl << endl;
    
//Test for the Destructors 
	cout << "Dtors:" << endl;

	{     
		ArrayList dtorAl(4, dt2);
		NodeList dtorNl(3, dt1);
	}   
	
//Test for the assignment operator            
	cout << "\nTesting Assignment Operator:" << endl;
	DataType assign1(142, 10.0), assign2(83, 43.0), assign3(353, 432.3);

	ArrayList assignArr(4, assign2);
	ArrayList array = assignArr;
	cout << "Data from the Array that got assigned:" << endl;
	cout << array << endl;
	cout << "Data from the Array that did the assigning:" << endl;
	cout << assignArr << endl;

	NodeList assignNode(6, assign1);
	NodeList node = assignNode;
	cout << "Data from the Node that got assigned:" << endl;
	cout << node << endl;
	cout << "Data from the Node that did the assigning:" << endl;
	cout << assignNode << endl;
    
    

//Test for front and back functions             
	cout << "Teseting Front and Back Functions:" << endl;

	ArrayList firstElement(5, assign1), lastElement(5, assign1);
	firstElement[0] = assign2;
	lastElement[4] = assign3;
	DataType* front = firstElement.front();
	cout << "\nTesting the Front function for an Array List:" << endl;
	cout << "The First Element of the Array is:" << endl;
	cout << *front << endl << endl;
	DataType* back = lastElement.back();
	cout << "Testing the Back function for an Array List:" << endl;
	cout << "The Last Element of the Array is:" << endl;
	cout << *back << endl << endl;

	NodeList nodeFront(7, assign2), nodeBack(7, assign2);
	nodeFront[0] = assign1;
	nodeBack[6] = assign3;
	Node* frontNode = nodeFront.front();
	cout << "\nTesting the Front function for a Node Linked List:" << endl;
	cout << "The First Node of the Linked List is:" << endl;
	cout << frontNode->data() << endl << endl;
	Node* backNode = nodeBack.back();
	cout << "Testing the Back function for a Node Linked List:" << endl;
	cout << "The Last Node of the Linked List is:" << endl;
	cout << backNode->data() << endl << endl;


//Test for find function
	cout << "Testing Find function:" << endl;
	DataType* prev_data = NULL;

	DataType* find_data = paramAl.find(assign2, prev_data);

	Node* prev_node = NULL;
	Node* find_node = paramNl.find(dt2, prev_node);
	cout << "Checking to see if Data inside the Array List is Found or Not:" << endl;

	if (find_data != NULL)
	{
		cout << "Data found: " << *find_data << endl << endl;
	}
	else
	{
		cout << "Could not find Data: " << endl << endl;
	}

	cout << "Checking to see if a certain Node inside the Linked List is Found or Not:" << endl;

	if (find_node != NULL)
	{
		cout << "Node found: " << find_node->data() << endl << endl;
	}
	else
	{
		cout << "Could not find Node" << endl << endl;
	}
 
//Test for the insertion functions  
	cout << "Testing Insertion Functions:" << endl;
	cout << "Testing After-Insertion Function:" << endl;

	NodeList nodes;
	ArrayList arraynew(3, assign2);
	arraynew[1] = assign2;
	arraynew[2] = assign3;

	cout << "\nInserting " << assign1 << " into an Array List, after " << arraynew[2] <<endl;
	arraynew.insertAfter(&arraynew[2], assign1);
	cout << arraynew << endl;

	cout << "\nInserting " << assign1 << " into an Array List, before " << arraynew[2] <<endl;
	arraynew.insertBefore(&arraynew[2], assign1);
	cout << arraynew << endl;

	cout << "\nInserting " << assign3 << " into a Linked List, after " << assign1 <<endl;
	cout << "This value is not in the list therefore the data inserted will start the list:" << endl;
	nodes.insertAfter(&assign1, assign3);
	cout << nodes << endl;

	cout << "\nInserting " << assign2 << " into an Array List, before " << assign3 <<endl;
	nodes.insertBefore(&assign3, assign2);
	cout << nodes << endl;

//Test for the operator [] function
	cout << "Testing Operator [] function:" << endl;
	cout << "Printing the 2nd element of the Array List:" << endl;
	cout << array[2] << endl << endl;

	cout << "Printing the 1st element of the Node Linked List:" << endl;
	cout << nodes[1] << endl << endl;


//Test for the Erase function
	cout << "Testing Erase Function" << endl;
	cout << "Erasing " << arraynew[3] << " from a Array List" << endl << endl;
	cout << "Before Erasing: " << endl;
	cout << arraynew << endl;
	cout << "After Erasing: " << endl;
	arraynew.erase(&arraynew[3]);
	cout << arraynew << endl;

	cout << "Erasing " << assign2 << " from a Node Linked List" << endl << endl;
	cout << "Before Erasing: " << endl;
	cout << nodes << endl;
	cout << "After Erasing: " << endl;
	nodes.erase(&assign2);
	cout << nodes << endl;

//Test for the size function    
	cout << "Testing Size function:" << endl;	
	cout << "Node List Size: " << nodes.size() << endl;
	cout << "Array List Size: " << array.size() << endl << endl;


//Test for the Clear and Empty function
	cout << "Testing Clear and Empty function" << endl;
	cout << "Check to see if Array List is Empty:" << endl;
	cout << boolalpha << array.empty() << endl;
	cout << "Check after clearing the Array List:" << endl;
	array.clear();
	cout << boolalpha << array.empty() << endl;


	cout << "Check to see if Linked List is Empty:" << endl;
	cout << boolalpha << nodes.empty() << endl;
	cout << "Check after clearing the Linked List:" << endl;
	nodes.clear();
	cout << boolalpha << nodes.empty() << endl << endl;

//End of Test Driver, Dtor called on all objects created
	cout << "END OF TESTS" << endl << "===============================" << endl;
	array.clear();
	nodes.clear();
	paramAl.clear();
	paramNl.clear();
	copyAl.clear();
	copyNl.clear();
	firstElement.clear();
	nodeFront.clear();
	lastElement.clear();
	nodeBack.clear();
		
	return 0;
}
