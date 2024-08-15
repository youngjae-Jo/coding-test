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
				if (i >= 1 && i <= N && j >= 1 && j <= N) {//���� ��, �ڱ� �ڽ� �ƴ�
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
				if (i >= 1 && i <= N && j >= 1 && j <= N) {//���� ��, �ڱ� �ڽ� �ƴ�
					if (classroom[i][j] == 0)
						count++;
				}
			}
		}
	}
	return count;
}

bool compare(pos a, pos b) {
	if (a.cnt != b.cnt) //�����ϴ� �л��� ���� ����
		return a.cnt > b.cnt;
	else if (a.emptyArea != b.emptyArea) //�ֺ��� ��ĭ�� ���� ����
		return a.emptyArea > b.emptyArea;
	else if (a.x != b.x) //���� ��
		return a.x < b.x;
	else //���� ��
		return a.y < b.y;
}

void sit_down(int num) {
	//����ִ� ĭ �߿��� �����ϴ� �л��� ������ ĭ�� ���� ���� ĭ����
	vector<pos> v;  //�ĺ���+�����ϴ� �л��� ����
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
		//������
		sit_down(num);
	}

	//������ ����
	res = satisfy();

	cout << res;
	return 0;
}