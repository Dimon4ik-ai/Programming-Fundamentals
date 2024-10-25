#include <iostream>
#include <string>
#include <cstdlib>  // Для функції rand()
#include <ctime>    // Для генерації випадкових чисел на основі часу

using namespace std;

int main() {

    int rows, cols;  // Змінні для кількості рядків і стовпців
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;
    // Створення двовимірного масиву (динамічного)
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    // Заповнення масиву випадковими числами від 0 до 99
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 100;  // Генерація випадкового числа в межах від 0 до 99
        }
    }

    // Виведення масиву на екран
    cout << "Двовимірний масив, заповнений випадковими числами:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << "\t";  // Виведення кожного елемента масиву
        }
        cout << endl;  // Перехід на новий рядок після кожного рядка
    }

    // Очищення пам'яті
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];  // Видаляємо кожен рядок
    }
    delete[] array;  // Видаляємо масив покажчиків

    // Знаходження останнього значення масиву
    int lastValue = array[rows - 1][cols - 1];
    cout << "\nОстаннє значення в масиві: " << lastValue << endl;

    return 0;
}