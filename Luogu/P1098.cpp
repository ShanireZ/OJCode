/*
	洛谷 P1098
	tag:模拟，字符串
	题意:一个输入的字符串中会有连接符'-'的出现
        如果连接符左右都是数字或都是小写字母，且左边的ASCII码左边小于右边时
        需要根据三个参数p1 p2 p3将连接符替换为左右两字符之间的元素或'*'
        p1表示替换元素的类型 1为小写 2为大写 3为'*'
        p2表示替换元素每个出现次数
        p3表示输出顺序 1为正序 2为逆序
	思路:模拟每个字符串的处理过程，建立变量存储用以替换连接符的字符串，并用到字符串的replace方法替换
		模拟过程为依次判断 当前字符是否为连接符----左右两边是否同为数字或小写字母----
        依次判断三个参数值---=根据参数值建立替换用字符串----替换连接符
	坑点:仔细读题并整理出每种情况
        从哪个字符起至哪个字符结束考虑清楚，各种情况都试一遍再提交
*/
#include <bits/stdc++.h>
using namespace std;
char nextChar, preChar;

string AddStar(int times) //只打印'*'
{
    string newS = "";
    newS.append(times, '*');
    return newS;
}

string AddChar(char next, char pre, int p2, bool cap, bool sque) //打印字母或数字
{                                                                //sque顺序1,逆序0  cap大写0,小写1
    char add, start, end;
    string newS = "";
    start = pre + 1;
    end = next - 1;
    if (cap == 0)
    {
        start -= 32;
        end -= 32;
    }
    for (add = start; add <= end; add++)
    {
        if (sque == 0)
        {
            newS.insert(newS.begin(), p2, add);
        }
        else
        {
            newS.append(p2, add);
        }
    }
    return newS;
}

string Situation(int p2, int situ) //situ正序小写1大写3,逆序小写2大写4
{
    string newS = "";
    bool cap, sque;
    if (situ == 1)
    {
        cap = 1, sque = 1;
    }
    else if (situ == 2)
    {
        cap = 1, sque = 0;
    }
    else if (situ == 3)
    {
        cap = 0, sque = 1;
    }
    else
    {
        cap = 0, sque = 0;
    }
    newS = AddChar(nextChar, preChar, p2, cap, sque);
    return newS;
}

int main()
{
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;

    for (int i = 1; i < s.size() - 1; i++)
    {
        preChar = s[i - 1], nextChar = s[i + 1];
        if (s[i] == '-' && preChar < nextChar) //是否是连接符且右边大
        {
            if ((isdigit(preChar) && isdigit(nextChar)) || (islower(preChar) && islower(nextChar))) //是否是数字或小写字母
            {
                string newS = "";       // 替换连接符的字符串
                if (p1 == 1 || p1 == 2) //字母或数字模式
                {
                    int situ = p3;
                    if (p1 == 2 && islower(preChar))
                    {
                        situ += 2;
                    }
                    newS = Situation(p2, situ);
                }
                else if (p1 == 3) //只打*模式
                {
                    int times = p2 * (nextChar - preChar - 1);
                    newS = AddStar(times);
                }
                s.replace(i, 1, newS); //用newS替换连接符
            }
        }
    }
    cout << s;
    return 0;
}