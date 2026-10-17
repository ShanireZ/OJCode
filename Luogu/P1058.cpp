#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int all[55][55];
string pic[500];
int main()
{
    //每個正方形的每行 從下至上
    string block[6] = {"+---+", "|   |/", "|   | +", "+---+ |", "/   /|", "+---+"};
    int m, n, high = 0;     //最高
    int maxX = 0, maxY = 0; //圖形高度和寬度
    cin >> m >> n;
    for (int i = m - 1; i >= 0; i--) //從上至下讀入
    {
        for (int j = 0; j < n; j++)
        {
            cin >> all[i][j];
            high = max(high, all[i][j]);
        }
    }
    for (int i = 0; i < 500; i++) //先填滿.
    {
        pic[i].append(500, '.');
    }
    //從最上行開始逐列逐個高度生成方塊 後續的可直接替換之前的圖形
    for (int i = m - 1; i >= 0; i--) //從最上一行開始
    {
        for (int j = 0; j < n; j++) //逐列
        {
            for (int k = 0; k < high; k++) //逐個高度
            {
                int tmpX = i * 2 + k * 3; //該行列高的起始X座標
                int tmpY = j * 4 + i * 2; //該行列高的起始Y座標
                if (all[i][j] > k)        //如果需要加一個塊 那就用塊替換之前的圖形
                {
                    for (int x = 0; x < 6; x++)
                    {
                        if (x == 0)
                        {
                            pic[tmpX + x].replace(tmpY, 5, block[x]);
                        }
                        else if (x == 1)
                        {
                            pic[tmpX + x].replace(tmpY, 6, block[x]);
                        }
                        else if (x == 2 || x == 3)
                        {
                            pic[tmpX + x].replace(tmpY, 7, block[x]);
                        }
                        else if (x == 4)
                        {
                            pic[tmpX + x].replace(tmpY + 1, 6, block[x]);
                        }
                        else
                        {
                            pic[tmpX + x].replace(tmpY + 2, 5, block[x]);
                        }
                    }
                    //尋找最終圖形的邊界
                    maxX = max(tmpX + 5, maxX);
                    maxY = max(tmpY + 6, maxY);
                }
            }
        }
    }
    for (int i = maxX; i >= 0; i--)
    {
        cout << pic[i].substr(0, maxY + 1) << endl;
    }
    return 0;
}