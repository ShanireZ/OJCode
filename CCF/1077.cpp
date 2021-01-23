#include <iostream>
using namespace std;
int tree[21] = {1};
int n;

void output_tree(int pos)
{
	for (int i = 1; i < pos; i++)
	{
		cout << tree[i] << '+';
	}
	cout << tree[pos] << endl;
}

void make_tree(int pos, int remain)
{
	for (int i = tree[pos - 1]; i <= remain; i++)
	{
		if (i == n)
		{
			break;
		}
		tree[pos] = i;
		if (remain - i == 0)
		{
			output_tree(pos);
		}
		else
		{
			make_tree(pos + 1, remain - i);
		}
	}
}

int main()
{
	cin >> n;
	int m = n;
	make_tree(1, m);
	return 0;
}