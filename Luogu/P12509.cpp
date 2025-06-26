#include <string>
using namespace std;
int Alice(std::string S)
{
    int res = 0;
    for (int i = 0; i < (int)S.size(); i++)
    {
        if (S[i] == '1')
        {
            res ^= i + 1;
        }
    }
    return res;
}
int Bob(std::string T, int X)
{
    for (int i = 0; i < (int)T.size(); i++)
    {
        if (T[i] == '1')
        {
            X ^= i + 1;
        }
    }
    return X;
}