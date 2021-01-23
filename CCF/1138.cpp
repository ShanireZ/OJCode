#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string plus_string(string a, string b)
{
    string result;
    int pos_a = a.size() - 1;    //a最后一位下标
    int pos_b = b.size() - 1;    //b最后一位下标
    int pos = max(pos_a, pos_b); //取较长字符串对齐
    if (pos_a > pos_b)           //位数少的数前方补0
    {
        b.insert(0, pos_a - pos_b, '0');
    }
    else
    {
        a.insert(0, pos_b - pos_a, '0');
    }
    bool next = false; //是否进位
    while (pos >= 0)
    {
        int temp;
        temp = (a[pos] - '0') + (b[pos] - '0');
        if (next == true)
        {
            temp++;
            next = false;
        }
        if (temp >= 10)
        {
            temp -= 10;
            next = true;
        }
        result.insert(0, 1, temp + '0');
        pos--;
    }
    if (next == 1)
    {
        result.insert(0, "1");
    }
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << plus_string(a, b) << endl;
    return 0;
}