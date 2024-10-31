#include<iostream>

//1000000007
using namespace std;

int main(int argc, char** argv)
{
    unsigned long long K, P, N, ans = 0;
    cin >> K >> P >> N;
    //1초당 P배, 처음 K마리, N초 후에는?
    for (int i = 0; i < N; i++) {
        K *= (P % 1000000007);
        K %= 1000000007;
    }
    cout << K;
    return 0;
}