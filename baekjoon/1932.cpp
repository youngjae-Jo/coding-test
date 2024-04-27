#include <iostream>
#include <algorithm>

using namespace std;
int arr[501][501];
int dp[501][501];

int main() {
    int n;
    cin >> n;
    int M = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];
    if (n >= 2) {
        dp[2][1] = dp[1][1] + arr[2][1];
        dp[2][2] = dp[1][1] + arr[2][2];
    }
    //왼쪽으로 가는건 i-1, j 오른쪽으로 가는건 i, j+1
    //왼쪽줄, 오른쪽 줄 
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        M = max(M, dp[n][i]);
    }
    cout << M;
    return 0;
}
