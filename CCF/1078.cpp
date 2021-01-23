#include <iostream>
#include <cstring>
using namespace std;
int b, min_times = 1000000; //存储最短路径
int floors[201][2];         //存储每一层向上 向下能到达的楼层
int record[201];            //存储本次DFS之前到达过的楼层
void use_elevator(int, int);
void use_judge(int, int);

int main()
{
    int n, a;
    cin >> n >> a >> b;
    if (a == b)
    {
        cout << 0;
        return 0;
    }
    memset(floors, -1, sizeof(floors));
    for (int i = 1; i <= n; i++) //如果能到达，则存储能到达的楼层号，否则则默认为-1
    {
        int num;
        cin >> num;
        if (i + num <= n)
        {
            floors[i][0] = i + num;
        }
        if (i - num >= 1)
        {
            floors[i][1] = i - num;
        }
    }

    use_elevator(a, 1);       //从a层出发，当前是第一次移动
    if (min_times == 1000000) //如果到不了那么这个值就从来没被改变过，就输出-1
    {
        min_times = -1;
    }
    cout << min_times;
    return 0;
}

void use_judge(int num, int times)
{
    for (int i = 1; i < times; i++)
    {
        if (num == record[i]) //如果走到了之前到达过的楼层，则会出现死循环，跳出
        {
            return;
        }
    }
    if (num != -1) //没有循环且到达的楼层存在，则递归实现下一次到达
    {
        use_elevator(num, times + 1);
    }
}

void use_elevator(int start, int times) //从start出发，当前是第times次移动
{
    if (times >= min_times) //如果已经比现有最短路径深了，就停止计算
    {
        return;
    }
    record[times] = start;                              //记录当前楼层
    if (floors[start][0] == b || floors[start][1] == b) //如果向上或向下可直接到达目的地，则跳出并判断是否为最短路径
    {
        min_times = times;
        return;
    }
    use_judge(floors[start][0], times); //向上递归可行性判断
    use_judge(floors[start][1], times); //向下递归可行性判断
}