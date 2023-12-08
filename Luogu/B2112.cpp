#include <algorithm>
#include <iostream>
using namespace std;
string s1, s2;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) //! 每次一轮游戏
    {
        cin >> s1 >> s2;
        if (s1 == s2)
        {
            cout << "Tie" << endl;
        }
        else if ((s1 == "Rock" && s2 == "Scissors") ||
                 (s1 == "Scissors" && s2 == "Paper") ||
                 (s1 == "Paper" && s2 == "Rock"))
        {
            cout << "Player1" << endl;
        }
        else
        {
            cout << "Player2" << endl;
        }
    }
    return 0;
}