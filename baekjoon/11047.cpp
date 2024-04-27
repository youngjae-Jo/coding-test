#include <iostream>
#include <climits>

using namespace std;
int A[11] = { 0, };
int N, K;

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int sum = 0;
    for (int i = N; i >= 1; i--) {
        sum += K / A[i];
        K = K % A[i];
    }

    cout << sum;
    return 0;
}