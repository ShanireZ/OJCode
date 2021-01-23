#include <iostream>
using namespace std;
int main()
{
	long long n, m;
	cin >> n >> m;
	//!所有图形个数 第一行1 ~ m之和 第二行2*(1 ~ m)之和 ...
	long long tot_all = m * (m + 1) / 2 * n * (n + 1) / 2;
	//!正方形个数 第一行全是1 第二行122222... 第三行123.....
	//!其实1233333之和 = 1234567之和 - 1234之和
	//!当然没有东西可减时就停止减
	long long tot_cube = 0;
	for (int i = 1; i <= n; i++)
	{
		tot_cube += m * (m + 1) / 2;
		if (m - i > 0)
		{
			tot_cube -= (m - i + 1) * (m - i) / 2;
		}
	}
	cout << tot_cube << " " << tot_all - tot_cube;
	return 0;
}