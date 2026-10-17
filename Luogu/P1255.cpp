#include <iostream>
#include <string>
using namespace std;
string steps[5001];

string plus_string(string a, string b)
{
    string result;
    int pos_a = a.size() - 1;    //a最後一位下標
    int pos_b = b.size() - 1;    //b最後一位下標
    int pos = max(pos_a, pos_b); //取較長字串對齊
    if (pos_a > pos_b)           //位數少的數前方補0
    {
        b.insert(0, pos_a - pos_b, '0');
    }
    else
    {
        a.insert(0, pos_b - pos_a, '0');
    }
    bool next = false; //是否進位
    while (pos >= 0)
    {
        int temp;
        temp = (a[pos] - '0') + (b[pos] - '0');
        if (next == true)
        {
            temp++;
            next = false;
        }
        if (temp >= 10)
        {
            temp -= 10;
            next = true;
        }
        result.insert(0, 1, temp + '0');
        pos--;
    }
    if (next == 1)
    {
        result.insert(0, "1");
    }
    return result;
}

string ladders(int n)
{
    if (steps[n] == "")
    {
        steps[n] = plus_string(ladders(n - 1), ladders(n - 2));
    }
    return steps[n];
}

int main()
{
    steps[0] = "0", steps[1] = "1", steps[2] = "2";
    int n;
    cin >> n;
    cout << ladders(n) << endl;
    return 0;
}