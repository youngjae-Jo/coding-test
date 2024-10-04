#include <iostream>
#include <vector>
using namespace std;

int N, K;
int plugged[100]; //�÷��� �������
int is_use[100]; //n�� ��ǰ�� ���� �ִ� ��
int order_i = 0;
vector<int> Order;

int dist(int curr, int p_idx) {//Order, plug �ε���
	int ans = 0;
	for (int i = curr; i < K; i++) {
		if (Order[i] == plugged[p_idx])
			break;
		else
			ans++;
	}

	return ans;
}

int main() {
	int cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		Order.push_back(tmp);
	}
	int idx = 0;
	//N�� ������ ���� �� ������ ���� �� ����
	//�ϳ������� idx, order_i �ö�
	//���� �־����� order_i �ö�
	for (order_i; order_i < K; order_i++) { //ó���� �ϴ� �Ǵ´�� �ȱ�

		if (!is_use[Order[order_i]]) {
			plugged[idx++] = Order[order_i];
			is_use[Order[order_i]] = 1;
		}
		if (idx == N) {
			idx--;
			break;
		}
	}

	for (int i = order_i + 1; i < K; i++) {
		int maxi = 0;
		int maxi_idx = 0;

		if (is_use[Order[i]]) continue; //�̹� ���������� �� �ʿ� ����

		for (int j = 0; j < N; j++) { //�÷��� ��� ���� �����
			int tmp = dist(i, j);
			if (tmp > maxi) {
				maxi = tmp;
				maxi_idx = j;
			}
		}
		int prev = plugged[maxi_idx];
		plugged[maxi_idx] = Order[i];
		is_use[prev] = 0;
		is_use[Order[i]] = 1;
		cnt++;
	}
	cout << cnt;
	return 0;
}