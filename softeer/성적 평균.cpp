#include<iostream>
#include<vector>
#include<cmath>
#include <iomanip> 
using namespace std;
int N, K;

int main(int argc, char** argv)
{
    cin >> N >> K;
    vector<int> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];
    int sum = 0;
    double average = 0;
    for (int i = 0; i < K; i++) {
        int A, B;
        cin >> A >> B;

        for (int j = A - 1; j < B; j++) //A~B����
            sum += S[j];

        average = (double)(sum) / (B - A + 1); //�⺻���� ���
        average *= 100; //2�ڸ� �ø���
        average = round(average); //���⼭ ������ �Ǹ� �Ҽ� 3°¥��
        average /= 100; //������� ������

        cout << setprecision(2) << fixed; //fixed�� ���� setprecision�� �ε��Ҽ��� �ڸ��� �����ϵ���
        cout << average << "\n";

        sum = 0;//�ʱ�ȭ
        average = 0;
    }

    return 0;
}