#include <iostream>
#include <string>
#include <cstdlib>  // ��� ������� rand()
#include <ctime>    // ��� ��������� ���������� ����� �� ����� ����

using namespace std;

int main() {

    int rows, cols;  // ����� ��� ������� ����� � ��������
    cout << "������ ������� �����: ";
    cin >> rows;
    cout << "������ ������� ��������: ";
    cin >> cols;
    // ��������� ����������� ������ (����������)
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    // ������������ ���������� ���������� �����
    srand(time(0));

    // ���������� ������ ����������� ������� �� 0 �� 99
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 100;  // ��������� ����������� ����� � ����� �� 0 �� 99
        }
    }

    // ��������� ������ �� �����
    cout << "���������� �����, ���������� ����������� �������:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << "\t";  // ��������� ������� �������� ������
        }
        cout << endl;  // ������� �� ����� ����� ���� ������� �����
    }

    // �������� ���'��
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];  // ��������� ����� �����
    }
    delete[] array;  // ��������� ����� ���������

    // ����������� ���������� �������� ������
    int lastValue = array[rows - 1][cols - 1];
    cout << "\n������� �������� � �����: " << lastValue << endl;

    return 0;
}