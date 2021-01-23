#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int stack[105] = {0};
    int top = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            stack[++top] = i;
        }
        else
        {
            cout << stack[top--] << " " << i << endl;
        }
    }
    return 0;
}
