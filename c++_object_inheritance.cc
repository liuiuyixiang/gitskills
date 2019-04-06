#include <iostream>
#include <linux/init.h>
#include <linux/module.h>

using namespace std;

class Base
{
public:
 
    Base(int i) :baseI(i){};
    virtual ~Base(){}
 
    int getI(){ return baseI; }
 
    static void countI(){};
 
    virtual void print(void){ cout << "Base::print()"; }
    int baseI;
 
private:
 
 
    static int baseS;
};
class Base_2
{
public:
    Base_2(int i) :base2I(i){};

    virtual ~Base_2(){}

    int getI(){ return base2I; }

    static void countI(){};

    virtual void print(void){ cout << "Base_2::print()"; }
    int base2I;
 
private:
 
 
    static int base2S;
};
 
class Drive_multyBase :public Base, public Base_2
{
public:

    Drive_multyBase(int d) :Base(1000), Base_2(2000) ,Drive_multyBaseI(d){};
 
    virtual void print(void){ cout << "Drive_multyBase::print" ; }
 
    virtual void Drive_print(){ cout << "Drive_multyBase::Drive_print" ; }

	void printAddr(void);
 
private:
    int Drive_multyBaseI;
};

typedef void(*Fun)(void);
 
void Drive_multyBase::printAddr(void)
{
	printk("%pf\n", &Drive_multyBase::print);
}
int main()
{
    Drive_multyBase d(3000);
    //[0]
    cout << "[0]Base::vptr1";
    cout << "\t地址：" << (Fun *)(&d) << endl;

    cout << "Base_1.baseI：" << &d.baseI << endl;
    cout << "Base_2.base2I：" << &d.base2I << endl;
	d.printAddr();
 
	return 0;
}
