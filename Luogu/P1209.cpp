/*
	洛谷 P1209
	tag:贪心，排序，搜索
	题意:有s个牛棚里面住了c头牛,需要用m块木板将有牛的牛棚的门封住，问m块木板的最小总长度
	思路:可以反向思考这道题，先用一块木板将所有门都封住，然后再在木板上制造m-1个缺口，就形成了m块木板
        其中缺口制造该遵循什么规则呢？
        为了保证木板总长度最短，肯定要优先制造尽可能大的缺口
        下一个缺口要保证比上一个缺口更小，或和上一个缺口一样大，但不是同一个位置
        得到缺口后，再将缺口大小从总长度上减去即可
	坑点:缺口一样大时，不是之前出现过的位置该如何判定？
        我们可以建立一个数组存之前出现过的位置，但这个方法不好，因为比较时会遍历这个数组，时间复杂度将再次大幅提升
        我们在制造同样大小的缺口的时候，可以优先制造位置靠后的缺口
        下一个同样大小的缺口只要保证位置在前一个之前就可以了
        这个坑点价值10分！！！
        当木板数目不小于牛的数目时，我们每个有牛的牛棚都可以单独一块木板！！！
        这个坑点20分！！！
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int m, s, c, total;
    cin >> m >> s >> c;
    int cows[c];
    memset(cows, 0, sizeof(cows));
    for (int i = 0; i < c; i++)
    {
        cin >> cows[i];
    }
    sort(cows, cows + c);

    if (m >= c) //木板够用时，那就每个牛棚单独一块
    {
        cout << c;
        return 0;
    }
    total = cows[c - 1] - cows[0] + 1; //一块木板时总长度

    int pre_distance = 300, pre_pos = 300;
    for (int i = 1; i < m; i++) //m块木板间共有m-1个缺口,依次找出剩下的最大缺口
    {
        int max_distance = 0;
        int pos;
        for (int j = 1; j < c; j++) //遍历找出本次缺口
        {
            int distance = cows[j] - cows[j - 1];
            if ((distance < pre_distance) || (distance == pre_distance && j < pre_pos)) //缺口不会比上次更大且非上次缺口
            {
                if (distance >= max_distance)
                {
                    max_distance = distance;
                    pos = j;
                }
            }
        }
        pre_pos = pos;               //本次缺口位置
        pre_distance = max_distance; //本次缺口大小
        total = total - max_distance + 1;
    }

    cout << total;
    return 0;
}