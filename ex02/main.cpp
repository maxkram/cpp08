#include "MutantStack.hpp"

int main()
{
MutantStack<int> mstack;

mstack.push(5);
mstack.push(17);

// here we print the top element of the stack
std::cout << mstack.top() << std::endl;

// here we pop out the top element of the stack
mstack.pop();

// here we print the size of the stack
std::cout << mstack.size() << std::endl;

// here we push 3 elements to the stack
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);

// here we create an iterator and iterate through the stack
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();

// here we print the elements of the stack
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}

// here we create a copy of the stack
std::stack<int> s(mstack);
return 0;
}