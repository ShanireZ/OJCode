#include <iostream>
#include <string>
using namespace std;
string dfs(int t) //当前re内容重复t次
{
    char ch;
    string re;
    while (cin >> ch) //记录re的内容 遇到]或无内容时停止 并开始重复
    {
        if (ch == '[') //遇到压缩 需要解压
        {
            int n; //压缩内容重复次数
            cin >> n;
            re.append(dfs(n)); //将压缩内容重复n次 并加入re中
        }
        else if (ch == ']') //压缩区域结束 开始重复
        {
            break;
        }
        else //其他字符正常加入
        {
            re.append(1, ch);
        }
    }
    string ans;
    for (int i = 1; i <= t; i++) //开始重复
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