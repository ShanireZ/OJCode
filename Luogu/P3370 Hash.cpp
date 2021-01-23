#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
unsigned long long mod1 = 1000000007, mod2 = 1000000009;
unsigned long long base = 233;
struct Hash
{
	unsigned long long r1, r2;
};
Hash hs[10005];
bool cmp(Hash a, Hash b)
{
	return a.r1 < b.r1;
}
void make_hash(string str, int pos)
{
	unsigned long long ans1 = 0, ans2 = 0;
	for (int i = 0; i < str.size(); i++)
	{
		ans1 = (ans1 * base + str[i]) % mod1;
		ans2 = (ans2 * base + str[i]) % mod2;
	}
	hs[pos].r1 = ans1, hs[pos].r2 = ans2;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		make_hash(str, i);
	}
	sort(hs + 1, hs + 1 + n, cmp);
	int tot = 1;
	for (int i = 1; i < n; i++)
	{
		if (hs[i].r1 != hs[i + 1].r1 || hs[i].r2 != hs[i + 1].r2)
		{
			tot++;
		}
	}
	cout << tot;
	return 0;
}