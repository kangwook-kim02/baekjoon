/*
beakjoon 9461
silver 3
�ĵ��� ����
DP (Dynamic programming) - top down
*/
#include <iostream>
using namespace std;

long long dp[101]; // ���� ���� ó���ϴ� ������ 0���� ��� �ʱ�ȭ �ϱ� ����.

long long padovan(int n) {
	if (dp[n] == 0) {
		dp[n] = padovan(n - 2) + padovan(n - 3);
		return dp[n];
	}
	
	return dp[n];
}

int main() {
	int t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;



	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << padovan(n) << "\n";
	}
}