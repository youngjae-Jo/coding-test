#include <iostream>
#include <algorithm>
using namespace std;
int L = -1, P = -1, V = -1;

int main() {
    int t = 1;
    int ans = 0;
    while (1) {
        cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0)
            return 0;
        //V�� �ް�, �����ϴ� P�� L�ϱ����� ����
        ans = (V / P) * L + min(L, V % P);
        cout << "Case " << t << ": " << ans << endl;

        ans = 0;
        t++;
    }

    return 0;
}