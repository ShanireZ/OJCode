#include <iostream>
using namespace std;
int lines[14]; //存储棋盘每行中Queen所在列
int rows[14];  //存储该列之前是否已经有Queen
int n, total;  //total为总情况数

void make(int line) //line为当前行号
{
    if (line > n) //n行放置完成
    {
        total++;        //情况数+1
        if (total <= 3) //若是前3种情况
        {
            for (int i = 1; i <= n; i++)
            {
                cout << lines[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (rows[i] == 1) //检查该列上是否已经有Queen
        {
            continue;
        }
        int trig = 1;
        for (int j = 1; j < line; j++) //检查现在放置的Queen是否在其他Queen的对角线上
        {
            if (lines[j] + (line - j) == i || lines[j] - (line - j) == i)
            {
                trig = 0;
                break;
            }
        }
        if (trig) //若新Queen不与之前列和对角线冲突
        {
            lines[line] = i; //放置Queen
            rows[i] = 1;     //标记杠放置的列
            make(line + 1);  //递归计算下一行
            rows[i] = 0;     //回溯
        }
    }
}

int main()
{
    cin >> n;
    make(1);
    cout << total;
    return 0;
}