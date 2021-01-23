#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	//1 输入
	int a, b, c;
	cin >> a >> b >> c;
	//2 运算
	if (a < b)
	{
		swap(a, b);
	}
	if (a < c)
	{
		swap(a, c);
	}
	if (b < c)
	{
		swap(b, c);
	}
	//3 输出
	cout << c << " " << b << " " << a;
	return 0;
}