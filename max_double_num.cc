#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std; 

int main(int argc, char** argv) 
{
    if (argc < 2) 
    {
        cout << "./a.out 1234...askdfj" << endl;
        return -1;
    }
    char* p_str = argv[1];
    char* p_tmp = NULL;
    string s_num;
    double max_num = 0;
    bool has_point = false;
    bool end_flag = false;
    while(p_str != NULL)
    {
        if (*p_str >= '0' && *p_str <= '9')
        {
            s_num.push_back(*p_str);
        }
        else if ((*p_str == '.' && !has_point && s_num.size() > 0))
        {
            s_num.push_back(*p_str);
            has_point = true;
        }
        else if(s_num.size() > 0)
        {
            //cout << "s_num: "<< s_num.c_str() << endl;
            double tmp_num = strtod(s_num.c_str(), NULL);
            //cout << setiosflags(ios::fixed) << "tmp_num: "<< tmp_num << endl;
            //istringstream iss(s_num);
            //double tmp_num;
            //iss >> tmp_num;
            if (tmp_num > max_num)
            {
                max_num = tmp_num;
            }
            if (p_tmp)
            {
                p_str = p_tmp;
            }
            s_num.clear();
            has_point = false;
            p_tmp = NULL;
            if (*p_str == '\0') break;
            continue;
        }

        if (has_point && p_tmp == NULL && s_num.size() > 0)
        {
            p_tmp = p_str;
        }
        //cout << "s_num: "<< s_num.c_str() << endl;
        if (*p_str == '\0') 
        {
            if (end_flag)
            {
                break;
            }
            end_flag = true;
        }
        else 
        {
            p_str++;
        }
    }
    //cout << "s_num: "<< s_num.c_str() << endl;
    //double tmp_num = strtod(s_num.c_str(), NULL);
    //cout << "tmp_num: "<< tmp_num << endl;
    //istringstream iss(s_num);
    //double tmp_num;
    //iss >> tmp_num;
    //if (tmp_num > max_num)
    //{
    //    max_num = tmp_num;
    //}
    //cout << setiosflags(ios::fixed) << max_num << endl;
    cout << setiosflags(ios::fixed) << atof(argv[1]) << endl;
    
}
