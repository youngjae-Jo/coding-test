#include <iostream>
#include <memory.h>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[6][3]; //½Â ¹« ÆÐ
bool flag = false;

bool flag_check() {
    for (int i = 0; i < 6; i++) {
        for (int k = 0; k < 3; k++) {
            if (arr[i][k] != 0) return false;
        }
    }
    return true;
}

void backtracking(int idx, int next, int depth) {
    if (idx == 5 && depth == 15) {
        if (flag_check()) flag = true;
        return;
    }
    if (arr[idx][0] > 0 && arr[next][2] > 0) {
        arr[idx][0]--;
        arr[next][2]--;
        backtracking(idx, next + 1, depth + 1);
        arr[idx][0]++;
        arr[next][2]++;
    }
    if (arr[idx][1] > 0 && arr[next][1] > 0) {
        arr[idx][1]--;
        arr[next][1]--;
        backtracking(idx, next + 1, depth + 1);
        arr[idx][1]++;
        arr[next][1]++;
    }
    if (arr[idx][2] > 0 && arr[next][0] > 0) {
        arr[idx][2]--;
        arr[next][0]--;
        backtracking(idx, next + 1, depth + 1);
        arr[idx][2]++;
        arr[next][0]++;
    }
    if (idx < 5) backtracking(idx + 1, idx + 2, depth);

}

int main() {

    for (int i = 0; i < 4; i++) {
        memset(arr, 0, sizeof(arr));
        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 3; c++)
                cin >> arr[r][c];
        }
        backtracking(0, 1, 0);
        if (flag) cout << 1 << ' ';
        else cout << 0 << ' ';
        flag = false;
    }


    return 0;
}
