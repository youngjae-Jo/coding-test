#include <iostream>
#include <vector>

using namespace std;

int N;
int T[15];
int P[15];
int m = 0;
int res = 0;
int visited[15] = { 0, };

void interest(int start, int d) {
    if (start >= N) {
        if (m < res) {
            m = res;
        }
        return;
    }

    if (!visited[start] && d + T[start] <= N+1) {
        visited[start] = 1;
        res += P[start];
        interest(start + T[start], d + T[start]);
        visited[start] = 0;
        res -= P[start];
    }

    interest(start + 1, d+1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }
    interest(0, 1);
    cout << m;

    return 0;
}
