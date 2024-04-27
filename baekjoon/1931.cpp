#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return (a.first < b.first);
    return a.second < b.second;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        int b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), compare);
    int time = v[0].second;
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        if (time <= v[i].first) {
            cnt++;
            time = v[i].second;
        }
    }

    cout << cnt;

    return 0;
}