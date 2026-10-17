/*
	洛谷 P1098
	tag:模擬，字串
	題意:一個輸入的字串中會有連接符'-'的出現
        如果連接符左右都是數字或都是小寫字母，且左邊的ASCII碼左邊小於右邊時
        需要根據三個參數p1 p2 p3將連接符替換為左右兩字元之間的元素或'*'
        p1表示替換元素的類型 1為小寫 2為大寫 3為'*'
        p2表示替換元素每個出現次數
        p3表示輸出順序 1為正序 2為逆序
	思路:模擬每個字串的處理過程，建立變數儲存用以替換連接符的字串，並用到字串的replace方法替換
		模擬過程為依次判斷 當前字元是否為連接符----左右兩邊是否同為數字或小寫字母----
        依次判斷三個參數值---=根據參數值建立替換用字串----替換連接符
	坑點:仔細讀題並整理出每種情況
        從哪個字元起至哪個字元結束考慮清楚，各種情況都試一遍再提交
*/
#include <bits/stdc++.h>
using namespace std;
char nextChar, preChar;

string AddStar(int times) //只列印'*'
{
    string newS = "";
    newS.append(times, '*');
    return newS;
}

string AddChar(char next, char pre, int p2, bool cap, bool sque) //列印字母或數字
{                                                                //sque順序1,逆序0  cap大寫0,小寫1
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

string Situation(int p2, int situ) //situ正序小寫1大寫3,逆序小寫2大寫4
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
        if (s[i] == '-' && preChar < nextChar) //是否是連接符且右邊大
        {
            if ((isdigit(preChar) && isdigit(nextChar)) || (islower(preChar) && islower(nextChar))) //是否是數字或小寫字母
            {
                string newS = "";       // 替換連接符的字串
                if (p1 == 1 || p1 == 2) //字母或數字模式
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
                s.replace(i, 1, newS); //用newS替換連接符
            }
        }
    }
    cout << s;
    return 0;
}