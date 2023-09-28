#include <iostream>
#include <vector>

using namespace std;

int maxBlock = 0;
int N;

//이동가능 방향은 상하좌우
//사용자 입장에서는 1024가지 선택지
//합쳐지는건 한번에 한가지 -> 몇가지 없음(직전에 이웃한 애들만 합쳐짐)

void upMove(vector<vector<int>>& map) {//위에서부터 내려오면서 합칠 거 있으면 합쳐야됨
    int sameN = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (map[j][i] == 0) {
                int count = 1;
                while (j + count < N && map[j + count][i] == 0)
                    count++;
                for (int k = 0; k < count; k++) {
                    if (j + k + count < N) {
                        map[j + k][i] = map[j + k + count][i];
                        map[j + k + count][i] = 0;
                    }
                }
            }
        }
    }//합치고 땡기기까지 하고 다음 인덱스로
    for (int i = 0; i < N; i++) {
        sameN = 0;
        for (int j = 0; j < N - 1; j++) {
            if (map[j][i]!= 0 && map[j][i] == map[j + 1][i]) {
                map[j][i] *= 2;
                sameN++;
                for(int z = 0; j+z+2<N; z++){
                    map[j+1+z][i]=map[j+2+z][i];
                }
                map[N-sameN][i] = 0;
            }
        }
    }
}


void downMove(vector<vector<int>>& map) {
    int sameN = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (map[N - 1 - j][i] == 0) {
                int count = 1;
                while (N - 1 - j - count > 0 && map[N - 1 - j - count][i] == 0)
                    count++;
                for (int k = 0; k < count; k++) {
                    if (N - 1 - j - k - count >= 0) {
                        map[N - 1 - j - k][i] = map[N - 1 - j - k - count][i];
                        map[N - 1 - j - k - count][i] = 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        sameN = 0;
        for (int j = 0; j < N - 1; j++) {       
            if (map[N - 1 - j][i]!=0&&map[N - 1 - j][i] == map[N - 1 - j - 1][i]) {
                map[N - 1 - j][i] *= 2;
                sameN++;
                for(int z = 0; j+z+2<N; z++){
                    map[N-1-j-1-z][i]=map[N-1-j-2-z][i];
                }
                map[sameN-1][i] = 0;
            }
        }
    }

}

void leftMove(vector<vector<int>>& map) {//up이랑 같은 구조
    int sameN = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (map[i][j] == 0) {
                int count = 1;
                while (j + count < N && map[i][j+count] == 0)
                    count++;
                for (int k = 0; k < count; k++) {
                    if (j + k + count < N) {
                        map[i][j + k] = map[i][j + k + count];
                        map[i][j + k + count] = 0;
                    }
                }
            }
        }
    }//합치고 땡기기까지 하고 다음 인덱스로
    for (int i = 0; i < N; i++) {
        sameN = 0;
        for (int j = 0; j < N - 1; j++) {
            if (map[i][j]!= 0 && map[i][j] == map[i][j+1]) {
                map[i][j] *= 2;
                sameN++;
                for(int z = 0; j+z+2<N; z++){
                    map[i][j+1+z]=map[i][j+2+z];
                }
                map[i][N-sameN] = 0;
            }
        }
    }
}

void rightMove(vector<vector<int>>& map) { //down이랑 같은 구조
    int sameN = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (map[i][N - 1 - j] == 0) {
                int count = 1;
                while (N - 1 - j - count > 0 && map[i][N - 1 - j - count] == 0)
                    count++;
                for (int k = 0; k < count; k++) {
                    if (N - 1 - j - k - count >= 0) {
                        map[i][N - 1 - j - k] = map[i][N - 1 - j - k - count];
                        map[i][N - 1 - j - k - count] = 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        sameN = 0;
        for (int j = 0; j < N - 1; j++) {       
            if (map[i][N - 1 - j]!=0&&map[i][N - 1 - j] == map[i][N - 1 - j - 1]) {
                map[i][N - 1 - j] *= 2;
                sameN++;
                for(int z = 0; j+z+2<N; z++){
                    map[i][N-1-j-1-z]=map[i][N-1-j-2-z];
                }
                map[i][sameN-1] = 0;
            }
        }
    }
}


int playGame(vector<vector<int>>& map, int cnt) {
    if (cnt == 5) {
        int currentMaxBlock = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] > currentMaxBlock)
                    currentMaxBlock = map[i][j];
            }
        }
        return currentMaxBlock;
    }
   
    for (int way = 0; way < 4; way++) {
       vector<vector<int>> mapCopy = map;
       switch (way) {
            case 0:
                upMove(mapCopy);
                break;
            case 1:
                downMove(mapCopy);
                break;
            case 2:
                leftMove(mapCopy);
                break;
            case 3:
                rightMove(mapCopy);
                break;
       }
        int currentMaxBlock = playGame(mapCopy, cnt + 1);
        if (currentMaxBlock > maxBlock) {
            maxBlock = currentMaxBlock;
        }
    }
    return maxBlock;
}

int main() {
    cin >> N;
    if (N == 1) {
        int m = 0;
        cin >> m;
        cout << m;
        return 0;
    }
    vector<vector<int>> board(21, vector<int>(21, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int maxBlock = playGame(board, 0);
    cout << maxBlock;
    return 0;
}