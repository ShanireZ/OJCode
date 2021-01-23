#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct Stu
{
    string name;
    int age, score;
    void learn()
    {
        age++;
        score = min(600, int(score * 1.2));
    }
    void outp()
    {
        cout << name << " " << age << " " << score << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        Stu s;
        cin >> s.name >> s.age >> s.score;
        s.learn();
        s.outp();
    }
    return 0;
}