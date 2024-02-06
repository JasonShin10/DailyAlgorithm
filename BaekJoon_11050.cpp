#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int factorial(int n)
{
	int num = 1;
	for (int i = 2; i <= n; i++)
	{
		num *= i;
	}
	return num;
}

int BinomialCoefficient(int N, int K)
{
	int answer = factorial(N) / (factorial(N - K) * factorial(K));
	return answer;
}

int main() {
	int N, K;
	cin >> N >> K;
	cout << BinomialCoefficient(N, K);
}
