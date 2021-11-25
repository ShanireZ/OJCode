#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
struct Data
{
    int year, sx;
};
string sx[15] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
map<string, Data> m;
int main()
{
    int n;
    cin >> n;
    m["Bessie"].year = 2021, m["Bessie"].sx = 0;
    for (int i = 1; i <= n; i++)
    {
        string name1, name2, opt, ani, x;
        cin >> name1 >> x >> x >> opt >> ani >> x >> x >> name2;
        int sx1 = 0;
        while (sx[sx1] != ani)
        {
            sx1++;
        }
        m[name1] = m[name2];
        if (opt == "previous")
        {
            m[name1].year -= 12;
            while (m[name1].sx != sx1)
            {
                m[name1].year++, m[name1].sx++;
                if (m[name1].sx > 11)
                {
                    m[name1].sx = 0;
                }
            }
        }
        else
        {
            m[name1].year += 12;
            while (m[name1].sx != sx1)
            {
                m[name1].year--, m[name1].sx--;
                if (m[name1].sx < 0)
                {
                    m[name1].sx = 11;
                }
            }
        }
    }
    cout << abs(m["Bessie"].year - m["Elsie"].year) << endl;
    return 0;
}