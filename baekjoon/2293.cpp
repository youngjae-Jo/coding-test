#include <iostream>

using namespace std;
long long dp[10001];
int value[101] = { 0, };

int main() {
    int n, k;
    int cnt = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = value[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - value[i]];
        }
    }
    cout << dp[k];
    return 0;
}
