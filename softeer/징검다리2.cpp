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

    vector<int>dp;//������� �� ���� ū, �ݺ� Ȱ��
    dp.push_back(A[1]);
    dp_up[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (A[i] > dp.back()) { //dp�� ���ؼ� 
            dp.push_back(A[i]); // �� ū ��� ����
            dp_up[i] = dp.size(); //�� ū ��츸 �������ϱ� size�� ����
        }
        else {
            int idx = binary_search(dp, A[i]); //i���� �� A[i]�� ��� ��ġ����
            dp[idx] = A[i]; // �� ũ�� �ʾƼ� A[i] ��ġ ã�Ƽ� ��ġ
            dp_up[i] = idx + 1; //�� ũ�� ���� ��� dp���� A[i]�� ��ġ = idx + 1
        }
        ascmax[i] = dp.back(); //i���� �� �ִ밪�� A, �� ���� �� Ȱ��
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
        if (ascmax[i] == A[i] && dp.back() == A[i]) //������
            tmp--;
        res = max(res, tmp);
    }

    cout << res;

    return 0;
}