#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
using namespace std;


class Fish {
public:
	int num, dir, r, c;
	bool live;
	Fish() {}
	Fish(int _n, int _d, int _r, int _c, bool _live) {
		num = _n;
		dir = _d;
		r = _r;
		c = _c;
		live = _live;
	}
};

Fish fishArr[17];	//����� 1~ 16������ ��ü ����
int map[4][4];		//����� ��ȣ�� ����

//12,11,9,,,
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,-1,-1,-1,0,1,1,1 };


int ret = 0;

//�迭�� �Լ��� �Ķ���ͷ� �ѱ�� Call By Reference (�ּҰ��� �Ѿ)
void solveDFS(int map[][4], Fish fishArr[], int shark_row, int shark_col, int s) {

	//��Ʈ��ŷ�� ���� ���� �迭 ���ΰ� ī���ؼ� ���º�ȭ ���Ѻ�
	int copy_map[4][4];
	Fish copy_fishArr[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < 17; i++) {
		copy_fishArr[i] = fishArr[i];
	}


	//����� ��ƸԱ�
	int fishNum = copy_map[shark_row][shark_col];
	int shark_dir = copy_fishArr[fishNum].dir;				//��Ƹ��� ����� �������� �ٲ�
	copy_fishArr[fishNum].live = false;
	copy_map[shark_row][shark_col] = -1;						//����� ��ƸԾ ����� ������

	s += fishNum;
	if (ret < s) ret = s;




	//����� �̵�
	for (int f = 1; f <= 16; f++) {
		if (copy_fishArr[f].live == false) continue;

		//���� ������ ������� ��ġ
		int cr = copy_fishArr[f].r;
		int cc = copy_fishArr[f].c;
		int cd = copy_fishArr[f].dir;

		//�ٲ� Ÿ���� ��ġ
		int nr = cr + dr[cd];
		int nc = cc + dc[cd];
		int nd = cd;

		//Ÿ���� ���� �Ѿ�ų� ���� ȸ��
		while (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || (nr == shark_row && nc == shark_col)) {
			nd = (nd + 1) % 8;
			nr = cr + dr[nd];
			nc = cc + dc[nd];
		}

		//1. Ÿ�� ĭ�� ������

		if (copy_map[nr][nc] != -1) {
			int targetFishNum = copy_map[nr][nc];
			//Ÿ�� ����� ��ġ ����
			copy_fishArr[targetFishNum].r = cr;
			copy_fishArr[targetFishNum].c = cc;

			//���� ����� ��ġ ����
			copy_fishArr[f].r = nr;
			copy_fishArr[f].c = nc;
			copy_fishArr[f].dir = nd;

			//������ �迭 ��ȣ swap
			copy_map[nr][nc] = f;
			copy_map[cr][cc] = targetFishNum;

		}


		//2. Ÿ�� ĭ�� ��ĭ�̸�
		else {

			copy_fishArr[f].r = nr;
			copy_fishArr[f].c = nc;
			copy_fishArr[f].dir = nd;

			copy_map[nr][nc] = f;
			copy_map[cr][cc] = -1;			//���� ����� �ִ� ĭ�� ����� ������ 

		}

	}


	//��� �̵�
	for (int step = 1; step <= 3; step++) {
		int nr = shark_row + dr[shark_dir] * step;
		int nc = shark_col + dc[shark_dir] * step;

		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) break;

		if (copy_map[nr][nc] != -1) {
			solveDFS(copy_map, copy_fishArr, nr, nc, s);
		}
	}




}



int main() {

	int n, d;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			cin >> n >> d;
			Fish fish = Fish(n, d - 1, i, j, true);
			map[i][j] = n;		//2���� �迭�� ����
			fishArr[n] = fish;			//����� ��ü �迭�� �ֱ�

		}
	}



	//��� �ʱ� ����
	ret = 0;
	solveDFS(map, fishArr, 0, 0, 0);
	cout << ret;

	return 0;

}