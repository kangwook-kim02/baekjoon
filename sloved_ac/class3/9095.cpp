/*
baekjoon 9095
silver 3
������ ��: DP ������ ��ȭ���� ã�� ���� ���� �߿��ϴ�.
*/
#include <iostream>
using namespace std;

int arr[11];
int main() {
	int t;

	cin >> t;
	
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < 11; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	int num;
	for (int i = 0; i < t; i++) {
		cin >> num;
		cout << arr[num] << "\n";
	}

}