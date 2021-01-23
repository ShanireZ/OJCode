#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct LongNum
{
    string num;
    LongNum operator+(LongNum x)
    {
        LongNum result;
        int pos_x = x.num.size() - 1; //x最后一位下标
        int pos = num.size() - 1;     //自身最后一位下标
        if (pos > pos_x)              //位数少的数前方补0
        {
            x.num.insert(0, pos - pos_x, '0');
        }
        else
        {
            num.insert(0, pos_x - pos, '0');
            pos = pos_x;
        }
        int ano = 0; //是否进位
        while (pos >= 0)
        {
            int temp;
            temp = (num[pos] - '0') + (x.num[pos] - '0');
            if (ano == 1)
            {
                temp++;
                ano--;
            }
            if (temp >= 10)
            {
                temp -= 10;
                ano = 1;
            }
            result.num.insert(0, 1, temp + '0');
            pos--;
        }
        if (ano == 1)
        {
            result.num.insert(0, "1");
        }
        return result;
    }
};

int main()
{
    int n;
    cin >> n;
    LongNum a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a.num >> b.num;
        c = a + b;
        cout << c.num << endl;
    }
    return 0;
}