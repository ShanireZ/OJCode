#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    // freopen("whereami.in", "r", stdin);
    // freopen("whereami.out", "w", stdout);
    // ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string way;
    cin >> way;
    for (int i = 1; i <= n; i++) //!长度
    {
        int trig = 1;
        for (int j = 0; j + i <= n; j++) //!从哪开始截取i长度的字符串
        {
            string chk = way.substr(j, i);
            if (j + 1 >= n)
            {
                break;
            }
            if (way.find(chk, j + 1) != string::npos) //!出现重复
            {
                trig = 0;
                break;
            }
        }
        if (trig)
        {
            cout << i;
            break;
        }
    }
    return 0;
}