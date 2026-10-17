#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	//情況總數 = pow(2, 單子樹的節點個數)
	//如果一個節點只有一個子節點，那麼必然會出現 前序ab 後序ba 的情況
	//因為前序是 中左右,後序是 左右中
	//找到兩個遍歷的中節點位置後，如果前序的子節點和後序的子節點相同
	//那麼必然說明他缺了左或者右，只有一個子樹
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