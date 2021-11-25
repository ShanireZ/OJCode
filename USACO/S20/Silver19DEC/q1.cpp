#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
    // freopen("moobuzz.in", "r", stdin);
    // freopen("moobuzz.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ex[8] = {14, 1, 2, 4, 7, 8, 11, 13};
    int n;
    cin >> n;
    //每15个数字中符合条件的只有8个,第一组8个数如上方数组内数字
    //下一组的8个数比上一组大15
    int x = (n - 1) / 8;
    int y = n % 8;
    cout << 15 * x + ex[y];
    return 0;
}