#include <iostream>
#include <string>
using namespace std;
int s21[5000][2];
int s11[5000][2];
int main()
{
    string str;
    int p21 = 0, p11 = 0, trig = 0;
    while (true)
    {
        cin >> str;
        int n = str.size();
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'W')
            {
                s21[p21][0]++;
                if (s21[p21][0] >= 21 && s21[p21][0] - s21[p21][1] >= 2)
                {
                    p21++;
                }
                s11[p11][0]++;
                if (s11[p11][0] >= 11 && s11[p11][0] - s11[p11][1] >= 2)
                {
                    p11++;
                }
            }
            else if (str[i] == 'L')
            {
                s21[p21][1]++;
                if (s21[p21][1] >= 21 && s21[p21][1] - s21[p21][0] >= 2)
                {
                    p21++;
                }
                s11[p11][1]++;
                if (s11[p11][1] >= 11 && s11[p11][1] - s11[p11][0] >= 2)
                {
                    p11++;
                }
            }
            else if (str[i] == 'E')
            {
                trig = 1;
                break;
            }
        }
        if (trig)
        {
            break;
        }
    }
    for (int i = 0; i <= p11; i++)
    {
        cout << s11[i][0] << ":" << s11[i][1] << endl;
    }
    cout << endl;
    for (int i = 0; i <= p21; i++)
    {
        cout << s21[i][0] << ":" << s21[i][1] << endl;
    }
    return 0;
}