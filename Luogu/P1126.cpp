#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;
struct Robot
{
    int x, y, step, towards;
    string info; //map驗證資訊
};
queue<Robot> way;
map<string, int> map_r;    //減枝驗證
int situ[55][55];          //路口是否可通行
int change_to[2] = {1, 3}; //右轉 左轉 對towards的改變

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) //如果出現了不可移動的塊，則對應編號的上一層路口和當前路口無法通過
    {
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
            {
                situ[i - 1][j] = 1;
                situ[i - 1][j - 1] = 1;
                situ[i][j - 1] = 1;
                situ[i][j] = 1;
            }
        }
    }
    int end_x, end_y;
    char start_towards;
    Robot start_robot;
    start_robot.step = 0;
    cin >> start_robot.x >> start_robot.y >> end_x >> end_y;
    cin >> start_towards;
    if (start_towards == 'E') //E0 S1 W2 N3 東西南北
    {
        start_robot.towards = 0;
    }
    else if (start_towards == 'S')
    {
        start_robot.towards = 1;
    }
    else if (start_towards == 'W')
    {
        start_robot.towards = 2;
    }
    else
    {
        start_robot.towards = 3;
    }

    way.push(start_robot); //開始BFS
    while (!way.empty())
    {
        if (way.front().x == end_x && way.front().y == end_y) //已到達目的地，程式結束
        {
            cout << way.front().step;
            return 0;
        }
        way.front().info += ('0' + way.front().x); //製作map驗證資訊字串
        way.front().info + '-';
        way.front().info += ('0' + way.front().y);
        way.front().info + '-';
        way.front().info += '0' + way.front().towards;
        if (map_r[way.front().info] == 1) //驗證該狀態是否出現過，剪枝
        {
            way.pop();
            continue;
        }
        map_r[way.front().info] = 1; //未驗證過的，本次加入已驗證列表

        int x = way.front().x; //隊首位置及朝向
        int y = way.front().y;
        int tow = way.front().towards;
        for (int i = 0; i < 2; i++) //每次共有5種策略，首先進行轉向策略2種
        {
            int tmp_tow = (tow + change_to[i]) % 4; //轉後方向計算
            Robot tmp_rob;
            tmp_rob.x = x, tmp_rob.y = y, tmp_rob.towards = tmp_tow;
            tmp_rob.step = way.front().step + 1;
            way.push(tmp_rob); //新方案加入佇列
        }
        for (int i = 1; i <= 3; i++) //其次進行前進1~3步策略，3種
        {
            int tmp_x = x, tmp_y = y;
            //判斷當前及後續是否可行，若走i步都不可行，那麼更多步數亦不可行
            if (tow == 0) //不同朝向移動時，座標改變不同
            {
                if (tmp_y + i >= m || situ[tmp_x][tmp_y + i] == 1) //一旦撞牆，直接break
                {
                    break;
                }
                tmp_y += i; //可行則改變座標
            }
            else if (tow == 1)
            {
                if (tmp_x + i >= n || situ[tmp_x + i][tmp_y] == 1)
                {
                    break;
                }
                tmp_x += i;
            }
            else if (tow == 2)
            {
                if (tmp_y - i < 1 || situ[tmp_x][tmp_y - i] == 1)
                {
                    break;
                }
                tmp_y -= i;
            }
            else
            {
                if (tmp_x - i < 1 || situ[tmp_x - i][tmp_y] == 1)
                {
                    break;
                }
                tmp_x -= i;
            }
            Robot tmp_rob;
            tmp_rob.x = tmp_x, tmp_rob.y = tmp_y, tmp_rob.towards = tow;
            tmp_rob.step = way.front().step + 1;
            way.push(tmp_rob); //方案加入佇列
        }
        way.pop(); //隊首所有後續策略都已判斷結束，隊首出隊
    }
    cout << -1; //無法到達
    return 0;
}