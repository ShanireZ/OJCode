#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int up[100005];
int h[100005];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
		while (s.size() && h[s.top()] < h[i])
		{
			up[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << up[i] << endl;
	}
	return 0;
}