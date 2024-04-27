#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[100000];

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int M = num[0];
    dp[0] = num[0];

    for (int i = 1; i < num.size(); i++) {
        dp[i] = max(num[i], dp[i - 1] + num[i]);
        M = max(dp[i], M);
    }
    cout << M;
    return 0;
}
