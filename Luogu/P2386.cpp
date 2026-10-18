/*
	洛谷 P2386 CCF 1073
	tag:遞歸，DFS，枚舉
	題意:m個蘋果放在n個盤子中，盤子都一樣（不管順序）且允許出現空盤，一共多少種放法
	思路:蘋果m個，盤子n個，函式f(m, n)表示m個蘋果放在n個盤子中
        若n > m，那麼必然會有盤子是空的，最多也就會用到m個盤子，所以f(m, n) = f(m, m)
        再將問題簡化為兩種情況
        1.如果有盤子是空的
        那麼去掉一個盤子也絲毫不會影響分配的方法數，則有f(m, n)若盤子有空餘 = f(m, n - 1)
        2.如果沒有空盤子
        那麼說明全部n個盤子中都至少有一個蘋果，這種情況就等同與將剩下的m-n個蘋果放入n個盤子中的方法數
        則有f(m, n)若盤子沒有空餘 = f(m - n, n)
        兩種情況合併 f(m, n) = f(m, n -1) + f(m - n, n)
        函式會不斷遞歸，使 m 和 n 都逐漸減小
        當 n == 1 或 m == 0 的時候，觸發遞歸終止條件，此時方案數為1
	坑點:盤子有可能比蘋果多！！！有可能只有一個蘋果或者沒有蘋果！！！有可能只有一個盤子！！！
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