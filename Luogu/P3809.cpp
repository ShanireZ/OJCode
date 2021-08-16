#include <iostream>
#include <string>
using namespace std;
//c桶 sa[i]第i名是谁 wt输出用
//y[i]第二关键字排名为i的数，其第一关键字位置 x[i]第i个数的第一关键字
int y[1000050], x[1000050], c[1000050], sa[1000050], wt[30];
int n, m; //长度 种类
string s;
void get_SA()
{
    for (int i = 1; i <= n; ++i)
    {
        x[i] = s[i];
        c[x[i]]++;
    }
    //c数组是桶 x[i]是第i个后缀的第一关键字
    for (int i = 2; i <= m; ++i)
    {
        c[i] += c[i - 1];
    }
    //做c的前缀和，我们就可以得出每个关键字最多是在第几名
    for (int i = n; i >= 1; --i)
    {
        sa[c[x[i]]--] = i;
    }
    //根据第一关键字 统计每个后缀的初始排名
    for (int k = 1; k <= n; k <<= 1)
    {
        int pos = 0;
        for (int i = n - k + 1; i <= n; ++i)
        {
            y[++pos] = i;
        }
        //y[i]表示第二关键字排名为i的数，其第一关键字的位置
        //第n-k+1到第n位没有第二关键字，所以按第二关键字排名时在最前面
        for (int i = 1; i <= n; ++i)
        {
            if (sa[i] > k)
            {
                y[++pos] = sa[i] - k;
            }
        }
        //如果满足sa[i]>k  那么该字符可以作为别人的第二关键字
        //该字符作为某后缀第二关键字时，排名顺序和sa中原顺序一致
        //所以i枚举的是第二关键字的排名，第二关键字靠前的先入y
        for (int i = 1; i <= m; ++i)
        {
            c[i] = 0;
        }
        //初始化重置c桶
        for (int i = 1; i <= n; ++i)
        {
            c[x[i]]++;
        }
        //将第一关键字放入桶中
        for (int i = 2; i <= m; ++i)
        {
            c[i] += c[i - 1];
        }
        //统计c的前缀和，c[i]现在为第一关键字排名为1~i的数的个数
        for (int i = n; i >= 1; --i)
        {
            int t = x[y[i]]; //第二关键字排名i的后缀，其第一关键字ascii
            sa[c[t]--] = y[i];
            //y[i] = 0;
        }
        //基数排序
        //因为y是按第二关键字的顺序来排的
        //第二关键字靠后的，在同一个第一关键字桶中排名越靠后
        swap(x, y);
        //因为生成新的x时要用到旧的，就把旧的复制至y
        x[sa[1]] = 1; //新排序顺便离散了，这样范围更小速度更快
        pos = 1;
        for (int i = 2; i <= n; ++i)
        {
            //如果i和i-1相同，就赋值pos表示和i-1一样
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? pos : ++pos;
        }
        //因为sa[i]已经排好序了，所以可以按排名枚举，生成下一次的第一关键字
        if (pos == n)
        {
            break;
        }
        m = pos;
        //因为已经离散化了，所以就有新范围了，新范围必然更小
    }
}

int main()
{
    cin >> s;
    s.insert(0, "#");
    n = s.size() - 1, m = 122;
    //n表示原字符串长度，m表示字符个数，ascll('z')=122
    //我们第一次读入字符直接不用转化，按原来的ascll码来就可以了
    //因为转化数字和大小写字母还得分类讨论，怪麻烦的
    get_SA();
    for (int i = 1; i <= n; i++)
    {
        cout << sa[i] << " ";
    }
    return 0;
}