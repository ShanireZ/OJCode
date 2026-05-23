#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
struct Cow
{
    int h, pos;
};
stack<Cow> s;
long long n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int h;
        cin >> h;
        while (s.size() && s.top().h <= h)
        {
            ans += i - s.top().pos + 1;
            s.pop();
        }
        if (s.size())
        {
            ans += i - s.top().pos + 1;
        }
        s.push(Cow{h, i});
    }
    cout << ans << endl;
    return 0;
}