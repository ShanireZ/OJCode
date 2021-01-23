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
    if (c == 1) //如果栈只有一个位置，则顺序输出
    {
        for (int i = 0; i < n; i++)
        {
            cout << all[i] << " ";
        }
        return 0;
    }
    int pos = 0, front = 0, rear = 0;
    //pos为all内当前读取元素下标  front为起使可出栈位置 rear为最后一个元素的后侧位置
    stack[rear++] = all[pos++];
    while (rear != front) //stack为空则停止
    {
        if (rear < c && pos < n) //若stack内元素数量不够c个，则补满
        {
            stack[rear++] = all[pos++];
        }
        else
        {
            int min_id = front;                     //用来存储当前可出栈所有数中最小数
            for (int i = min_id + 1; i < rear; i++) //找出可出栈数中最小数
            {
                if (stack[i] < stack[min_id])
                {
                    min_id = i;
                }
            }
            cout << stack[min_id] << " "; //输出可出栈数中最小数
            if (min_id != rear - 1)       //空位依次前移
            {
                for (int i = min_id; i < rear - 1; i++)
                {
                    stack[i] = stack[i + 1];
                }
            }
            front = max(min_id - 1, 0); //重新调整起使可出栈位置
            rear--;                     //stack内元素个数减一
        }
    }
    return 0;
}