#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int A[21][21];

bool check(int x, int y, int d1, int d2) {
    return x + d1 + d2 < N && y - d1 >= 0 && y + d2 < N;
}

int calculate(int x, int y, int d1, int d2) {
    vector<vector<int>> temp(N, vector<int>(N, 0));
    vector<int> population(5, 0);

    // 5번 선거구 경계 설정
    for (int i = 0; i <= d1; ++i) {
        temp[x + i][y - i] = 5;
        temp[x + d2 + i][y + d2 - i] = 5;
    }
    for (int i = 0; i <= d2; ++i) {
        temp[x + i][y + i] = 5;
        temp[x + d1 + i][y - d1 + i] = 5;
    }

    // 5번 선거구 내부 채우기
    for (int r = x + 1; r < x + d1 + d2; ++r) {
        bool isInside = false;
        for (int c = 0; c < N; ++c) {
            if (temp[r][c] == 5) isInside = !isInside;
            if (isInside) temp[r][c] = 5;
        }
    }

    // 각 선거구별 인구 계산
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (temp[r][c] == 5) population[4] += A[r][c];
            else if (r < x + d1 && c <= y) population[0] += A[r][c];
            else if (r <= x + d2 && c > y) population[1] += A[r][c];
            else if (r >= x + d1 && c < y - d1 + d2) population[2] += A[r][c];
            else population[3] += A[r][c];
        }
    }

    sort(population.begin(), population.end());
    return population[4] - population[0];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    int result = INT_MAX;
    for (int x = 0; x < N; ++x) {
        for (int y = 1; y < N; ++y) {
            for (int d1 = 1; y - d1 >= 0 && x + d1 < N; ++d1) {
                for (int d2 = 1; y + d2 < N && x + d1 + d2 < N; ++d2) {
                    result = min(result, calculate(x, y, d1, d2));
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}
