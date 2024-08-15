#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int classroom[21][21]; //1~20, N,N
int student[401][4];

struct pos {
	int x = -1;
	int y = -1;
	int cnt = 0;
	int emptyArea = -1;
};

int is_satisfy(int num, int r, int c) {
	int count = 0;
	//r-1,c-1 / r-1, c / r-1, c+1
	for (int i = r - 1; i <= r + 1; i++) {
		for (int j = c - 1; j <= c + 1; j++) {
			if (abs(r - i) + abs(c - j) == 1) {
				if (i >= 1 && i <= N && j >= 1 && j <= N) {//범위 내, 자기 자신 아님
					if (classroom[i][j] == student[num][0] || classroom[i][j] == student[num][1] || classroom[i][j] == student[num][2] || classroom[i][j] == student[num][3])
						count++;
				}
			}
		}
	}
	return count;
}

int cnt_empty(int r, int c) {
	int count = 0;
	for (int i = r - 1; i <= r + 1; i++) {
		for (int j = c - 1; j <= c + 1; j++) {
			if (abs(r - i) + abs(c - j) == 1) {
				if (i >= 1 && i <= N && j >= 1 && j <= N) {//범위 내, 자기 자신 아님
					if (classroom[i][j] == 0)
						count++;
				}
			}
		}
	}
	return count;
}

bool compare(pos a, pos b) {
	if (a.cnt != b.cnt) //좋아하는 학생이 가장 많은
		return a.cnt > b.cnt;
	else if (a.emptyArea != b.emptyArea) //주변에 빈칸이 가장 많은
		return a.emptyArea > b.emptyArea;
	else if (a.x != b.x) //작은 행
		return a.x < b.x;
	else //작은 열
		return a.y < b.y;
}

void sit_down(int num) {
	//비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로
	vector<pos> v;  //후보지+좋아하는 학생수 정보
	int maax = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (classroom[i][j] != 0)
				continue;
			int cnt = is_satisfy(num, i, j);
			if (cnt >= maax) {
				int tmp = cnt_empty(i, j);
				v.push_back({ i, j, cnt, tmp });
			}
		}
	}
	sort(v.begin(), v.end(), compare);
	classroom[v[0].x][v[0].y] = num;
}

int satisfy() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cnt = is_satisfy(classroom[i][j], i, j);
			if (cnt != 0)
				ans += pow(10, cnt - 1);
		}
	}
	return ans;
}

int main() {
	int res = 0;
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int num = -1;
		cin >> num;
		for (int j = 0; j < 4; j++)
			cin >> student[num][j];
		//앉히기
		sit_down(num);
	}

	//만족도 총합
	res = satisfy();

	cout << res;
	return 0;
}