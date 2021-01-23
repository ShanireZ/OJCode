#include <iostream>
#include <string>
using namespace std;
string ans;
int n;
void move(int f1, int f2, int t1, int t2, int step)
{
	swap(ans[f1], ans[t1]);
	swap(ans[f2], ans[t2]);
	cout << ans.substr(1) << endl;
	if (step == 2 * n - 3)
	{
		return;
	}
	int x = 1;
	if (step % 2 == 1)
	{
		x = 2;
	}
	if (step >= 2 * n - 7 && step <= 2 * n - 5)
	{
		x = 3 - x;
	}
	move(t1 - x, t2 - x, f1, f2, step + 1);
}
int main()
{
	cin >> n;
	ans.append("x").append(n, 'o').append(n, '*').append(2, '-');
	cout << ans.substr(1) << endl;
	move(n, n + 1, 2 * n + 1, 2 * n + 2, 1);
	return 0;
}

/*! n==4 5步 n==5 7步 n==6 9步 n==7 11步 ---- 2n-3步
图示			   f1f2         t1t2			变化	step
ooooooo*******--   n n+1        2n+1 2n+2		-2	    1
oooooo--******o*   2n-1 2n      n n+1           -1	    2
oooooo******--o*   n-1 n        2n-1 2n         -2	    3
ooooo--*****o*o*   2n-3 2n-2    n-1 n           -1	    4
ooooo*****--o*o*   n-2 n-1      2n-3 2n-2       -2	    5
oooo--****o*o*o*   2n-5 2n-4    n-2 n-1         -1	    6
oooo****--o*o*o*   n-3 n-2      2n-5 2n-4       -1?	    7   2n-7
ooo--***o*o*o*o*   [2n-6 2n-5]  n-3 n-2         -2?	    8	2n-6
ooo*o**--*o*o*o*   [n-5 n-4]    2n-6 2n-5       -1?	    9	2n-5
o--*o**oo*o*o*o*   [2n-7 2n-6]  n-5 n-4         -1	    10	2n-4
o*o*o*--o*o*o*o*   n-6 n-5      2n-7 2n-6         	    11	2n-3
--o*o*o*o*o*o*o*
*/