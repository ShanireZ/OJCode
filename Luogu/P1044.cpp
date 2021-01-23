#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int total[20001];
string mult_string(string a, string b)
{
    if (a == "0" || b == "0")
    {
        return "0";
    }
    string result;
    memset(total, 0, sizeof(total));
    for (int i = 0; i <= a.size() - 1; i++)
    {
        int pos_a = a.size() - 1 - i;
        for (int j = 0; j <= b.size() - 1; j++)
        {
            int pos_b = b.size() - 1 - j;
            total[i + j] += (a[pos_a] - '0') * (b[pos_b] - '0');
            if (total[i + j] > 9)
            {
                int next = total[i + j] / 10;
                total[i + j] %= 10;
                total[i + j + 1] += next;
            }
        }
    }
    int pos = a.size() + b.size() - 1;
    if (total[pos] == 0)
    {
        pos--;
    }
    for (int i = pos; i >= 0; i--)
    {
        result += total[i] + '0';
    }
    return result;
}

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
    return result;
}

int main()
{
    int n;
    cin >> n;
    string total1 = "1", total2 = "1";
    for (int i = n + 2; i <= n * 2; i++)
    {
        stringstream tmp_ss;
        tmp_ss << i;
        string tmp_str;
        tmp_ss >> tmp_str;
        total1 = mult_string(total1, tmp_str);
    }
    for (int i = 2; i <= n; i++)
    {
        stringstream tmp_ss;
        tmp_ss << i;
        string tmp_str;
        tmp_ss >> tmp_str;
        total2 = mult_string(total2, tmp_str);
    }
    cout << div_string(total1, total2);
    return 0;
}