#include<iostream>

//1000000007
using namespace std;

int main(int argc, char** argv)
{
    unsigned long long K, P, N, ans = 0;
    cin >> K >> P >> N;
    //1�ʴ� P��, ó�� K����, N�� �Ŀ���?
    for (int i = 0; i < N; i++) {
        K *= (P % 1000000007);
        K %= 1000000007;
    }
    cout << K;
    return 0;
}