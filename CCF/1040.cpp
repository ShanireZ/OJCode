#include<iostream>
using namespace std;
 
int main()
{
    long long a, b, c, m, n; 
    cin >> a >> b;
    m = a;
    n = b;
    while(n != 0)
    {
    	long long t = m;
    	m = n;
    	n = t % n;
	}
    c = m;
    b = b / c;
    if(c % b == 0)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
