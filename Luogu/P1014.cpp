#include <iostream>
using namespace std;
int main()
{
	int n, i, a, b;
	cin >> n;
	
	for(i = 1; n - i > 0; i++)
	{
		n = n - i;
	}
	
	if(i % 2 == 0)
	{
		//偶数 从上至下	 上加下减 
		a = n;
		b = i - n + 1;
	}else
	{
		//奇数 从下至上  上减下加 
		a = i - n + 1;
		b = n;
	}
	cout << a << "/" << b;
	return 0;
}
