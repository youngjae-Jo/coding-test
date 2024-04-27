#include <iostream>
#include <queue>

using namespace std;
int map[1001][1001];
int visited[1001];
queue<int> q;
int N, M, V;


void DFS(int v) {
	visited[v] = 1;
	cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visited[i] == 0) {
			DFS(i);
		}
	}
}

void BFS(int v) {
	visited[v] = 1;
	cout << v << " ";

	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (map[v][i] == 1 && visited[i] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
				q.push(i);
				visited[i] = 1;
				cout << i << " ";
			}
		}
	}

}

int main() {
	cin >> N >> M >> V;
	int num, inter;

	for (int i = 0; i < M; i++) {
		cin >> num >> inter;
		map[num][inter] = 1;
		map[inter][num] = 1;
	}
	DFS(V);
	cout << endl;
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
	BFS(V);

	return 0;
}