/*
	洛谷 P1203
	tag:搜尋，字串，模擬
	題意:一串項鍊，上面有r,b,w三色的珠子，紅藍相對獨立，白色萬用
		從任意兩個珠子間打斷項鍊，並從兩頭開始不斷收集顏色相同的珠子，直到遇到顏色不同的珠子為止
		問從哪打斷項鍊收集的珠子最多
	思路:模擬從每一個點打斷時，收集的珠子的數量，將最大的數輸出即可
		其中要解決的問題有：
		珠子座標問題(珠子座標是環形的)
		白色萬用珠子的問題(會在開頭或者中間出現)
		收集量統計和收集量取最大值的問題
	坑點:這算動態規劃麼？
		主要坑點是會有一串全是相同顏色的珠子！尤其是全白的比較難處理！
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string necklace = "";

int reset(int num)
{
	if (num > n - 1)
	{
		num -= n;
	}
	else if (num < 0)
	{
		num += n;
	}
	return num;
}

void check_start(int &total, int &start, int end, int add)
{
	while (necklace[reset(start)] == 'w')
	{
		start += add;
		total++;
		if (reset(start) == reset(end))
		{
			cout << n;
			exit(0);
		}
	}
}

void count_jewel(int &total, int start, int range_i, int add)
{
	for (int i = 0; i < range_i; i++)
	{
		if (necklace[start] == necklace[reset(start + i * add)] || necklace[reset(start + i * add)] == 'w')
		{
			total++;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	cin >> n >> necklace;
	int max_jewel = 0;
	for (int i = 0; i < n; i++)
	{
		int total = 0;
		int pos_start = i;
		int pos_end = i - 1;
		check_start(total, pos_start, pos_end, 1);
		count_jewel(total, pos_start, n, 1);
		int pos_cost = total;
		pos_start += (total - 1);
		check_start(total, pos_end, pos_start, -1);
		count_jewel(total, pos_end, n - pos_cost, -1);
		max_jewel = max(max_jewel, total);
	}
	cout << max_jewel;
	return 0;
}