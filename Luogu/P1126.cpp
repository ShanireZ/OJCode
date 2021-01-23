#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;
struct Robot
{
    int x, y, step, towards;
    string info; //map验证信息
};
queue<Robot> way;
map<string, int> map_r;    //减枝验证
int situ[55][55];          //路口是否可通行
int change_to[2] = {1, 3}; //右转 左转 对towards的改变

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) //如果出现了不可移动的块，则对应编号的上一层路口和当前路口无法通过
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
    if (start_towards == 'E') //E0 S1 W2 N3 东西南北
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

    way.push(start_robot); //开始BFS
    while (!way.empty())
    {
        if (way.front().x == end_x && way.front().y == end_y) //已到达目的地，程序结束
        {
            cout << way.front().step;
            return 0;
        }
        way.front().info += ('0' + way.front().x); //制作map验证信息字符串
        way.front().info + '-';
        way.front().info += ('0' + way.front().y);
        way.front().info + '-';
        way.front().info += '0' + way.front().towards;
        if (map_r[way.front().info] == 1) //验证该状态是否出现过，剪枝
        {
            way.pop();
            continue;
        }
        map_r[way.front().info] = 1; //未验证过的，本次加入已验证列表

        int x = way.front().x; //队首位置及朝向
        int y = way.front().y;
        int tow = way.front().towards;
        for (int i = 0; i < 2; i++) //每次共有5种策略，首先进行转向策略2种
        {
            int tmp_tow = (tow + change_to[i]) % 4; //转后方向计算
            Robot tmp_rob;
            tmp_rob.x = x, tmp_rob.y = y, tmp_rob.towards = tmp_tow;
            tmp_rob.step = way.front().step + 1;
            way.push(tmp_rob); //新方案加入队列
        }
        for (int i = 1; i <= 3; i++) //其次进行前进1~3步策略，3种
        {
            int tmp_x = x, tmp_y = y;
            //判断当前及后续是否可行，若走i步都不可行，那么更多步数亦不可行
            if (tow == 0) //不同朝向移动时，坐标改变不同
            {
                if (tmp_y + i >= m || situ[tmp_x][tmp_y + i] == 1) //一旦撞墙，直接break
                {
                    break;
                }
                tmp_y += i; //可行则改变坐标
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
            way.push(tmp_rob); //方案加入队列
        }
        way.pop(); //队首所有后续策略都已判断结束，队首出队
    }
    cout << -1; //无法到达
    return 0;
}