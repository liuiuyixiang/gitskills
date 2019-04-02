#include <iostream>

extern const int a;


void test1()
{
    std::cout << "a value: " << a << std::endl;
    std::cout << "a address: " << &a << std::endl;
    int *p = (int *)&a;
    *p = a + 1;
    std::cout << a << std::endl;
}
