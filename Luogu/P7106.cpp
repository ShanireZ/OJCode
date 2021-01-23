#include <iostream>
#include <string>
using namespace std;
char num[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int main()
{
    string str, ans;
    cin >> str;
    ans.append("#");
    for (int i = 1; i <= 6; i++)
    {
        int pos = 0;
        while (num[pos] != str[i])
        {
            pos++;
        }
        ans += num[15 - pos];
    }
    cout << ans;
    return 0;
}