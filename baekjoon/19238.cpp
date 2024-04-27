#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
//���� ���� ���� Ʋ��
using namespace std;
int N, M, energy;
int state[21][21];

struct pos {
	int x = -1;
	int y = -1;
	int alive = 1;
};

struct info {
	int x;
	int y;
	int Dist;
	int num;
};

pos baek;
pos psg[400][2];
int mini = 9999;
int curr_mini = 9999;
int mins_idx = 0;
int tmp = -1;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dist(int a, int b, int c, int d) {
	queue<pair <pair<int, int>, int>> q;
	q.push({ { a,b }, 0 });
	int visited[21][21] = { 0 };
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			visited[i][j] = 0;
		}
	}


	visited[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int distance = q.front().second;
		q.pop();

		if (distance > curr_mini)//�߰� Ž�� ����
			return curr_mini;
		if (x == c && y == d) {
			if (distance <= curr_mini)
				curr_mini = distance;
			return curr_mini;
		}
		for (int i = 0; i < 4; i++) {
			int newRow = x + dx[i];
			int newCol = y + dy[i];
			if (newRow >= 1 && newRow <= N && newCol >= 1 && newCol <= N) {
				if (!state[newRow][newCol] && !visited[newRow][newCol]) {
					visited[newRow][newCol] = 1;
					q.push({ {newRow, newCol}, distance + 1 });
				}
			}
		}


	}
	return -1;
}



int is_end() {
	if (mini == -1)
		return 1;

	for (int i = 0; i < M; i++) {
		if (psg[i][0].alive) {
			return 0;
		}
	}
	return 1;
}

bool compare(info a, info b) {
	if (a.Dist != b.Dist) {
		return a.Dist < b.Dist; // Dist�� ���� ������� ����
	}
	if (a.x != b.x) {
		return a.x < b.x; // x�� ���� ������� ����
	}
	return a.y < b.y; // y�� ���� ������� ����
}

void find_nearest() {//��ġ�°� ���� ���� �켱��������ؾߵ�
	vector<info> v;
	for (int i = 0; i < M; i++) {
		if (psg[i][0].alive) {
			tmp = dist(psg[i][0].x, psg[i][0].y, baek.x, baek.y);
			info curr = { psg[i][0].x, psg[i][0].y, tmp, i };
			v.push_back(curr);

			//dist �ٽ� ������ �ʱ�ȭ
			curr_mini = 9999;

		}
	}


	sort(v.begin(), v.end(), compare);
	mini = v[0].Dist;
	mins_idx = v[0].num;

}

void solve() {

	while (1) {
		//���� ����� �մ� ã��
		find_nearest();
		//�Ÿ���ŭ ���� ��(�ٵǸ� -1)
		energy -= mini;
		if (energy <= 0 || is_end()) {
			cout << "-1";
			return;
		}
		//�����������Ÿ���ŭ���ứ�� alive = 0, �ٵǸ� -1, �ƴϸ� ���� 2��
		tmp = dist(psg[mins_idx][0].x, psg[mins_idx][0].y, psg[mins_idx][1].x, psg[mins_idx][1].y);
		curr_mini = 9999;

		baek.x = psg[mins_idx][1].x;
		baek.y = psg[mins_idx][1].y;
		psg[mins_idx][0].alive = 0; //����
		if (energy >= tmp) {//����
			energy += tmp;
			if (is_end()) {
				cout << energy;
				return;
			}

		}
		/*else if (energy == tmp) {//������?
			if (is_end()) {
				cout << tmp;
				return;
			}
		}*/
		else {//����
			cout << "-1";
			return;
		}
		//�ʱ�ȭ
		mini = 9999; mins_idx = 0; tmp = -1;
	}

}

int main() {
	cin >> N >> M >> energy;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> state[i][j];//����
		}
	}
	cin >> baek.x >> baek.y;//���� ���� �࿭
	for (int i = 0; i < M; i++) {//i��° �°� ������, ������
		cin >> psg[i][0].x >> psg[i][0].y >> psg[i][1].x >> psg[i][1].y;
	}
	solve();


	return 0;
}