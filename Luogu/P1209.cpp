/*
	洛谷 P1209
	tag:貪心，排序，搜尋
	題意:有s個牛棚裡面住了c頭牛,需要用m塊木板將有牛的牛棚的門封住，問m塊木板的最小總長度
	思路:可以反向思考這道題，先用一塊木板將所有門都封住，然後再在木板上製造m-1個缺口，就形成了m塊木板
        其中缺口製造該遵循什麼規則呢？
        為了保證木板總長度最短，肯定要優先製造儘可能大的缺口
        下一個缺口要保證比上一個缺口更小，或和上一個缺口一樣大，但不是同一個位置
        得到缺口後，再將缺口大小從總長度上減去即可
	坑點:缺口一樣大時，不是之前出現過的位置該如何判定？
        我們可以建立一個陣列存之前出現過的位置，但這個方法不好，因為比較時會遍歷這個陣列，時間複雜度將再次大幅提升
        我們在製造同樣大小的缺口的時候，可以優先製造位置靠後的缺口
        下一個同樣大小的缺口只要保證位置在前一個之前就可以了
        這個坑點價值10分！！！
        當木板數目不小於牛的數目時，我們每個有牛的牛棚都可以單獨一塊木板！！！
        這個坑點20分！！！
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

    if (m >= c) //木板夠用時，那就每個牛棚單獨一塊
    {
        cout << c;
        return 0;
    }
    total = cows[c - 1] - cows[0] + 1; //一塊木板時總長度

    int pre_distance = 300, pre_pos = 300;
    for (int i = 1; i < m; i++) //m塊木板間共有m-1個缺口,依次找出剩下的最大缺口
    {
        int max_distance = 0;
        int pos;
        for (int j = 1; j < c; j++) //遍歷找出本次缺口
        {
            int distance = cows[j] - cows[j - 1];
            if ((distance < pre_distance) || (distance == pre_distance && j < pre_pos)) //缺口不會比上次更大且非上次缺口
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