#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[300001]; int dp_up[300001]; int dp_down[300001]; int ascmax[300001];

int binary_search(vector<int>& dp, int target) {
    int left = 0, right = dp.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (dp[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    vector<int>dp;//현재까지 중 가장 큰, 반복 활용
    dp.push_back(A[1]);
    dp_up[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (A[i] > dp.back()) { //dp를 통해서 
            dp.push_back(A[i]); // 더 큰 경우 갱신
            dp_up[i] = dp.size(); //더 큰 경우만 들어왔으니까 size가 갯수
        }
        else {
            int idx = binary_search(dp, A[i]); //i까지 중 A[i]가 어디 위치인지
            dp[idx] = A[i]; // 더 크지 않아서 A[i] 위치 찾아서 배치
            dp_up[i] = idx + 1; //더 크지 않은 경우 dp에서 A[i]의 위치 = idx + 1
        }
        ascmax[i] = dp.back(); //i까지 중 최대값인 A, 답 구할 때 활용
    }

    dp.clear();
    dp.push_back(A[N]);
    dp_down[N] = 1;

    for (int i = N - 1; i >= 1; i--) {
        if (A[i] > dp.back()) {
            dp.push_back(A[i]);
            dp_down[i] = dp.size();
        }
        else {
            int idx = binary_search(dp, A[i]);
            dp[idx] = A[i];
            dp_down[i] = idx + 1;
        }
    }

    int res = 1;
    for (int i = 1; i <= N; i++) {
        int tmp = dp_up[i] + dp_down[i] - 1;
        if (ascmax[i] == A[i] && dp.back() == A[i]) //변곡점
            tmp--;
        res = max(res, tmp);
    }

    cout << res;

    return 0;
}