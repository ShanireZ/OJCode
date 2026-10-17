#include <iostream>
using namespace std;
int main()
{
    int n, zg = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int cj;    //! 1.建立變數儲存當前人的成績
        cin >> cj; //! 2.輸出當前人的成績進變數裡
        if (cj > zg) //! 3.判斷新分數是否比之前的最高分還要高--->更新/不更新
        {
            zg = cj;
        }
    }
    cout << zg << endl;
    return 0;
}