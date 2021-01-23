#include <iostream>
#include <cstdio>
using namespace std;
int times = 1;

void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%d.Move %d from %c to %c\n", times++, n, a, c);
    }
    else
    {
        hanoi(n - 1, a, c, b);
        printf("%d.Move %d from %c to %c\n", times++, n, a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'a', 'b', 'c');
    return 0;
}


