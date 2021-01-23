#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reduce_string(string a, string b)
{
    string result;
    int pos_a = a.size() - 1;        //a最后一位下标
    int pos_b = b.size() - 1;        //b最后一位下标
    int pos = pos_a;                 //取较长字符串对齐
    b.insert(0, pos_a - pos_b, '0'); //b前方补0
    bool next = false;               //是否借位
    while (pos >= 0)
    {
        int temp;
        temp = (a[pos] - '0') - (b[pos] - '0');
        if (next == true)
        {
            temp--;
            next = false;
        }
        if (temp < 0)
        {
            temp += 10;
            next = true;
        }
        result.insert(0, 1, temp + '0');
        pos--;
    }
    pos = 0;
    while (result[pos] == '0' && pos < pos_a) //前侧去0且如果是0最后的0保留
    {
        pos++;
    }
    result.erase(0, pos);
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << reduce_string(a, b) << endl;
    return 0;
}