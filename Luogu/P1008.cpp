#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c;
	int nForm[9];
	bool judge;
	
	for(nForm[0] = 1; nForm[0] < 4; nForm[0]++)
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
						b = 2 * a;
						nForm[3] = b / 100;
						nForm[4] = (b / 10) % 10;
						nForm[5] = b % 10;
						c = 3 * a;
						nForm[6] = c / 100;
						nForm[7] = (c / 10) % 10;
						nForm[8] = c % 10;
						if(c > 999)
						{
							judge = false;
						}
						for(int i = 3; i < 9 && judge != false; i++)
						{
							if(nForm[i] == 0)
							{
								judge = false;
							}
						}
						for(int i = 8; i > 2 && judge != false; i--)
						{
							for(int j = 1; i - j >= 0 && judge != false; j++)
							{
								if(nForm[i] == nForm[i-j])
								{
									judge = false;
								}
							}
						}

						if(judge == true)
						{
							printf("%d %d %d\n", a, b, c);
						}
					}
				}
			}
		}
	}
	
	return 0;
}
