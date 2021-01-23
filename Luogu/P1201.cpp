#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string names[n];
    int cash[n];
    memset(cash, 0, sizeof(cash));
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }
    for (int i = 0; i < n; i++)
    {
        string sender;
        cin >> sender;
        int sender_pos;
        for (int j = 0; j < n; j++)
        {
            if (names[j] == sender)
            {
                sender_pos = j;
                break;
            }
        }
        int all_cash, num_rec, per_cash;
        cin >> all_cash >> num_rec;
        if (num_rec == 0)
        {
            continue;
        }
        per_cash = all_cash / num_rec;
        cash[sender_pos] -= per_cash * num_rec;
        for (int j = 0; j < num_rec; j++)
        {
            string rec;
            cin >> rec;
            int rec_pos;
            for (int k = 0; k < n; k++)
            {
                if (names[k] == rec)
                {
                    rec_pos = k;
                    break;
                }
            }
            cash[rec_pos] += per_cash;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << names[i] << " " << cash[i] << endl;
    }
    return 0;
}