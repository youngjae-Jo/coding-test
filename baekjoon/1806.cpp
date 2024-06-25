#include <iostream>
#include <vector>
using namespace std;

int N, S;

int main() {
    cin >> N >> S;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int start = 0, end = 0, sum = 0;
    int minLen = 100001;
    //연속된 수들의 부분합
    while (start <= end) {
        if (sum >= S) {
            minLen = min(minLen, end - start);
            sum -= v[start++];
        }
        else if (end == N)
            break;
        else
            sum += v[end++];
    }
    if (minLen > 100000)
        minLen = 0;
    cout << minLen;
    return 0;
}