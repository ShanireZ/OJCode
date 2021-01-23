#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    int x, y, z;
    cin >> x >> y >> z;
    int nForm[9];
    bool judge;
    int total = 0;
    
    for(nForm[0] = 1; nForm[0] < 10; nForm[0]++)
    {
        for(nForm[1] = 1; nForm[1] < 10; nForm[1]++)
        {
            if(nForm[1] != nForm[0])
            {
                for(nForm[2] = 1; nForm[2] < 10; nForm[2]++)
                {
                    if(nForm[2] != nForm[1] && nForm[2] != nForm[0])
                    {
                        judge = true;
                        a = nForm[0] * 100 + nForm[1] * 10 + nForm[2];
                        b = y * a / x;
                        nForm[3] = b / 100;
                        nForm[4] = (b / 10) % 10;
                        nForm[5] = b % 10;
                        c = z * a / x;
                        nForm[6] = c / 100;
                        nForm[7] = (c / 10) % 10;
                        nForm[8] = c % 10;
                        if(c > 999)
                        {
                            judge = false;
                        }
                        for(int i = 3; i < 9; i++)
                        {
                            if(nForm[i] == 0)
                            {
                                judge = false;
                            }
                        }
                        for(int i = 8; i > 2; i--)
                        {
                            for(int j = 1; i - j >= 0; j++)
                            {
                                if(nForm[i] == nForm[i-j])
                                {
                                    judge = false;
                                }
                            }
                        }

                        if(judge == true)
                        {
                            cout << a << " " << b << " " << c << endl;
                            total++;
                        }
                    }
                }
            }
        }
    }
    
    if(total == 0)
    {
    	cout << "No!!!" << endl;
	}
	
    return 0;
}
