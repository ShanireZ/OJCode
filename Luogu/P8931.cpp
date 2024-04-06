#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int id;
    cin >> id;
    if (id == 1) // int溢出
    {
        cout << "1000000000 1000000000" << endl;
    }
    else if (id == 2) // 二分没规划好起点
    {
        cout << "1" << endl;
        cout << "1 1" << endl;
        cout << "5" << endl;
        cout << "5" << endl;
    }
    else // 多测不清空 亲人两行泪
    {
        cout << "2" << endl;
        cout << "1 1" << endl;
        cout << "1" << endl;
        cout << "2" << endl;
        cout << "1 1" << endl;
        cout << "1" << endl;
        cout << "2" << endl;
    }
    return 0;
}