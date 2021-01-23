#include <bits/stdc++.h>
using namespace std;

int main()
{
    char trig;
    char pass[9] = {"NOIP@CCF"};
    char word[9];
    int i, judge;
    memset(word,0,sizeof(word));
    cin >> trig;
    while(trig == 'Y')
    {
        cin >> word;
        judge = 1;
        for(i = 0; i < 8; i++)
        {
            if(pass[i] != word[i])
            {
                judge = 0;
                break;
            }
        }
        if(judge)
        {
            cout << "Success";
            return 0;
        }else
        {
            cout << "Sorry" << endl;
        }
        cin >> trig;
    }
    return 0;
}