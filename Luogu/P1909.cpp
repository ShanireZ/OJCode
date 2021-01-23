#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int s1, p1, s2, p2, s3, p3;
	cin >> s1 >> p1 >> s2 >> p2 >> s3 >> p3;
	int c1 = ceil(1.0 * n / s1) * p1;
	int c2 = ceil(1.0 * n / s2) * p2;
	int c3 = ceil(1.0 * n / s3) * p3;
	int minc = min(c1, c2);
	minc = min(minc, c3);
	cout << minc;
	return 0;
}