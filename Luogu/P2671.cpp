#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
//? 由要求可知x z必須為同奇或同偶 且顏色必須相同
//? 我們按m種顏色分組 每種顏色兩組共2m組 分別表示每種顏色的奇數同色組和偶數同色組
//? 每組中的數假設為ai 編號為xi 該組共有n個元素
//? 必然會有ans=(x1+x2)(a1+a2)+......
//? 化簡可得 (n-2)(x1a1+x2a2+...+xnan) + (x1+x2+...+xn)(a1+a2+...+an)
long long bnum[200005], bid[200005], cxn[200005], cnt[200005]; //顏色x的奇陣列編號2x-1 偶陣列編號2x
long long num[100005];
int main()
{
	freopen("xxxx.in", "r", stdin);
	freopen("xxxx.out", "w", stdout);
	int n, m, mod = 10007;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) //數字
	{
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++) //顏色
	{
		int color;
		cin >> color;
		int gid = 2 * color; //偶數
		if (i % 2 == 1)		 //奇數
		{
			gid--;
		}
		cnt[gid] = (cnt[gid] + 1) % mod;		  //該組成員個數
		bnum[gid] = (bnum[gid] + num[i]) % mod;	  //該組成員num和
		bid[gid] = (bid[gid] + i) % mod;		  //該組成員id和
		cxn[gid] = (cxn[gid] + num[i] * i) % mod; //該組成員id*num和
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