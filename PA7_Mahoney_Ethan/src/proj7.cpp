/**
 * @brief  CS-202 Project 7 MyString test driver
 * @Author Ethan Mahoney
 *
 * This file is the test driver for the Dynamic Allocation MyString class prescribed in Project 7 of CS-202
 */

#include <iostream>
#include "MyString/MyString.h"

int main() {
 std::cout << "Constructor Tests\n==========================" << std::endl;
 //(1) 
 std::cout << "Testing Default ctor" << std::endl;
 MyString ms_default;

 //(2)
 std::cout << "\nTesting Parametrized ctor" << std::endl;
 MyString ms_parameterized("MyString parametrized constructor!");
 std::cout << ms_parameterized.c_str() << std::endl;

 //(3)
 std::cout << "\nTesting Copy ctor" << std::endl;
 MyString ms_copy(ms_parameterized);
 std::cout << ms_copy.c_str() << std::endl;

 //(4)
 std::cout << "\nTesting Dtor" << std::endl;
 {
   MyString ms_destroy("MyString to be destroyed...");
   std::cout << ms_destroy.c_str() << std::endl;
 }

 //(5),(6)
 std::cout << "\nSize and Length Test\n==========================" << std::endl;
 MyString ms_size_length("Size and length test");
 std::cout << "\nTesting size()" << std::endl;
 std::cout << ms_size_length.size() << std::endl;
 std::cout << "\nTesting length()" << std::endl;
 std::cout << ms_size_length.length() << std::endl;

 //(7)
 std::cout << "\nTesting c_str()" << std::endl;
 MyString ms_toCstring("C-String equivalent successfully obtained!");
 std::cout << ms_toCstring.c_str() << std::endl << std::endl;

 //(8) 
 std::cout << "\nTesting operator==()\n==========================" << std::endl;
 MyString ms_same1("The same"), ms_same2("The same");
 std::cout << "\nComparing '" << ms_same1.c_str() << "' and '" << ms_same2.c_str() << "':" << std::endl;

 if (ms_same1==ms_same2)
  std::cout << "\nSame success\n" << std::endl;

 MyString ms_different("The same (NOT)");
 std::cout << "\nComparing '" << ms_same1.c_str() << "' and '" << ms_different.c_str() << "':" << std::endl;

 if (!(ms_same1==ms_different)) 
  std::cout << "\nDifferent success" << std::endl;

 //(9)
 std::cout << "\nTesting operator=()\n==========================" << std::endl;
 MyString ms_assign("Before assignment");
 std::cout << ms_assign.c_str() << std::endl << std::endl;
 ms_assign = MyString("After performing assignment");
 std::cout << ms_assign.c_str() << std::endl;

 //(10)
 std::cout << "\nTesting operator+\n==========================" << std::endl;
 MyString ms_append1("The first part");
 std::cout << ms_append1.c_str() << std::endl;
 MyString ms_append2(" and the second");
 std::cout << ms_append2.c_str() << std::endl;
 MyString ms_concat = ms_append1+ ms_append2;
 std::cout << ms_concat.c_str() << std::endl;

 //(11)
 std::cout << "\nTesting operator[]()\n==========================" << std::endl;
 MyString ms_access("Access successful (NOT)");
 ms_access[17] = 0;
 std::cout << ms_access.c_str() << std::endl;

 //(12)
 std::cout << "\nTesting operator<<()\n==========================" << std::endl;
 std::cout << ms_access << std::endl;

 std::cout << "End of Tests\n==========================" << std::endl;

return 0;
}
