#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long dp[101];

int main() {
    int T, N, M;
    M = 0;
    cin >> T;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= 100; i++) {
        if (dp[i] == 0) {
            dp[i] = dp[i - 3] + dp[i - 2];
        }
    }

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << dp[N] << endl;
    }
    return 0;
}
