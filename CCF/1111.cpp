#include <iostream>
#include <algorithm>
using namespace std;
long long q[1000005];
int main()
{
    int a, n;
    while (cin >> a >> n)
    {
        q[0] = a;
        int pos2 = 0, pos3 = 0;
        int rear = 1;
        while (rear < n)
        {
            long long tmp2 = q[pos2] * 2 + 1;
            long long tmp3 = q[pos3] * 3 + 1;
            long long tmp = min(tmp2, tmp3);
            if (tmp2 < tmp3)
            {
                pos2++;
            }
            else
            {
                pos3++;
            }
            if (tmp != q[rear - 1])
            {
                q[rear++] = tmp;
            }
        }
        cout << q[n - 1] << endl;
    }
    return 0;
}