#include "Span.hpp"

Span::Span ()
{
    std::cout << GREEN << "Default Constructor called" << DEFAULT << std::endl;
}

Span::~Span()
{
    std::cout << RED << "Default Constructor called" << DEFAULT << std::endl;
}

Span::Span(const Span &other)
{
    std::cout << GREEN << "Copy Constructor called" << DEFAULT << std::endl;
    this->_n = other._n; // this is the explicit copy of the constructor

    // *this = other; // this is the short version of the copy constructor
}

Span &Span ::operator=(const Span &other)
{    
    if (this != &other)
    {
        this->_n = other._n;

        std::cout << GREEN << "Assignment Operator called" << DEFAULT << std::endl;
    }
    return *this;    
    
    // (void)other; // this is the short version of the Assignment constructor
    // return *this;
}

Span::Span(const unsigned int &nbr)
{
    this->_n = nbr;
    std::cout << GREEN << "Parameter Operator called" << DEFAULT << std::endl;
}

void Span::addNumber(const unsigned int &newNbr)
{
    if (completeList.size() < _n) 
    {
        completeList.push_back(newNbr);
    } 
    else 
    {
        throw std::runtime_error("Error: Cannot add more numbers, list is full.");
    }
}

void Span::displayList() const
{
    for (std::list<unsigned int>::const_iterator it = completeList.begin(); it != completeList.end(); it++)
    {
            unsigned int nbrToPrint = *it;
            std::cout << nbrToPrint << std::endl;       
    }
}

unsigned int Span::shortestSpan() const
{
    if (completeList.size() < 2)
    {
        throw std::runtime_error("Error: Cannot calculate the shortest span, list is too short.");
    }

    // copy the list to a new list
    std::list<unsigned int> sortedList = completeList;

    // use the sort function to sort the list. Then we can exact calculate the shortest span between the numbers
    sortedList.sort();

    unsigned int shortestSpan = std::numeric_limits<unsigned int>::max();

    for (std::list<unsigned int>::const_iterator it = sortedList.begin(); it != sortedList.end(); it++)
    {
        // here i get the current number
        unsigned int currentNbr = *it;

        //here i copy the iterator and let him point to the next element in the list
        std::list<unsigned int>::const_iterator nextIt = it;
        nextIt++;

        if (nextIt != sortedList.end())
        {
            unsigned int nextNbr = *nextIt;
            unsigned int currentSpan = nextNbr - currentNbr;
            if (currentSpan < shortestSpan)
            {
                shortestSpan = currentSpan;
            }
        }
    }
    
    return shortestSpan;
}

unsigned int Span::longestSpan() const
{
    if (completeList.size() < 2)
    {
        throw std::runtime_error("Error: list is too short.");
    }

    // copy the list to a new list
    std::list<unsigned int> sortedList = completeList;
    
    // use the sort function to sort the list. Then we can exactly calculate the longest span between the numbers
    sortedList.sort();

    // get the smallest and largest numbers in the sorted list. In this case we have the smalles nr in front and the largest in the back. So it`easy to get them
    unsigned int smallest = sortedList.front();
    unsigned int largest = sortedList.back();

    // calculate the difference between the smallest and largest numbers
    unsigned int longestSpan = largest - smallest;

    return longestSpan;
}


std::ostream &operator<<(std::ostream &out, const Span &span)
{
    out << span;
    return out;
}

// template <typename InputIterator>
// void Span::addNumbers(InputIterator begin, InputIterator end)
// {
//     while (begin != end)
//     {
//         addNumber(*begin);
//         ++begin;
//     }
// }
