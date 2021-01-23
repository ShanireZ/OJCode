#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
struct NewString
{
    string str; //当前字符串
    int step;   //当前操作步数
};
map<string, int> map_s; //验证表 剪枝用
queue<NewString> judge; //使用转换策略后存储新字符串的队列
NewString first, last;  //开始 及 结束 字符串
string rule[6][2];      //转换策略
int nums, trig;         //nums转换策略个数  trig是否可转换

void bfs()
{
    judge.push(first); //开始字符串加入队列
    while (!judge.empty())
    {
        if (map_s[judge.front().str] == 1) //验证当前的队首是否之前已经出现过，剪枝
        {
            judge.pop();
            continue;
        }
        map_s[judge.front().str] = 1;   //之前未出现过的，本次加入验证map
        string cur = judge.front().str; //队首的字符串
        for (int i = 0; i < nums; i++)
        {
            int pos = 0;
            pos = cur.find(rule[i][0], pos); //查找规则前段是否出现过
            while (pos != string::npos)      //出现过则使用策略替换，并将替换后的加入队列
            {
                string tmp_s = cur;
                NewString tmp_ns;
                tmp_ns.str = tmp_s.replace(pos, rule[i][0].size(), rule[i][1]);
                tmp_ns.step = judge.front().step + 1;
                if (tmp_ns.str == last.str) //判断是否已经到达结束字符串
                {
                    cout << tmp_ns.step;
                    trig = 1;
                    return;
                }
                judge.push(tmp_ns);
                pos = cur.find(rule[i][0], pos + 1); //继续向后查找，是否仍可继续用当前策略替换
            }
        }
        judge.pop(); //队首出队
    }
}

int main()
{
    cin >> first.str >> last.str;                 //读入开始 及 结束 字符串
    while (cin >> rule[nums][0] >> rule[nums][1]) //读入转换策略
    {
        nums++; //转换策略个数
    }
    bfs();
    if (!trig) //如果所有转换分支都判断完毕依旧无法到达结束字符串，则无法转换
    {
        cout << "NO ANSWER!";
    }
    return 0;
}