#include <iostream>

using namespace std;
int main()
{
    const int a = 10;
    int *p = (int *)&a;
    *p = 20;
    std::cout << "a: " << a  << endl;
    std::cout << "*p: "<< *p << endl;

    return 0;
}