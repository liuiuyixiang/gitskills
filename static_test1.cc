#include <iostream>
#include "static_test2.h"


int main()
{
    static int a = 100;
    const int b1 = 100;
    const volatile int b2 = 100;
    std::cout << "test 1 a address: " << &a << std::endl;
    std::cout << "test 1 b1 address: " << &b1 << std::endl;
    std::cout << "test 1 b2 address: " << &b2 << std::endl;
    int *p = (int *)&a;
    *p = 1;
    std::cout << "test 1 a value: " << a << std::endl;
    //test1();
    return 0;
}
