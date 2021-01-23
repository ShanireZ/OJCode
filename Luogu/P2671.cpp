#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
//? 由要求可知x z必须为同奇或同偶 且颜色必须相同
//? 我们按m种颜色分组 每种颜色两组共2m组 分别表示每种颜色的奇数同色组和偶数同色组
//? 每组中的数假设为ai 编号为xi 该组共有n个元素
//? 必然会有ans=(x1+x2)(a1+a2)+......
//? 化简可得 (n-2)(x1a1+x2a2+...+xnan) + (x1+x2+...+xn)(a1+a2+...+an)
long long bnum[200005], bid[200005], cxn[200005], cnt[200005]; //颜色x的奇数组编号2x-1 偶数组编号2x
long long num[100005];
int main()
{
	freopen("xxxx.in", "r", stdin);
	freopen("xxxx.out", "w", stdout);
	int n, m, mod = 10007;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) //数字
	{
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++) //颜色
	{
		int color;
		cin >> color;
		int gid = 2 * color; //偶数
		if (i % 2 == 1)		 //奇数
		{
			gid--;
		}
		cnt[gid] = (cnt[gid] + 1) % mod;		  //该组成员个数
		bnum[gid] = (bnum[gid] + num[i]) % mod;	  //该组成员num和
		bid[gid] = (bid[gid] + i) % mod;		  //该组成员id和
		cxn[gid] = (cxn[gid] + num[i] * i) % mod; //该组成员id*num和
	}
	long long tot = 0;
	for (int i = 1; i <= m * 2; i++)
	{
		tot += ((cnt[i] - 2) * cxn[i] % mod) + (bnum[i] * bid[i] % mod);
		tot %= mod;
	}
	cout << tot;
	return 0;
}