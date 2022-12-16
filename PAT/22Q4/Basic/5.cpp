#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        q.push(x);
    }
    int tot = 0, now = 0;
    for (int i = 1; i <= n; i++)
    {
        while (q.front() != i)
        {
            now++, tot += q.size();
            q.push(q.front()), q.pop();
        }
        now++, tot += q.size();
        q.pop();
    }
    printf("%d %.1f\n", now, tot * 1.0 / n);
    return 0;
}