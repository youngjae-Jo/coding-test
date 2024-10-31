#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> v;
int ans = INT_MIN;

struct compare {
	bool operator()(pair<int, int> a, pair<int, int>b) {
		return a.second > b.second;
	}
};

void go_back(int idx) {
	//idx가 X에서 idx까지 가는데 걸리는 시간
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> to_X;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	int to_X_dist = 0;

	bool visited[1001];
	for (int i = 0; i <= N; i++) visited[i] = false;

	to_X.push({ idx,0 });
	while (!to_X.empty()) {
		pair<int, int> f = to_X.top();
		to_X.pop();
		visited[f.first] = true;

		if (f.first == X) {
			to_X_dist = f.second;
			break;
		}

		if (!v[f.first].empty()) {
			for (int i = 0; i < v[f.first].size(); i++) {
				if (!visited[v[f.first][i].first]) {
					to_X.push({ v[f.first][i].first, f.second + v[f.first][i].second });
				}
			}
		}
	}

	for (int i = 0; i <= N; i++) visited[i] = false;

	pq.push({ X,to_X_dist });
	while (!pq.empty()) {
		pair<int, int> f = pq.top();
		pq.pop();
		visited[f.first] = true;

		if (f.first == idx) {
			ans = max(ans, f.second);
			break;
		}

		if (!v[f.first].empty()) {
			for (int i = 0; i < v[f.first].size(); i++) {
				if (!visited[v[f.first][i].first]) {
					pq.push({ v[f.first][i].first, f.second + v[f.first][i].second });
				}
			}
		}
	}

}


int main() {
	cin >> N >> M >> X;
	v.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int start, end, t;
		cin >> start >> end >> t;

		pair<int, int> tmp;
		tmp.first = end;
		tmp.second = t;
		v[start].push_back(tmp);
	}

	//1~N 학생, X번에 모여있다가, 자기 위치로 돌아가야 됨
	for (int i = 1; i <= N; i++) {
		go_back(i);
	}

	cout << ans;

	return 0;
}