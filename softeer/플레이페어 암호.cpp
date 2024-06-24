#include<iostream>
#include<string>

using namespace std;
string s;
string key;
int is_there[26] = { 0, }; //�־��� üũ

int main(int argc, char** argv)
{
    is_there[9] = 1; // J �Ⱦ���
    cin >> s;
    cin >> key;
    char maap[5][5]; //��ȣ�� by key
    int alpha_idx[25]; //�� ���Ĺ��� ��ȣ�� �� ��ġ
    int row_idx = 0;
    int col_idx = 0;

    //5*5�� ä��µ� ������ ���� ���ĺ��� �� �߸� �����ϰ� ���� ����
    for (int i = 0; i < key.size(); i++) { //��ȣ�� ����
        int tmp = key[i] - 'A';

        if (!is_there[tmp]) {

            maap[row_idx][col_idx] = key[i];
            alpha_idx[tmp] = row_idx * 5 + col_idx;
            is_there[tmp] = 1;
            col_idx++;
            if (col_idx == 5) {
                row_idx++;
                col_idx = 0;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!is_there[i]) {
            char c = 'A' + i;
            maap[row_idx][col_idx] = c;
            alpha_idx[i] = row_idx * 5 + col_idx;
            is_there[i] = 1;
            col_idx++;
            if (col_idx == 5) {
                row_idx++;
                col_idx = 0;
            }
        }
    }
    /*cout<<endl;
    cout<<maap[0][0] << maap[0][1] << maap[0][2] << maap[0][3] << maap[0][4]<<endl;
    cout<<maap[1][0] << maap[1][1] << maap[1][2] << maap[1][3] << maap[1][4]<<endl;
    cout<<maap[2][0] << maap[2][1] << maap[2][2] << maap[2][3] << maap[2][4]<<endl;
    cout<<maap[3][0] << maap[3][1] << maap[3][2] << maap[3][3] << maap[3][4]<<endl;
    cout<<maap[4][0] << maap[4][1] << maap[4][2] << maap[4][3] << maap[4][4]<<endl;
    */

    //�޼����� ��ȣȭ �ΰ��� ���� ������ ���ӵǸ� AA BC -> AX AB CX �̷�������, xx���� ���� XQ��, ���� ���ڸ��� X�� ���̱�
    for (int i = 0; 2 * i < s.size(); i++) {
        if (s.size() == 2 * i + 1) {
            s.append(1, 'X');
            break;
        }
        else if (s[2 * i] == s[2 * i + 1]) {
            if (s[2 * i] != 'X')
                s.insert(s.begin() + 2 * i + 1, 'X');
            else
                s.insert(s.begin() + 2 * i + 1, 'Q');
        }
    }
    //2���� ���, �ʿ��� ���� �࿡ �ִ� ��� -> ���� ���� ������ ����
    // ���� �� -> ���� ���� �Ʒ��� ������
    // �ٸ� �� �ٸ� ���̸� ���� ���� ����� �࿡ �ִ� ����
    for (int i = 0; 2 * i < s.size(); i++) {
        int idx1 = s[2 * i] - 'A';
        int idx2 = s[2 * i + 1] - 'A';
        int row1 = alpha_idx[idx1] / 5; int row2 = alpha_idx[idx2] / 5;
        int col1 = alpha_idx[idx1] % 5; int col2 = alpha_idx[idx2] % 5;
        if (row1 == row2) {
            int newCol1 = (col1 + 1) % 5;
            int newCol2 = (col2 + 1) % 5;
            s[2 * i] = maap[row1][newCol1];
            s[2 * i + 1] = maap[row2][newCol2];
        }
        else if (col1 == col2) {
            int newRow1 = (row1 + 1) % 5;
            int newRow2 = (row2 + 1) % 5;
            s[2 * i] = maap[newRow1][col1];
            s[2 * i + 1] = maap[newRow2][col2];
        }
        else {
            s[2 * i] = maap[row1][col2];
            s[2 * i + 1] = maap[row2][col1];
        }
    }

    cout << s;

    return 0;
}