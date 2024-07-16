#include <iostream>
#include <stack>

#define DEFAULT "\033[0m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

//here we create a template class MutantStack and it inherits from std::stack. So we can use all the functions from stack i.e. push, pop, top, size, empty
template <typename T>
class MutantStack : public std::stack<T>
{

    public:
    MutantStack() : std::stack<T>() {std::cout << GREEN << "Default Constructor called" << DEFAULT << std::endl;}
    ~MutantStack() {std::cout << RED << "Destructor called" << DEFAULT << std::endl;}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {std::cout << GREEN << "Copy Constructor called" << DEFAULT << std::endl;}
    MutantStack &operator = (const MutantStack &other)
{
    if (this != &other)
    {
        std::stack<T>::operator=(other);
    }
    return *this;
}
    
    typedef typename std::stack<T>::container_type::iterator iterator;
	
    // with this function we can iterate through the stack
		iterator begin(void) {
			return (std::stack<T>::c.begin());
		};
		
		iterator end(void) {
			return (std::stack<T>::c.end());
		};

};