#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];
long long dp[101][21]; //i,j   i까지 원소들의 조합으로 만들 수 있는 연산값 j를 만드는 경우의 수

int main() {
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1][arr[1]] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + arr[i] <= 20)
					dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[N - 1][arr[N]];
	return 0;
}