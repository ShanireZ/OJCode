#include <iostream>
#include <string>
using namespace std;
string month[15] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
string mon[15] = {"", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        while (s3.size() != 4)
        {
            s3 = "0" + s3;
        }
        for (int i = 1; i <= 12; i++)
        {
            if (s1 == month[i])
            {
                s3 += mon[i];
                break;
            }
        }
        if (s2.size() == 2)
        {
            s2 = "0" + s2;
        }
        s3 += s2.substr(0, 2);
        int ok = 1;
        for (int i = 0; i < 4; i++)
        {
            if (s3[i] != s3[7 - i])
            {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "Y" : "N") << " " << s3 << "\n";
    }
    return 0;
}