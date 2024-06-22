#include<iostream>
#include<cmath>

using namespace std;
int N;

int main(int argc, char** argv)
{
    cin >> N;
    long long dp[16];

    dp[1] = 3;
    dp[2] = 5;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + (pow(2, i - 1));
    }
    cout << dp[N] * dp[N];
    return 0;
}