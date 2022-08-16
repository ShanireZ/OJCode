#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int de[100005];
int in[100005];
int main()
{
    int high, pos_de = 1, pos_in = 1;
    cin >> high;
    de[pos_de] = high, in[pos_in] = high;
    while (cin >> high)
    {
        if (high > de[pos_de]) //最长非升序列
        {
            int next = pos_de - 1;
            while (next >= 1 && high > de[next])
            {
                next--;
            }
            de[++next] = high;
        }
        else
        {
            de[++pos_de] = high;
        }
        if (high < in[pos_in]) //最长上升序列
        {
            int next = pos_in;
            while (next >= 1 && high < in[next])
            {
                next--;
            }
            if (high == in[next])
            {
                continue;
            }
            in[++next] = high;
        }
        else if (high > in[pos_in])
        {
            in[++pos_in] = high;
        }
    }
    cout << pos_de << endl
         << pos_in;
    return 0;
}