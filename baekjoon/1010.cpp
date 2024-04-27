#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long dp[31][31];

void dp_comb() {
    for (int i = 1; i <= 30; i++) {
        dp[i][1] = i;
        dp[i][i] = 1;
        dp[i][0] = 1;
    }
    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}

int main() {
    int T, N, M;
    cin >> T;
    dp_comb();

    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        cout << dp[M][N] << endl;
    }
    return 0;
}
