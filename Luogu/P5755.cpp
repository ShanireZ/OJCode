#include <algorithm>
#include <iostream>
using namespace std;
string s;
int trie[50005][26], root = 1, pos = 1;
void init()
{
	int now = root;
	for (char ch : s)
	{
		int x = ch - 'A';
		if (trie[now][x] == 0)
		{
			trie[now][x] = ++pos;
		}
		now = trie[now][x];
	}
}
int main()
{
	while (cin >> s)
	{
		init();
	}
	cout << pos << endl;
	return 0;
}