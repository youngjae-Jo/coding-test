#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long N, B;
vector<long> a;

bool calculate(long target) {
    long cost = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < target) {
            cost += pow(target - a[i], 2);
            if (cost > B)
                return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> B;
    a.resize(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long left = a[0];
    long right = a[N - 1] + (long)sqrt(B);
    long ans;

    while (left <= right) {
        long mid = (left + right) / 2;
        if (calculate(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;

    }

    cout << ans;

    return 0;

}