#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int nums[200];
void make1(int p)
{
	int n1 = 1, n2 = 0;
	for (int i = p; i >= 1; i--)
	{
		swap(n1, n2);
		n1 += nums[i] * n2;
	}
	int m = min(n1, n2);
	for (int i = 2; i <= m; i++)
	{
		while (n1 % i == 0 && n2 % i == 0)
		{
			n1 /= i;
			n2 /= i;
		}
	}
	if (n2 == 1)
	{
		cout << n1 << endl;
		return;
	}
	cout << n1 << "/" << n2 << endl;
}
void make0(int n1, int n2)
{
	int m = min(n1, n2);
	for (int i = 2; i <= m; i++)
	{
		while (n1 % i == 0 && n2 % i == 0)
		{
			n1 /= i;
			n2 /= i;
		}
	}
	if (n2 == 0)
	{
		cout << "[" << n1 << "]" << endl;
		return;
	}
	int p = 0;
	while (n2 != 1)
	{
		int r = n1 % n2;
		nums[p++] = n1 / n2;
		n1 = n2;
		n2 = r;
	}
	nums[p] = n1;
	cout << "[" << nums[0];
	for (int i = 1; i <= p; i++)
	{
		if (i == 1)
		{
			cout << ";";
		}
		else
		{
			cout << ",";
		}
		cout << nums[i];
	}
	cout << "]" << endl;
}
int main()
{
	string str;
	while (cin >> str)
	{
		str += ']';
		int num = 0, pos = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				num = num * 10 + str[i] - '0';
			}
			else
			{
				nums[pos++] = num;
				num = 0;
			}
		}
		if (str[0] == '[')
		{
			make1(pos - 2);
		}
		else
		{
			make0(nums[0], nums[1]);
		}
	}
	return 0;
}