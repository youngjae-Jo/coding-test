#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& disk, int K, int direction) {
    vector<int> temp(disk.size());
    for (int i = 0; i < disk.size(); ++i) {
        temp[(i + K * direction + disk.size()) % disk.size()] = disk[i];
    }
    disk = temp;
}

bool remove_adjacent(vector<vector<int>>& disks) {
    int N = disks.size();
    int M = disks[0].size();
    vector<vector<bool>> to_remove(N, vector<bool>(M, false));
    bool removed = false;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (disks[i][j] == 0) continue;
            // Check right and left
            if (disks[i][j] == disks[i][(j + 1) % M]) {
                to_remove[i][j] = to_remove[i][(j + 1) % M] = true;
                removed = true;
            }
            if (disks[i][j] == disks[i][(j - 1 + M) % M]) {
                to_remove[i][j] = to_remove[i][(j - 1 + M) % M] = true;
                removed = true;
            }
            // Check top and bottom
            if (i > 0 && disks[i][j] == disks[i - 1][j]) {
                to_remove[i][j] = to_remove[i - 1][j] = true;
                removed = true;
            }
            if (i < N - 1 && disks[i][j] == disks[i + 1][j]) {
                to_remove[i][j] = to_remove[i + 1][j] = true;
                removed = true;
            }
        }
    }

    if (removed) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (to_remove[i][j]) disks[i][j] = 0;
    }

    return removed;
}

void update_disks(vector<vector<int>>& disks) {
    int N = disks.size();
    int M = disks[0].size();
    int sum = 0, count = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (disks[i][j] != 0) {
                sum += disks[i][j];
                count++;
            }

    if (count == 0) return;
    double avg = (double)sum / count;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (disks[i][j] != 0) {
                if (disks[i][j] > avg) disks[i][j]--;
                else if (disks[i][j] < avg) disks[i][j]++;
            }
}

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    vector<vector<int>> disks(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> disks[i][j];

    while (T--) {
        int x, d, k;
        cin >> x >> d >> k;
        d = (d == 0) ? 1 : -1; // Adjust direction for rotation

        for (int i = x - 1; i < N; i += x) {
            rotate(disks[i], k, d);
        }

        if (!remove_adjacent(disks)) {
            update_disks(disks);
        }
    }

    int result = 0;
    for (const auto& disk : disks)
        for (int num : disk)
            result += num;

    cout << result << endl;
    return 0;
}
