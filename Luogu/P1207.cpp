#include <iostream>
#include <string>
using namespace std;
char part[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

bool check(string str)
{
    int n = str.size();
    int trig = 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - 1 - i])
        {
            trig = 0;
            break;
        }
    }
    return trig;
}

string change(int num, int b)
{
    string str;
    while (num)
    {
        str.insert(0, 1, part[num % b]);
        num /= b;
    }
    return str;
}

int main()
{
    int n, s;
    cin >> n >> s;
    int cnt = 0;
    while (s++)
    {
        int kind = 0;
        string num;
        for (int i = 2; i <= 10; i++)
        {
            num = change(s, i);
            if (check(num))
            {
                kind++;
            }
            if (kind == 2)
            {
                cnt++;
                cout << s << endl;
                break;
            }
        }
        if (cnt == n)
        {
            return 0;
        }
    }
}