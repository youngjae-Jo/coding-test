#include<iostream>
#include <algorithm>
#include<climits>

using namespace std;
int N, M, K; //���� ���� N��, �ù� �ٱ��� ���� M, ���ϴ� Ƚ�� K
int W[10];
int ans = INT_MAX;

int main(int argc, char** argv)
{
    //�Է�
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> W[i];
    sort(W, W + N);
    do {
        int cur = 0, work = 0;
        for (int i = 0; i < K; i++) {
            int r = M;
            while (1) {
                r -= W[cur];
                if (r < 0) break;
                work += W[cur++];
                cur %= N;
            }
        }
        ans = min(ans, work);
    } while (next_permutation(W, W + N));
    //���ؾ��ϴ� �ּ����� �ù� ����
    cout << ans;

    return 0;
}