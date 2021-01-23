#include <iostream>
#include <algorithm>
using namespace std;
struct Player
{
    int id, score, power;
};
Player players[200005];
Player win[100005], lose[100005];

bool cmp(Player a, Player b)
{
    if (a.score == b.score)
    {
        return a.id < b.id;
    }
    return a.score > b.score;
}
int main()
{
    int n, r, q;
    cin >> n >> r >> q;
    for (int i = 0; i < 2 * n; i++) //读入
    {
        cin >> players[i].score;
    }
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> players[i].power;
        players[i].id = i + 1;
    }
    sort(players, players + 2 * n, cmp); //初始积分排序
    for (int turn = 0; turn < r; turn++) //r轮比赛
    {
        int pos_win = 0, pos_lose = 0;
        for (int i = 0; i < 2 * n; i += 2) //比较输赢并加分
        {
            if (players[i].power > players[i + 1].power)
            {
                players[i].score++;
                win[pos_win++] = players[i];
                lose[pos_lose++] = players[i + 1];
            }
            else
            {
                players[i + 1].score++;
                win[pos_win++] = players[i + 1];
                lose[pos_lose++] = players[i];
            }
        }
        int i = 0, j = 0, pos = 0; //归并排序
        while (i < n && j < n)
        {
            if (win[i].score > lose[j].score ||
                (win[i].score == lose[j].score && win[i].id < lose[j].id))
            {
                players[pos++] = win[i++];
            }
            else
            {
                players[pos++] = lose[j++];
            }
        }
        while (i < n)
        {
            players[pos++] = win[i++];
        }
        while (j < n)
        {
            players[pos++] = lose[j++];
        }
    }
    cout << players[q - 1].id;
    return 0;
}