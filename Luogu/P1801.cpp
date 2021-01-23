#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int> > up;
priority_queue<int, vector<int>, less<int> > down;
int all[200005];
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> all[i];
    }
    int j = 1;
    //! 对顶堆
    //! 需要注意的是，例如要取第三小的元素，那么下方大顶堆要留2个，第三小的就是上方小顶堆的堆顶
    //! 每次取完后，将小顶堆堆顶挪到下方大顶堆，下方凑齐下次的个数
    //! 这样做才能保证取第n小的元素时，n-1个最小的元素在下方
    //! 如果没有上面的挪动操作，只能保证下方n-1个中是新加入元素中最小的，有可能真正较小的某些元素就被卡在上面了
    //! 每次挪动之后，就自然形成了下次需要的当前最小的n-1个，然后再根据新加入元素进行移动
    for (int i = 1; i <= n; i++)
    {
        int id;
        cin >> id;
        while (j <= id)
        {
            down.push(all[j]);
            j++;
            if (down.size() == i)
            {
                up.push(down.top());
                down.pop();
            }
        }
        cout << up.top() << endl;
        down.push(up.top());
        up.pop();
    }
    return 0;
}