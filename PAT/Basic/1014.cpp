#include <iostream>
#include <string>
using namespace std;
string s1, s2, s3, s4;
string xq[10] = {"", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    cin >> s1 >> s2 >> s3 >> s4;
    int sz = min(s1.size(), s2.size()), trig = 0;
    for (int i = 0; i < sz; i++)
    {
        if (trig == 0 && s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
        {
            cout << xq[s1[i] - 'A' + 1] << " ";
            trig++;
        }
        else if (trig == 1 && s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'N')
        {
            cout << s1[i] - 'A' + 10 << ":";
            trig++;
        }
        else if (trig == 1 && s1[i] == s2[i] && s1[i] >= '0' && s1[i] <= '9')
        {
            cout << "0" << s1[i] << ":";
            trig++;
        }
    }
    sz = min(s3.size(), s4.size());
    for (int i = 0; i < sz; i++)
    {
        if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z')))
        {
            if (i < 10)
            {
                cout << "0";
            }
            cout << i;
            break;
        }
    }
    return 0;
}