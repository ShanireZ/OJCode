#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n1[5000], n2[5000], n3[5000];
bool check(int p)
{
	for (int i = 1; i <= p / 2; i++)
	{
		if (n1[i] != n1[p - i + 1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string m;
	int n, p, step = 0;
	cin >> n >> m;
	p = m.size();
	for (int i = 0; i < p; i++)
	{
		if (m[i] >= '0' && m[i] <= '9')
		{
			n1[i + 1] = m[i] - '0';
			n2[p - i] = m[i] - '0';
		}
		else
		{
			n1[i + 1] = m[i] - 'A' + 10;
			n2[p - i] = m[i] - 'A' + 10;
		}
	}
	while (step < 30)
	{
		memset(n3, 0, sizeof(n3));
		for (int i = p; i > 0; i--)
		{
			n3[i] += n1[i] + n2[i];
			if (n3[i] >= n)
			{
				n3[i - 1]++;
				n3[i] -= n;
			}
		}
		step++;
		p += n3[0];
		int p1 = 1, p2 = p;
		for (int i = 1 - n3[0]; i <= p - n3[0]; i++)
		{
			n1[p1++] = n3[i];
			n2[p2--] = n3[i];
		}
		if (check(p))
		{
			cout << "STEP=" << step;
			return 0;
		}
	}
	cout << "Impossible!";
	return 0;
}