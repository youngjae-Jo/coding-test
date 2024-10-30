#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

int N, K;
//시작점 X, 걷거나 순간이동, 걷기 X-1, X+1, 순간이동 2*X
struct info {
	int loc;
	int time;
};
queue<info> q;
int dist[100001];
int previous[100001];

int main() {
	int t = 0;
	cin >> N >> K;

	for (int i = 0; i <= 100000; i++) {
		dist[i] = INT_MAX;
		previous[i] = -1;
	}
	dist[N] = 0;

	q.push({ N, 0 });
	while (!q.empty()) {
		info f = q.front();
		q.pop();
		if (f.loc == K) {
			cout << f.time;
			break;
		}

		if (f.loc - 1 >= 0 && dist[f.loc - 1] > f.time + 1) {
			dist[f.loc - 1] = f.time + 1;
			q.push({ f.loc - 1, f.time + 1 });
			previous[f.loc - 1] = f.loc;
		}
		if (f.loc + 1 <= 100000 && dist[f.loc + 1] > f.time + 1) {
			dist[f.loc + 1] = f.time + 1;
			q.push({ f.loc + 1, f.time + 1 });
			previous[f.loc + 1] = f.loc;
		}
		if (2 * f.loc <= 100000 && dist[2 * f.loc] > f.time + 1) {
			dist[2 * f.loc] = f.time + 1;
			q.push({ 2 * f.loc, f.time + 1 });
			previous[2 * f.loc] = f.loc;
		}

	}
	vector<int> path;
	for (int i = K; i != -1; i = previous[i]) path.push_back(i);
	reverse(path.begin(), path.end());

	cout << endl;
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";

	return 0;
}