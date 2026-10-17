#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
struct NewString
{
    string str; //當前字串
    int step;   //當前操作步數
};
map<string, int> map_s; //驗證表 剪枝用
queue<NewString> judge; //使用轉換策略後儲存新字串的佇列
NewString first, last;  //開始 及 結束 字串
string rule[6][2];      //轉換策略
int nums, trig;         //nums轉換策略個數  trig是否可轉換

void bfs()
{
    judge.push(first); //開始字串加入佇列
    while (!judge.empty())
    {
        if (map_s[judge.front().str] == 1) //驗證當前的隊首是否之前已經出現過，剪枝
        {
            judge.pop();
            continue;
        }
        map_s[judge.front().str] = 1;   //之前未出現過的，本次加入驗證map
        string cur = judge.front().str; //隊首的字串
        for (int i = 0; i < nums; i++)
        {
            int pos = 0;
            pos = cur.find(rule[i][0], pos); //查找規則前段是否出現過
            while (pos != string::npos)      //出現過則使用策略替換，並將替換後的加入佇列
            {
                string tmp_s = cur;
                NewString tmp_ns;
                tmp_ns.str = tmp_s.replace(pos, rule[i][0].size(), rule[i][1]);
                tmp_ns.step = judge.front().step + 1;
                if (tmp_ns.str == last.str) //判斷是否已經到達結束字串
                {
                    cout << tmp_ns.step;
                    trig = 1;
                    return;
                }
                judge.push(tmp_ns);
                pos = cur.find(rule[i][0], pos + 1); //繼續向後查找，是否仍可繼續用當前策略替換
            }
        }
        judge.pop(); //隊首出隊
    }
}

int main()
{
    cin >> first.str >> last.str;                 //讀入開始 及 結束 字串
    while (cin >> rule[nums][0] >> rule[nums][1]) //讀入轉換策略
    {
        nums++; //轉換策略個數
    }
    bfs();
    if (!trig) //如果所有轉換分支都判斷完畢依舊無法到達結束字串，則無法轉換
    {
        cout << "NO ANSWER!";
    }
    return 0;
}