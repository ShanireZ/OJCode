#include <iostream>
#include <string>
using namespace std;
string dfs(int t) //當前re內容重複t次
{
    char ch;
    string re;
    while (cin >> ch) //記錄re的內容 遇到]或無內容時停止 並開始重複
    {
        if (ch == '[') //遇到壓縮 需要解壓
        {
            int n; //壓縮內容重複次數
            cin >> n;
            re.append(dfs(n)); //將壓縮內容重複n次 並加入re中
        }
        else if (ch == ']') //壓縮區域結束 開始重複
        {
            break;
        }
        else //其他字元正常加入
        {
            re.append(1, ch);
        }
    }
    string ans;
    for (int i = 1; i <= t; i++) //開始重複
    {
        ans.append(re);
    }
    return ans;
}
int main()
{
    cout << dfs(1);
    return 0;
}