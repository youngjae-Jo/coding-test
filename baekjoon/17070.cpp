#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> house;
vector<vector<vector<int>>> dp;

int search(int x, int y, int state) {
    // �������� �������� ��
    if (x == N - 1 && y == N - 1) {
        return 1;
    }

    // �̹� ���� ���
    if (dp[x][y][state] != -1) {
        return dp[x][y][state];
    }

    dp[x][y][state] = 0;

    // ���η� ���� ���
    if (state == 0 || state == 2) {
        if (y + 1 < N && house[x][y + 1] == 0) {
            dp[x][y][state] += search(x, y + 1, 0);
        }
    }

    // ���η� ���� ���
    if (state == 1 || state == 2) {
        if (x + 1 < N && house[x + 1][y] == 0) {
            dp[x][y][state] += search(x + 1, y, 1);
        }
    }

    // �밢������ ���� ���
    if (x + 1 < N && y + 1 < N && house[x + 1][y] == 0 && house[x][y + 1] == 0 && house[x + 1][y + 1] == 0) {
        dp[x][y][state] += search(x + 1, y + 1, 2);
    }

    return dp[x][y][state];
}

int main() {
    cin >> N;
    house.assign(N, vector<int>(N));
    dp.assign(N, vector<vector<int>>(N, vector<int>(3, -1)));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> house[i][j];
        }
    }

    cout << search(0, 1, 0) << endl;

    return 0;
}
