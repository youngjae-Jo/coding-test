#include <iostream>

using namespace std;
long long dp[1001];

int main() {
	int n;
	cin >> n;
	//2*n ���簢���� 1*2, 2*1, 2*2�� ä��� ����� ��
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3; //dp[1]�� 2*1���̱� = dp[1], 1*2/2*2
	dp[3] = 5; //dp[2] + 2(1*2 ���̴� ��ġ)-> dp[2] + dp[2]-d[1]
	dp[4] = dp[2] * 2 + dp[3];//dp[2]+2*2/1*2����ؼ� ���̱�, dp[3] + 2*1 �̿��ؼ� ���̱�


	for (int i = 5; i <= n; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}