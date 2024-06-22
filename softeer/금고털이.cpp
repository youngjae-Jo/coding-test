#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int W, N;
vector<pair<int, int>>s;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> W >> N;

    int m, p;
    int idx = 0;
    int res = 0;

    for (int i = 1; i <= N; i++) {
        cin >> m >> p;
        pair<int, int> tmp = make_pair(m, p);
        s.push_back(tmp);
    }
    sort(s.begin(), s.end(), compare);

    for (idx; idx < N; idx++) {
        if (s[idx].first <= W) {
            res += (s[idx].second * s[idx].first);
            W -= s[idx].first;
        }
        else {
            res += (W * s[idx].second);
            break;
        }
    }
    cout << res;

    return 0;
}