#include <iostream>
#include <cstring>

using namespace std;

int sushi[30001];
int ate[3001];

int main() {
	//N�� ����, �ʹ� ������ d, �����ؼ� �Դ� k���� ����, ���� ��ȣ c
	int N, d, k, c;
	int maxi = -1;
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		int coupon = 1; //������ �߰��ؾ� �ϴϱ� �ϴ� �� �ش� ����
		for (int j = i; j < i + k; j++) {
			if (ate[sushi[j % N]] == 1)
				cnt++;
			else
				ate[sushi[j % N]] = 1;
			if (sushi[j % N] == c) //k�� ������ �� ������ ����
				coupon = 0;
		}
		maxi = max(maxi, k - cnt + coupon); //k�� �߿��� cnt�� ��ġ�� coupon��ŭ �� ��
		memset(ate, 0, sizeof(ate));
	}
	cout << maxi;
	//k�� �������� ������ ����, ������ ���� c�� ��¥�� �߰�(��Ʈ ���� ������ ����)
	//�پ��� ������ ��ǥ
	return 0;
}