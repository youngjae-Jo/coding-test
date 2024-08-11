#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;
int N;
struct info {
    int score = 0; //받은 점수
    int num = -1; //몇번 사람이었는지
};

bool compare(info a, info b) {
    return (a.score > b.score);
}

bool compare2(info a, info b) {
    return (a.score < b.score);
}

int main(int argc, char** argv)
{
    cin >> N;
    vector<info> total(N);
    for (int t = 1; t <= 3; t++) {
        vector<info> grade;
        int array[100000]; //넘버가 i인 사람의 이번 회차의 순위
        memset(array, 0, sizeof(array));

        for (int i = 0; i < N; i++) {//입력
            int s = 0;
            cin >> s;
            info tmp;
            tmp.score = s;
            tmp.num = i;
            grade.push_back(tmp);
            total[i].score += s;
            total[i].num = i;
        }

        sort(grade.begin(), grade.end(), compare);//처리
        for (int i = 0; i < N; i++) {
            int count = 1 + i;
            int idx = i - 1;
            while (idx >= 0) {
                if (grade[idx].score == grade[i].score) {
                    count--;
                    idx--;
                }
                else
                    break;
            }
            array[grade[i].num] = count;
        }

        for (int i = 0; i < N; i++)//출력
            cout << array[i] << " ";
        cout << endl;
    }

    int final[100000];
    int final_array[100000];
    memset(final, 0, sizeof(final));
    sort(total.begin(), total.end(), compare); //최종 순위 구하기
    for (int i = 0; i < N; i++) {
        int count = 1 + i;
        int idx = i - 1;
        while (idx >= 0) {
            if (total[idx].score == total[i].score) {
                count--;
                idx--;
            }
            else
                break;
        }
        final_array[total[i].num] = count;
    }

    for (int i = 0; i < N; i++)//출력 
        cout << final_array[i] << " ";

    //cout << endl<<endl;
    //for(int i = 0; i<N; i++)//출력
        //cout<<"num = "<<total[i].num << ", score = "<< total[i].score << " ";

    return 0;
}