#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, c;
    cin >> n >> c;
    int stack[c], all[n];
    memset(all, 0, sizeof(all));
    memset(stack, 0, sizeof(stack));
    for (int i = 0; i < n; i++)
    {
        cin >> all[i];
    }
    if (c == 1) //如果棧只有一個位置，則順序輸出
    {
        for (int i = 0; i < n; i++)
        {
            cout << all[i] << " ";
        }
        return 0;
    }
    int pos = 0, front = 0, rear = 0;
    //pos為all內當前讀取元素下標  front為起使可出棧位置 rear為最後一個元素的後側位置
    stack[rear++] = all[pos++];
    while (rear != front) //stack為空則停止
    {
        if (rear < c && pos < n) //若stack內元素數量不夠c個，則補滿
        {
            stack[rear++] = all[pos++];
        }
        else
        {
            int min_id = front;                     //用來儲存當前可出棧所有數中最小數
            for (int i = min_id + 1; i < rear; i++) //找出可出棧數中最小數
            {
                if (stack[i] < stack[min_id])
                {
                    min_id = i;
                }
            }
            cout << stack[min_id] << " "; //輸出可出棧數中最小數
            if (min_id != rear - 1)       //空位依次前移
            {
                for (int i = min_id; i < rear - 1; i++)
                {
                    stack[i] = stack[i + 1];
                }
            }
            front = max(min_id - 1, 0); //重新調整起使可出棧位置
            rear--;                     //stack內元素個數減一
        }
    }
    return 0;
}