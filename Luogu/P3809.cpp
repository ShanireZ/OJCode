#include <iostream>
#include <string>
using namespace std;
//c桶 sa[i]第i名是誰 wt輸出用
//y[i]第二關鍵字排名為i的數，其第一關鍵字位置 x[i]第i個數的第一關鍵字
int y[1000050], x[1000050], c[1000050], sa[1000050], wt[30];
int n, m; //長度 種類
string s;
void get_SA()
{
    for (int i = 1; i <= n; ++i)
    {
        x[i] = s[i];
        c[x[i]]++;
    }
    //c陣列是桶 x[i]是第i個後綴的第一關鍵字
    for (int i = 2; i <= m; ++i)
    {
        c[i] += c[i - 1];
    }
    //做c的前綴和，我們就可以得出每個關鍵字最多是在第幾名
    for (int i = n; i >= 1; --i)
    {
        sa[c[x[i]]--] = i;
    }
    //根據第一關鍵字 統計每個後綴的初始排名
    for (int k = 1; k <= n; k <<= 1)
    {
        int pos = 0;
        for (int i = n - k + 1; i <= n; ++i)
        {
            y[++pos] = i;
        }
        //y[i]表示第二關鍵字排名為i的數，其第一關鍵字的位置
        //第n-k+1到第n位沒有第二關鍵字，所以按第二關鍵字排名時在最前面
        for (int i = 1; i <= n; ++i)
        {
            if (sa[i] > k)
            {
                y[++pos] = sa[i] - k;
            }
        }
        //如果滿足sa[i]>k  那麼該字元可以作為別人的第二關鍵字
        //該字元作為某後綴第二關鍵字時，排名順序和sa中原順序一致
        //所以i枚舉的是第二關鍵字的排名，第二關鍵字靠前的先入y
        for (int i = 1; i <= m; ++i)
        {
            c[i] = 0;
        }
        //初始化重置c桶
        for (int i = 1; i <= n; ++i)
        {
            c[x[i]]++;
        }
        //將第一關鍵字放入桶中
        for (int i = 2; i <= m; ++i)
        {
            c[i] += c[i - 1];
        }
        //統計c的前綴和，c[i]現在為第一關鍵字排名為1~i的數的個數
        for (int i = n; i >= 1; --i)
        {
            int t = x[y[i]]; //第二關鍵字排名i的後綴，其第一關鍵字ascii
            sa[c[t]--] = y[i];
            //y[i] = 0;
        }
        //基數排序
        //因為y是按第二關鍵字的順序來排的
        //第二關鍵字靠後的，在同一個第一關鍵字桶中排名越靠後
        swap(x, y);
        //因為生成新的x時要用到舊的，就把舊的複製至y
        x[sa[1]] = 1; //新排序順便離散了，這樣範圍更小速度更快
        pos = 1;
        for (int i = 2; i <= n; ++i)
        {
            //如果i和i-1相同，就賦值pos表示和i-1一樣
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? pos : ++pos;
        }
        //因為sa[i]已經排好序了，所以可以按排名枚舉，生成下一次的第一關鍵字
        if (pos == n)
        {
            break;
        }
        m = pos;
        //因為已經離散化了，所以就有新範圍了，新範圍必然更小
    }
}

int main()
{
    cin >> s;
    s.insert(0, "#");
    n = s.size() - 1, m = 122;
    //n表示原字串長度，m表示字元個數，ascll('z')=122
    //我們第一次讀入字元直接不用轉化，按原來的ascll碼來就可以了
    //因為轉化數字和大小寫字母還得分類討論，怪麻煩的
    get_SA();
    for (int i = 1; i <= n; i++)
    {
        cout << sa[i] << " ";
    }
    return 0;
}