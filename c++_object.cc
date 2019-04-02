#include <iostream>

using namespace std;


class Base
{
public:
 
    Base(int i) :baseI(i){};

    virtual void print(void){ cout << "调用了虚函数Base::print()"; }

    virtual void setI(){cout<<"调用了虚函数Base::setI()";}

    virtual ~Base(){}
 
private:
 
    int baseI;

};

int main()
{
    cout <<"Base size:"<< sizeof(Base) << endl;

    Base b(100);
    int * vptrAdree = (int *)(&b);  
    cout << "虚函数指针（vprt）的地址是：\t"<<vptrAdree << endl;

    typedef void(*Fun)(void);
    cout << "第一个虚函数的地址是：" << (Fun *)*(int*)(&b) << endl;
    cout << "通过地址，调用虚函数Base::print() " << endl;
    //Fun vfunc = (Fun)*( (Fun *)*(int*)(&b));
    //vfunc();

    return 0;
}
