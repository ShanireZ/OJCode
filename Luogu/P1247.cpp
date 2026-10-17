//! 關於nim取石子問題有定理 所有數xor一遍得到ans
//! 如果ans == 0 那麼則為平衡狀態 先手必敗
//! 反之ans != 0 則為非平衡狀態 先手必贏
//todo 因為根據二進制原理，所有堆的數目都可由二進制組成
//todo 所以所有可拆分為2的次冪形式的子堆
//todo 再根據異或原理 1 ^ 1 == 0  0 ^ 1 == 1
//todo 如果拆分出的子堆在i次冪上的堆數為偶時,那麼必然有偶數個1異或得到0
//todo 如果i次冪的子堆數為奇數,那麼必然奇數個1異或得到1
//todo 如果每個次冪的結果都為0,那麼說明每個次冪的子堆數都為偶數,我們稱之為平衡狀態
//todo 反之為非平衡狀態
//* 非平衡狀態先手必勝策略
//* 每一步讓序列變成平衡狀態,將必敗結局拋給後手
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
            //! 如果想讓非平衡12變為平衡 可以從小到大逐個嘗試每個堆(要求堆的編號最小)
            //todo 1.因為 12 ^ 3 == 6 ^ 9 == 15
            //todo 所以我們可以將3調整為15, 15 ^ 6 ^ 9 == 15 ^ 15 == 0
            //todo 但是3變不成15,因為3比15小
            //todo 2.因為 12 ^ 6 == 3 ^ 9 == 10
            //todo 我們可以將6變成10來達到目的, 3 ^ 10 ^ 9 == 10 ^ 10 == 0
            //todo 但是6變不成10,因為6比10小
            //* 3.12 ^ 9 == 3 ^ 6 == 5
            //* 所以我們可以將9調整為5, 3 ^ 6 ^ 5 == 5 ^ 5 == 0
            //* 9比5大所以可以調整
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