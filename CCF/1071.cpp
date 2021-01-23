/*
    数列从0开始，每150个一次循环，所以把k和150取余即可
    把没有规律的提前进行初始化
    记忆化搜索加快运算效率，避免重复运算
    和的余数 = 余数的和的余数
*/
#include <iostream>
#include <cstring>
using namespace std;
int pell_mod[150];

int pell(int a)
{
    if (pell_mod[a] == -1)
    {
        pell_mod[a] = (pell(a - 1) * 2 + pell(a - 2)) % 32767;
    }
    return pell_mod[a];
}

int main()
{
    memset(pell_mod, -1, sizeof(pell_mod));
    pell_mod[0] = 0, pell_mod[1] = 1, pell_mod[2] = 2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        k %= 150;
        cout << pell(k) << endl;
    }
    return 0;
}