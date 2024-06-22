#include<iostream>

using namespace std;

int N;
int A[3001];
int dp[3001];
int res = 0;

void cross() { //점점 높아지는
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (A[i] < A[j] && dp[j] <= dp[i]) {
                dp[j] = dp[i] + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        res = max(res, dp[i]);
    }
}

int main(int argc, char** argv)
{
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        dp[i] = 1;
    }

    cross();

    cout << res;
    return 0;
}