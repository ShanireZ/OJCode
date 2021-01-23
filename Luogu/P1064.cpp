#include <iostream>
#include <algorithm>
using namespace std;
struct Item
{
    int v, p, q;
    int total;
};
Item items[65];
int child[65][3]; //0存附件个数，i存i号附件编号，
int check[32005];
int main()
{
    int cash, m;
    cin >> cash >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> items[i].v >> items[i].p >> items[i].q;
        if (items[i].q > 0)
        {
            child[items[i].q][0]++;
            child[items[i].q][child[items[i].q][0]] = i;
        }
        items[i].total = items[i].v * items[i].p;
    }
    for (int i = 1; i <= m; i++)
    {
        if (items[i].q == 0 && cash >= items[i].v) //只看主件
        {
            for (int j = cash; j >= items[i].v; j--)
            {
                check[j] = max(check[j], check[j - items[i].v] + items[i].total); //只买主件
                if (child[i][0] > 0 && j >= items[i].v + items[child[i][1]].v)    //买主件和1号附件
                {
                    check[j] = max(check[j], check[j - items[i].v - items[child[i][1]].v] + items[i].total + items[child[i][1]].total);
                }
                if (child[i][0] > 1)
                {
                    if (j >= items[i].v + items[child[i][2]].v) //买主件和二号附件
                    {
                        check[j] = max(check[j], check[j - items[i].v - items[child[i][2]].v] + items[i].total + items[child[i][2]].total);
                    }
                    if (j >= items[i].v + items[child[i][1]].v + items[child[i][2]].v) //买主件和所有附件
                    {
                        check[j] = max(check[j], check[j - items[i].v - items[child[i][1]].v - items[child[i][2]].v] + items[i].total + items[child[i][1]].total + items[child[i][2]].total);
                    }
                }
            }
        }
    }
    cout << check[cash];
    return 0;
}