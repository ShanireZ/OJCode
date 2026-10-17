#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << n * n - 1 << "\n"; // 最後一層(n-1個)+之前所有層(等差數列)
	return 0;
}