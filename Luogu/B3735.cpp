#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << n * n - 1 << "\n"; // 最后一层(n-1个)+之前所有层(等差数列)
	return 0;
}