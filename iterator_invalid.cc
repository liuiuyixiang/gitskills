#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> vTest;
    for (auto i =0; i < 10; i++)
    {
        vTest.push_back(i);
    }
    vector<int>::iterator itr = vTest.begin();
    itr++;
    cout<< *itr << endl;
    while(vTest.size() > 2)
    {
        itr = vTest.erase(itr);
        cout<< &(*itr) << endl;
    }
    return 0;
}
