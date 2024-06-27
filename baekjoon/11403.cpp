#include <iostream>
#include <vector>
using namespace std;

int N, S;

int main() {
    cin >> N >> S;
    vector<int> v(N);
    for (int i = 0; i < N; i++) #include <iostream>
#include <cstring>
		using namespace std;

	int N;
	int maap[100][100];
	bool visited[100];

	void dfs(int v) {
		for (int i = 0; i < N; i++) {
			if (!visited[i] && maap[v][i]) {
				visited[i] = true;
				dfs(i);
			}
		}
	}

	int main() {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> maap[i][j];
		}

		for (int i = 0; i < N; i++) {
			memset(visited, false, 100);
			dfs(i);
			for (int j = 0; j < N; j++) {
				if (visited[j])
					maap[i][j] = 1;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << maap[i][j] << " ";
			}
			cout << endl;
		}

		return 0;
	}
        cin >> v[i];
    }
    int start = 0, end = 0, sum = 0;
    int minLen = 100001;
    //연속된 수들의 부분합
    while (start <= end) {
        if (sum >= S) {
            minLen = min(minLen, end - start);
            sum -= v[start++];
        }
        else if (end == N)
            break;
        else
            sum += v[end++];
    }
    if (minLen > 100000)
        minLen = 0;
    cout << minLen;
    return 0;
}