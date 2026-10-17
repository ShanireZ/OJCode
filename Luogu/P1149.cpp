/*
	洛谷 P1149
	tag:模擬，函式，搜尋
	題意:用指定數目的火柴拼出等式，求一共能拼出多少不同的等式
	思路:聲明函式make用以計算當前數字所用的火柴數目
		遍歷所有情況，將可以拼出的等式記錄
	坑點:每種情況需要呼叫三次函式，若不使用函式，程式碼將會比較冗長
		還可使用陣列將範圍內的所有數字需要的火柴數記錄，遍歷時可減少重複數字的計算
*/
#include <cstdio>
int amount[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; //所有數字需要火柴數

int make(int i) //計算當前數字需要多少火柴
{
	int count = 0;
	if (i == 0)
	{
		return 6;
	}
	while (i)
	{
		count += amount[i % 10];
		i /= 10;
	}
	return count;
}

int main()
{
	int n, total = 0;
	scanf("%d", &n);
	n -= 4; //除去加號和等號

	for (int i = 0; i < 1000; i++) //元素最高數字不超過1000
	{
		int ai = 0;
		ai = make(i);
		if (ai > n - 4) //每個數字最少2根火柴，剩下不夠4根則無法繼續完成
		{
			continue;
		}

		for (int j = 0; j < 1000; j++)
		{
			int aj = 0;
			aj = make(j);
			if (aj + ai > n - 2) //最後數字若不夠2根則無法完成
			{
				continue;
			}

			int k, ak = 0;
			k = i + j;
			ak = make(k);

			if (ai + aj + ak == n)
			{
				total++;
			}
		}
	}

	printf("%d", total);
	return 0;
}