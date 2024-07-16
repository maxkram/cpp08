#include "Span.hpp"

int main()
{
//Test 1 with List;
Span sp = Span(5);

sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;


//Test 2 with Vector;
Span sp2 = Span(10000);
std::vector<int> v(10000, 0);
for (int i = 0; i < 10000; i++)
{
    v[i] = i;
}
sp2.addNumbers(v.begin(), v.end());
std::cout << sp2.shortestSpan() << std::endl;
std::cout << sp2.longestSpan() << std::endl;

//Test 3 with List and error because of too many numbers;
    Span Spani(10);

    try
    {
        Spani.addNumber(1);
        Spani.addNumber(2);
        Spani.addNumber(3);
        Spani.addNumber(4);
        Spani.addNumber(5);
        Spani.addNumber(6);
        Spani.addNumber(7);
        Spani.addNumber(8);
        Spani.addNumber(9);
        Spani.addNumber(10);
        Spani.addNumber(11);
        Spani.displayList();
        
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << DEFAULT << '\n';
    }
return 0;
}