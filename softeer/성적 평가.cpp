#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;
int N;
struct info {
    int score = 0; //���� ����
    int num = -1; //��� ����̾�����
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
        int array[100000]; //�ѹ��� i�� ����� �̹� ȸ���� ����
        memset(array, 0, sizeof(array));

        for (int i = 0; i < N; i++) {//�Է�
            int s = 0;
            cin >> s;
            info tmp;
            tmp.score = s;
            tmp.num = i;
            grade.push_back(tmp);
            total[i].score += s;
            total[i].num = i;
        }

        sort(grade.begin(), grade.end(), compare);//ó��
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

        for (int i = 0; i < N; i++)//���
            cout << array[i] << " ";
        cout << endl;
    }

    int final[100000];
    int final_array[100000];
    memset(final, 0, sizeof(final));
    sort(total.begin(), total.end(), compare); //���� ���� ���ϱ�
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

    for (int i = 0; i < N; i++)//��� 
        cout << final_array[i] << " ";

    //cout << endl<<endl;
    //for(int i = 0; i<N; i++)//���
        //cout<<"num = "<<total[i].num << ", score = "<< total[i].score << " ";

    return 0;
}