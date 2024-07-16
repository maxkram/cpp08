#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
#include <list>
#include <vector>

#define DEFAULT "\033[0m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Span
{
    private:
        unsigned int _n;
        std::list<unsigned int> completeList;

    public:
        Span();
        ~Span();
        Span(const unsigned int &nbr);
        Span(const Span &other);
        Span &operator=(const Span &other);

    void addNumber(const unsigned int &newNbr);
    void displayList() const;
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end)
    {
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

};

    std::ostream &operator<<(std::ostream &out, const Span &span);  