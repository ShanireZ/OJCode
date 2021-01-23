#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	//情况总数 = pow(2, 单子树的节点个数)
	//如果一个节点只有一个子节点，那么必然会出现 前序ab 后序ba 的情况
	//因为前序是 中左右,后序是 左右中
	//找到两个遍历的中节点位置后，如果前序的子节点和后序的子节点相同
	//那么必然说明他缺了左或者右，只有一个子树
	string s1, s2;
	long long tot = 0;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size() - 1; i++)
	{
		for (int j = 1; j < s2.size(); j++)
		{
			if (s1[i] == s2[j] && s1[i + 1] == s2[j - 1])
			{
				tot++;
			}
		}
	}
	cout << pow(2, tot);
	return 0;
}