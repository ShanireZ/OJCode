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

bool cmp(string a, string b)
{
    if (a == b)
    {
        return true;
    }
    if (a.size() != b.size())
    {
        return a.size() > b.size();
    }
    else
    {
        int pos = 0;
        while (a[pos] == b[pos])
        {
            pos++;
        }
        return a[pos] > b[pos];
    }
}

string div_string(string a, string b)
{
    string result;
    if (!cmp(a, b)) //a较小
    {
        result = a;
        result.insert(0, "0 ");
    }
    else
    {
        int start = b.size();
        string temp = a.substr(0, start); //复制首次被除数部分
        for (int i = 0; i <= a.size() - b.size(); i++)
        {
            if (cmp(temp, b)) //可被除
            {
                int count = 0;
                bool trig = 1;
                while (trig)
                {
                    temp = reduce_string(temp, b);
                    count++;
                    trig = cmp(temp, b);
                }
                result += ('0' + count);
            }
            else if (i != 0) //不可被除且不是首位
            {
                result += '0';
            }
            if (start < a.size())
            {             
                if (temp[0] == '0') //余数为0则清除
                {
                    temp.erase(0, 1);
                }
                temp += a.substr(start++, 1);
            }
        }
        result += ' ' + temp;
    }
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << div_string(a, b) << endl;
    return 0;
}