#include <iostream>
#include <algorithm>
using namespace std;
int ranks[200005], score[200005], power[200005]; //ranks存储每一名编号 score存储编号i的分数 power存储编号i的实力
int win[100005], lose[100005];                   //胜者组 败者组 每一轮结束后胜者组和败者组都是有序的,因为他们是
                                                 //按照从高分到低分的顺序比赛，先比赛的分数肯定高
bool cmp(int a, int b)
{
    if (score[a] == score[b])
    {
        return a < b;
    }
    return score[a] > score[b];
}
int main()
{
    int n, r, q;
    cin >> n >> r >> q;
    for (int i = 1; i <= 2 * n; i++) //读入
    {
        cin >> score[i];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> power[i];
        ranks[i] = i;
    }
    sort(ranks + 1, ranks + 1 + 2 * n, cmp); //初始积分排序
    for (int turn = 0; turn < r; turn++)     //r轮比赛
    {
        int pos_win = 1, pos_lose = 1;
        for (int i = 1; i <= 2 * n; i += 2) //比较输赢并加分
        {
            if (power[ranks[i]] > power[ranks[i + 1]])
            {
                score[ranks[i]]++;
                win[pos_win++] = ranks[i];
                lose[pos_lose++] = ranks[i + 1];
            }
            else
            {
                score[ranks[i + 1]]++;
                win[pos_win++] = ranks[i + 1];
                lose[pos_lose++] = ranks[i];
            }
        }
        int i = 1, j = 1, pos = 1; //归并排序
        while (i <= n && j <= n)
        {
            if (score[win[i]] > score[lose[j]] || (score[win[i]] == score[lose[j]] && win[i] < lose[j]))
            {
                ranks[pos++] = win[i++];
            }
            else
            {
                ranks[pos++] = lose[j++];
            }
        }
        while (i <= n)
        {
            ranks[pos++] = win[i++];
        }
        while (j <= n)
        {
            ranks[pos++] = lose[j++];
        }
    }
    cout << ranks[q];
    return 0;
}