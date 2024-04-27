#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1001];
int dp[1001];
int previ[1001]; // 추적 배열
int N;
int maxi = 0, max_index = 0;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        dp[i] = 1;
        previ[i] = -1; // 초기 추적 정보 설정
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                previ[i] = j;
            }
        }
        if (maxi < dp[i]) {
            maxi = dp[i];
            max_index = i; // LIS의 마지막 원소 위치 저장
        }
    }

    // LIS 추적 및 출력
    vector<int> lis;
    for (int i = max_index; i != -1; i = previ[i]) {
        lis.push_back(A[i]);
    }
    reverse(lis.begin(), lis.end());

    cout << maxi << "\n";
    for (int x : lis) {
        cout << x << " ";
    }

    return 0;
}
