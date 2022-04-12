/*
	洛谷 P2386 CCF 1073
	tag:递归，DFS，枚举
	题意:m个苹果放在n个盘子中，盘子都一样（不管顺序）且允许出现空盘，一共多少种放法
	思路:苹果m个，盘子n个，函数f(m, n)表示m个苹果放在n个盘子中
        若n > m，那么必然会有盘子是空的，最多也就会用到m个盘子，所以f(m, n) = f(m, m)
        再将问题简化为两种情况
        1.如果有盘子是空的
        那么去掉一个盘子也丝毫不会影响分配的方法数，则有f(m, n)若盘子有空余 = f(m, n - 1)
        2.如果没有空盘子
        那么说明全部n个盘子中都至少有一个苹果，这种情况就等同与将剩下的m-n个苹果放入n个盘子中的方法数
        则有f(m, n)若盘子没有空余 = f(m - n, n)
        两种情况合并 f(m, n) = f(m, n -1) + f(m - n, n)
        函数会不断递归，使 m 和 n 都逐渐减小
        当 n == 1 或 m == 0 的时候，触发递归终止条件，此时方案数为1
	坑点:盘子有可能比苹果多！！！有可能只有一个苹果或者没有苹果！！！有可能只有一个盘子！！！
*/

#include <iostream>
using namespace std;

int assign(int m, int n)
{
    if (n == 1 || m <= 1)
    {
        return 1;
    }
    else if (n > m)
    {
        return assign(m, m);
    }
    else
    {
        return assign(m, n - 1) + assign(m - n, n);
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int m, n;
        cin >> m >> n;
        cout << assign(m, n) << endl;
    }
    return 0;
}