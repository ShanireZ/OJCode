#include <iomanip>
#include <iostream>
using namespace std;
int n, tot, w1, w2;
int main()
{
	cin >> n >> tot;
	while (n--)
	{
		int id, w;
		cin >> id >> w;
		id == 1 ? w1 += w : w2 += w;
	}
	cout << fixed << setprecision(3) << 1.0 * tot * w1 / (w1 + w2) << endl;
	return 0;
}