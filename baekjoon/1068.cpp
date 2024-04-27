#include <iostream>
#include <vector>
using namespace std;

int N, root, ans = 0;
int del;
vector<int> graph[50];

void dfs(int x) {
    int del_idx = -1;
    for (int i = 0; i < graph[x].size(); i++) {
        if (graph[x][i] == del) {
            del_idx = i;
            continue;
        }
        dfs(graph[x][i]);
    }
    if (del_idx > -1)
        graph[x].erase(graph[x].begin() + del_idx);
    if (graph[x].empty())
        ans++;
}

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        int parent = -1;
        cin >> parent;
        if (parent == -1) {
            root = i;
            continue;
        }
        graph[parent].push_back(i);
    }
    cin >> del;
    if (del != root)
        dfs(root);
    cout << ans;

    return 0;
}