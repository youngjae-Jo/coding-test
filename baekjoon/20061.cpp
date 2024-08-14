#include <iostream>

using namespace std;

int N;
int score = 0;
int blue[4][6];
int green[6][4];

bool is_possible(int x, int y, int mode) {
	if (mode == 1) //�Ķ�
		return (x >= 0 && x <= 3 && y >= 0 && y <= 5 && blue[x][y] == 0);
	else if (mode == 3) //�Ķ��ε� 2*1
		return ((x >= 0 && x <= 3 && y >= 0 && y <= 5 && blue[x][y] == 0) && (x + 1 >= 0 && x + 1 <= 3 && y >= 0 && y <= 5 && blue[x + 1][y] == 0));

	else if (mode == 2)//�ʷ�
		return (x >= 0 && x <= 5 && y >= 0 && y <= 3 && green[x][y] == 0);
	else if (mode == 4) //�ʷ��ε� 2*1
		return ((x >= 0 && x <= 5 && y >= 0 && y <= 3 && green[x][y] == 0) && (x >= 0 && x <= 5 && y + 1 >= 0 && y + 1 <= 3 && green[x][y + 1] == 0));
	return false;
}


void toBlue(int t, int x, int y) {
	int y_check = 0;

	switch (t) { //x�� �״�� y�� �ٲ�鼭 ��
	case 1: //	t = 1: ũ�Ⱑ 1��1�� ����� (x, y)�� ���� ���
		while (is_possible(x, y_check++, 1)) {}
		blue[x][y_check - 2] = 1;
		break;
	case 2: //	t = 2: ũ�Ⱑ 1��2�� ����� (x, y), (x, y+1)�� ���� ���
		y_check = 1;
		while (is_possible(x, y_check++, 1)) {}
		blue[x][y_check - 3] = 1;
		blue[x][y_check - 2] = 1;
		break;
	case 3: //	t = 3: ũ�Ⱑ 2��1�� ����� (x, y), (x+1, y)�� ���� ���
		while (is_possible(x, y_check++, 3)) {}
		blue[x][y_check - 2] = 1;
		blue[x + 1][y_check - 2] = 1;
		break;
	default:
		break;
	}

	//�Ķ����� �� ������ ������ ����-> ���� ���� 1�� �߰�, 
	for (int i = 5; i >= 0; i--) {//��
		int flag = 1;
		for (int j = 0; j < 4; j++) {
			if (blue[j][i] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			if (i != 0) {
				for (int j = 0; j < 4; j++) {
					if (blue[j][i - 1] == 0) {
						flag = 0;
						break;
					}
				}
				if (flag == 1)
					flag = 2;
				else if (flag == 0)
					flag = 1;
			}
			if (flag == 1) {
				for (int j = 0; j < 4; j++) {//����
					blue[j][i] = 0;
				}
				for (int k = i - 1; k >= 0; k--) {
					for (int z = 0; z < 4; z++) {
						blue[z][k + 1] = blue[z][k];
					}
				}

				score++;
			}
			else if (flag == 2) {
				for (int j = 0; j < 4; j++) {//����
					blue[j][i] = 0;
					blue[j][i - 1] = 0;
				}
				for (int k = i - 2; k >= 0; k--) {
					for (int z = 0; z < 4; z++) {
						blue[z][k + 2] = blue[z][k];
					}
				}

				score += 2;
			}
		}
	}

	//�߰� ���뿡 ������ ���������� �б� ,�Ķ����� ��� ���� ������ �ű⿡ 1*2�� ���� �� ����
	int middle_area = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j < 4; j++) {
			if (blue[j][i] == 1) {
				middle_area++;
				break;
			}
		}
	}
	//if (y_check - 2 == 1) {
	if (middle_area == 2) {
		if (blue[x][2] == 1 && t == 2) {//2ĭ�б�
			for (int i = 0; i < 4; i++) {
				for (int j = 3; j >= 0; j--) {
					blue[i][j + 2] = blue[i][j];
				}
			}
		}
	}
	else if (middle_area == 1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 4; j >= 0; j--) {
				blue[i][j + 1] = blue[i][j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {//�а��� �߰����� 0����
		for (int j = 0; j < 2; j++)
			blue[i][j] = 0;
	}
}

void toGreen(int t, int x, int y) {

	int x_check = 0;

	switch (t) { //x�� �״�� y�� �ٲ�鼭 ��
	case 1: //	t = 1: ũ�Ⱑ 1��1�� ����� (x, y)�� ���� ���
		while (is_possible(x_check++, y, 2)) {}
		green[x_check - 2][y] = 1;
		break;
	case 2: //	t = 2: ũ�Ⱑ 1��2�� ����� (x, y), (x, y+1)�� ���� ���
		x_check = 1;
		while (is_possible(x_check++, y, 4)) {}
		green[x_check - 2][y] = 1;
		green[x_check - 2][y + 1] = 1;
		break;
	case 3: //	t = 3: ũ�Ⱑ 2��1�� ����� (x, y), (x+1, y)�� ���� ���
		while (is_possible(x_check++, y, 2)) {}
		green[x_check - 3][y] = 1;
		green[x_check - 2][y] = 1;
		break;
	default:
		break;
	}
	//�����, �ѹ� �Ű�µ� �ѹ��� �Űܾ��ϴ°��(g,b���), i,i+1 ������ ���
	for (int i = 5; i >= 0; i--) {//��
		int flag = 1;
		for (int j = 0; j < 4; j++) {
			if (green[i][j] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			if (i != 0) {
				for (int j = 0; j < 4; j++) {
					if (green[i - 1][j] == 0) {
						flag = 0;
						break;
					}
				}
				if (flag == 1)
					flag = 2;
				else if (flag == 0)
					flag = 1;
			}
			if (flag == 1) {
				for (int j = 0; j < 4; j++) {//����
					green[i][j] = 0;
				}
				for (int k = i - 1; k >= 0; k--) {
					for (int z = 0; z < 4; z++) {
						green[k + 1][z] = green[k][z];
					}
				}
				score++;
			}
			else if (flag == 2) {//�ι� pop
				for (int j = 0; j < 4; j++) {//����
					green[i][j] = 0;
					green[i - 1][j] = 0;
				}
				for (int k = i - 2; k >= 0; k--) {
					for (int z = 0; z < 4; z++) {
						green[k + 2][z] = green[k][z];
					}
				}
				score += 2;
			}
		}
	}
	int middle_area = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j] == 1) {
				middle_area++;
				break;
			}
		}
	}

	//�߰� ���뿡 ������ �Ʒ������� �б�
	if (middle_area == 2) {
		if (green[2][y] == 1 && t == 3) {//2ĭ�б�
			for (int i = 0; i < 4; i++) {
				for (int j = 3; j >= 0; j--) {
					green[j + 2][i] = green[j][i];
				}
			}
		}
	}
	else if (middle_area == 1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 4; j >= 0; j--) {
				green[j + 1][i] = green[j][i];
			}
		}
	}


	for (int i = 0; i < 2; i++) {//�а��� �߰����� 0����
		for (int j = 0; j < 4; j++)
			green[i][j] = 0;
	}
}

int main() {
	cin >> N; //����� ���� Ƚ��
	for (int i = 0; i < N; i++) {
		int t, x, y;
		cin >> t >> x >> y;

		toBlue(t, x, y);
		toGreen(t, x, y);
	}
	int area = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j < 6; j++) {
			if (blue[i][j] == 1) area++;
			if (green[j][i] == 1) area++;
		}
	}

	//���
	cout << score << endl << area;

	return 0;
}