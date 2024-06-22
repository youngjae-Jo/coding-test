#include<iostream>
#include<vector>
using namespace std;

int m, n;

int sum = 0;
int res = 0;
int maxCheck = 0; //사람 한명 움직이면서 벌어들인거 최댓값 확인용

int dx[4] = { -1, 1, 0, 0 }; int dy[4] = { 0, 0, -1, 1 };
int maap[21][21]; //문제 조건에서 1~N 
int tmp_maap[21][21];
int visited[21][21]; //문제 조건에서 1~N

struct friends {
    int pos_x = -1;
    int pos_y = -1;
};
vector<friends> f;
friends candi[3];
friends elected[3];

bool is_valid(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void move(int x, int y, int depth, int count) { //dfs기반으로 탐색
    //maxcheck 되는 곳이 여러개라면? -> 겹치는게 없는 쪽으로 가야됨
    if (depth == 3) { //3번 움직일 수 있으니까
        if (maxCheck <= count) {
            for (int i = 0; i < 3; i++) {
                elected[i].pos_x = candi[i].pos_x;
                elected[i].pos_y = candi[i].pos_y;
            }
            maxCheck = count;
        }
        return;
    }


    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            candi[depth].pos_x = nx; candi[depth].pos_y = ny;
            int crrnt = tmp_maap[nx][ny];
            tmp_maap[nx][ny] = 0;
            move(nx, ny, depth + 1, count + crrnt);
            visited[nx][ny] = 0;
            tmp_maap[nx][ny] = crrnt;
        }
    }
}

int check[3] = { 0,0,0 };
int fArray[3] = { -1,-1,-1 };

void pick_friend(int depth, int original_sum) { //순서 정하기
    if (depth == m) { //m명 순서 정했으면 순서대로 구하게 하기

        for (int k = 0; k < m; k++) { //구하기
            move(f[fArray[k]].pos_x, f[fArray[k]].pos_y, 0, 0);
            sum += maxCheck;

            maxCheck = 0;
            for (int i = 0; i < 3; i++) //이전 방문했던 곳 다 비우기, elected, candi는 초기화 필요없이 덮어씌우면 됨
                tmp_maap[elected[i].pos_x][elected[i].pos_y] = 0;
            for (int i = 1; i <= n; i++) { //visited 초기화
                for (int j = 1; j <= n; j++)
                    visited[i][j] = 0;
            }
        }
        if (res <= sum)
            res = sum;

        sum = original_sum; //복구
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                tmp_maap[i][j] = maap[i][j];
        }

        return;
    }
    for (int i = 0; i < m; i++) {
        if (!check[i]) {
            check[i] = 1;
            fArray[depth] = i;
            pick_friend(depth + 1, original_sum);
            check[i] = 0;
        }
    }
}