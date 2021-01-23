#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Car
{
    string num, info;
    int v, w, id;
    float ratio;
    void compute()
    {
        ratio = 1.0 * v / w;
    }
};

bool cmp(Car a, Car b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    cin >> n;
    Car cars[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> cars[i].num >> cars[i].v >> cars[i].w >> temp >> cars[i].info;
        cars[i].id = i + 1;
        cars[i].compute();
    }
    sort(cars, cars + n, cmp);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int temp;
            cin >> temp;
            for (int i = 0; i < n; i++)
            {
                if (cars[i].id == temp)
                {
                    cout << cars[i].num << endl;
                    break;
                }
            }
        }
        else if (op == 2)
        {
            string temp;
            cin >> temp;
            for (int i = 0; i < n; i++)
            {
                if (cars[i].num == temp)
                {
                    cout << cars[i].info << endl;
                    break;
                }
            }
        }
        else
        {
            float temp;
            cin >> temp;
            for (int i = 0; i < n; i++)
            {
                if (cars[i].ratio < temp)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}