#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    string id;
    int age, sx, lr;
    bool operator<(const Node &oth) const
    {
        if (lr == oth.lr)
        {
            if (lr == 1)
            {
                if (age == oth.age)
                {
                    return sx < oth.sx;
                }
                return age > oth.age;
            }
            else
            {
                return sx < oth.sx;
            }
        }
        return lr > oth.lr;
    }
};
Node ns[105];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].id >> ns[i].age;
        ns[i].sx = i, ns[i].lr = (ns[i].age >= 60);
    }
    sort(ns + 1, ns + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        cout << ns[i].id << endl;
    }
    return 0;
}