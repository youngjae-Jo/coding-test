¤·#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int MAX = 1 << 21;

int N, treeSize;
int result;
int arr[MAX];

int DFS(int idx) {
    if (idx * 2 >= treeSize) {
        result += arr[idx];
        return arr[idx];
    }
    else {
        int leftNode = DFS(idx * 2);
        int rightNode = DFS(idx * 2 + 1);
        result += arr[idx] + abs(leftNode - rightNode);
        return arr[idx] + max(leftNode, rightNode);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    treeSize = 1 << (N + 1);

    for (int i = 2; i < treeSize; i++)
        cin >> arr[i];

    DFS(1);
    cout << result << "\n";
    return 0;
}
