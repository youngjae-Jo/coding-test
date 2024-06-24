#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
vector<int> F;

bool compare(int a, int b) {
    return a < b;
}

int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        F.push_back(v);
    }
    //������ F_a*F_b �� �ִ밪, -1
    sort(F.begin(), F.end(), compare);
    //���� ������ ��� �������� �� �ΰ���
    //���� �Ѱ� -> ���� 2��
    int res = -10000;
    int last = F.size();
    if (n == 2)
        res = F[0] * F[1];
    else if (F[0] < 0 && F[1] < 0)
        res = max(F[0] * F[1], F[last - 1] * F[last - 2]);
    else
        res = F[last - 1] * F[last - 2];
    cout << res;

    return 0;
}