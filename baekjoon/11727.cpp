#include <iostream>

using namespace std;
long long dp[1001];

int main() {
	int n;
	cin >> n;
	//2*n 직사각형을 1*2, 2*1, 2*2로 채우는 경우의 수
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3; //dp[1]에 2*1붙이기 = dp[1], 1*2/2*2
	dp[3] = 5; //dp[2] + 2(1*2 붙이는 위치)-> dp[2] + dp[2]-d[1]
	dp[4] = dp[2] * 2 + dp[3];//dp[2]+2*2/1*2사용해서 붙이기, dp[3] + 2*1 이용해서 붙이기


	for (int i = 5; i <= n; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}