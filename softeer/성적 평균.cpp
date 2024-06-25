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

        for (int j = A - 1; j < B; j++) //A~B까지
            sum += S[j];

        average = (double)(sum) / (B - A + 1); //기본적인 계산
        average *= 100; //2자리 올리기
        average = round(average); //여기서 정수로 되면 소수 3째짜리
        average /= 100; //원래대로 돌리기

        cout << setprecision(2) << fixed; //fixed를 쓰면 setprecision이 부동소수점 자리만 설정하도록
        cout << average << "\n";

        sum = 0;//초기화
        average = 0;
    }

    return 0;
}