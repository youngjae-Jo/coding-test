#include<iostream>
#include<vector>

using namespace std;
int P, N; //���� ���̷����� �ʴ� P��

int main(int argc, char** argv)
{
    long long res = 0;
    cin >> P >> N;
    for (int i = 0; i < N; i++) {
        long long amount = 0;
        cin >> amount;
        res = (res * P) % 1000000007;
        res += amount;
    }

    cout << res;
    return 0;
}