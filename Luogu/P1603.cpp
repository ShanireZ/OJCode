#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string words[26] = {"one", "two", "three", "four", "five", "six", "seven", "eight",
                    "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                    "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
                    "a", "both", "another", "first", "second", "third"};
string nums[26] = {"01", "04", "09", "16", "25", "36", "49", "64", "81", "00",
                   "21", "44", "69", "96", "25", "56", "89", "24", "61", "00",
                   "01", "04", "01", "01", "04", "09"};

int main()
{
    string str;
    getline(cin, str);
    str = " " + str.substr(0, str.size() - 1) + " ";
    string output[6];
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        words[i] = " " + words[i] + " ";
        int pos = str.find(words[i], 0);
        while (pos != string::npos)
        {
            output[count] = nums[i];
            count++;
            pos = str.find(words[i], pos + 1);
        }
    }
    if(count == 0)
    {
        cout << 0;
        return 0;
    }
    sort(output, output + count);
    string result;
    for (int i = 0; i < count; i++)
    {
        result += output[i];
    }
    while (result[0] == '0')
    {
        result.erase(0, 1);
    }
    cout << result;
    return 0;
}