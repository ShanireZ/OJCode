#include <iostream>
using namespace std;

int cube[10][10];
int cube_f[10][10];
int cube_a[10][10];
int n;

void read(int p[10][10])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            if (temp == '@')
            {
                p[i][j] = 0;
            }
            else
            {
                p[i][j] = 1;
            }
        }
    }
}

void turn(int mode)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mode == 1)
            {
                cube_a[j][n - 1 - i] = cube[i][j];
            }
            else if (mode == 2)
            {
                cube_a[i][n - 1 - j] = cube[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cube[i][j] = cube_a[i][j];
        }
    }
}

bool check()
{
    int trig = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cube[i][j] != cube_f[i][j])
            {
                trig = 0;
                break;
            }
        }
    }
    return trig;
}

int main()
{

    cin >> n;
    read(cube);
    read(cube_f);
    int id = -1;
    for (int i = 0; i < 3; i++)
    {
        turn(1);
        if (check())
        {
            id = i + 1;
            goto over;
        }
    }
    turn(1);
    turn(2);
    if (check())
    {
        id = 4;
        goto over;
    }
    for (int i = 0; i < 3; i++)
    {
        turn(1);
        if (check())
        {
            id = 5;
            goto over;
        }
    }
    turn(1);
    turn(2);
    if (check())
    {
        id = 6;
        goto over;
    }
    id = 7;
over:
    cout << id;
    return 0;
}