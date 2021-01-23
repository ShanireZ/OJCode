#include<iostream>
#include<string>
using namespace std;

int main()
{
	string stringA, stringB;
	cin >> stringA;
	cin >> stringB;
	
	int a, totalA = 1, b, totalB = 1;
	for(int i = 0; i < stringA.size(); i++)
	{
		a = stringA[i] - 'A' + 1;
		totalA = totalA * a;
	}
	for(int i = 0; i < stringB.size(); i++)
	{
		b = stringB[i] - 'A' + 1;
		totalB = totalB * b;
	}
	
	totalA = totalA % 47;
	totalB = totalB % 47;
	if(totalA == totalB)
	{
		cout << "GO";
	}else
	{
		cout << "STAY";
	}
	
	return 0;
}
