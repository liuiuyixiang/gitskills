#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class CatalanNumber
{
    public:
        CatalanNumber();
        int recordAllStr(string tmp_str, int left, int right);
        void printAllRecord();
    private:
        vector<string> record;
        int record_num;
};

CatalanNumber::CatalanNumber()
{
    this->record_num = 0;
}
int CatalanNumber::recordAllStr(string tmp_str, int left, int right)
{
    if (right <= 0)
    {
        //this->record.push_back(tmp_str);
        this->record_num++;
        return 0;
    }

    if (left > 0)
    {
        recordAllStr(tmp_str + '(', left-1, right);
    }
    if (right > left)
    {
        recordAllStr(tmp_str + ')', left, right-1);
    }
    return 0;
}
void CatalanNumber::printAllRecord()
{
    //for (auto i : this->record)
    //{
    //    cout << i << endl;   
    //}
    cout << this->record_num << endl;
}
int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        cout << "./a.out 4" << endl;
        return -1;
    }

    int n = atoi(argv[1]);
    CatalanNumber a;
    string tmp_str;
    a.recordAllStr(tmp_str, n, n);
    a.printAllRecord();
    return 0;
}
