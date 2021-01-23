#include <iostream>
#include <string>
using namespace std;
string all[105];
int ways[105][105];
int moves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
string word = "yizhong";
int trig;
int n;
void check(int x, int y, int forward, int wordpos)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        if (all[x][y] == word[wordpos])
        {
            if (wordpos == 6)
            {
                trig = 1;
            }
            else
            {
                check(x + moves[forward][0], y + moves[forward][1], forward, wordpos + 1);
            }
            if (trig)
            {
                ways[x][y] = 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> all[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (all[i][j] == 'y')
            {
                for (int k = 0; k < 8; k++)
                {
                    trig = 0;
                    check(i + moves[k][0], j + moves[k][1], k, 1);
                    if (trig)
                    {
                        ways[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ways[i][j])
            {
                cout << all[i][j];
            }
            else
            {
                cout << '*';
            }
        }
        cout << endl;
    }
    return 0;
}