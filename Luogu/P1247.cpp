//! 关于nim取石子问题有定理 所有数xor一遍得到ans
//! 如果ans == 0 那么则为平衡状态 先手必败
//! 反之ans != 0 则为非平衡状态 先手必赢
//todo 因为根据二进制原理，所有堆的数目都可由二进制组成
//todo 所以所有可拆分为2的次幂形式的子堆
//todo 再根据异或原理 1 ^ 1 == 0  0 ^ 1 == 1
//todo 如果拆分出的子堆在i次幂上的堆数为偶时,那么必然有偶数个1异或得到0
//todo 如果i次幂的子堆数为奇数,那么必然奇数个1异或得到1
//todo 如果每个次幂的结果都为0,那么说明每个次幂的子堆数都为偶数,我们称之为平衡状态
//todo 反之为非平衡状态
//* 非平衡状态先手必胜策略
//* 每一步让序列变成平衡状态,将必败结局抛给后手
#include <iostream>
using namespace std;
int all[500005];
int main()
{
    ios::sync_with_stdio(false);
    int n, ans;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> all[i];
    }
    ans = all[1];
    for (int i = 2; i <= n; i++)
    {
        ans = ans ^ all[i];
    }
    if (ans == 0)
    {
        cout << "lose";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            //! 3 ^ 6 ^ 9 = 12 非平衡
            //! 如果想让非平衡12变为平衡 可以从小到大逐个尝试每个堆(要求堆的编号最小)
            //todo 1.因为 12 ^ 3 == 6 ^ 9 == 15
            //todo 所以我们可以将3调整为15, 15 ^ 6 ^ 9 == 15 ^ 15 == 0
            //todo 但是3变不成15,因为3比15小
            //todo 2.因为 12 ^ 6 == 3 ^ 9 == 10
            //todo 我们可以将6变成10来达到目的, 3 ^ 10 ^ 9 == 10 ^ 10 == 0
            //todo 但是6变不成10,因为6比10小
            //* 3.12 ^ 9 == 3 ^ 6 == 5
            //* 所以我们可以将9调整为5, 3 ^ 6 ^ 5 == 5 ^ 5 == 0
            //* 9比5大所以可以调整
            if (all[i] - (ans ^ all[i]) > 0)
            {
                int op = all[i] - (ans ^ all[i]);
                if ((ans ^ all[i]) ^ (all[i] - op) == 0)
                {
                    all[i] -= op;
                    cout << op << " " << i << endl;
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << all[i] << " ";
        }
    }
    return 0;
}