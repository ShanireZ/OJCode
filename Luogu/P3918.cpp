#include <iostream>
#include <algorithm>
using namespace std;
int s[305];
bool cmp(int a, int b)
{
    return a > b;
}
//特技放兩頭和連著放收益一樣，但放兩頭不耽誤中間收益
//這樣內層繼續放其他的可加大收益，以此類推
//每次距離減少2
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> s[i];
    }
    sort(s + 1, s + 1 + k, cmp);
    int tot = 0;
    int dis = n - 1;
    for (int i = 1; i <= n / 2; i++)
    {
        tot += s[i] * dis;
        dis -= 2;
    }
    cout << tot;
    return 0;
}