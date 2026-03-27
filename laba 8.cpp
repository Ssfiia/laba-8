#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Header.h"
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;
    int choice, N, K;
    do {
        cout << "\n ВЫБОР ЗАДАНИЯ " << endl;
        cout << "1. BackRec10: Архиолог." << endl;
        cout << "2. HomeDyn1: Черепешка." << endl;
        cout << "3. HomeDyn17: К-ичные числа." << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;
        switch (choice) {
        case 1:
            /*do {
                cout << "Введите количество найденных артефактов: ";
                cin >> N;
                if (N <= 1) cout << "Количество должно быть больше нуля." << endl;
            } while (N <= 1);*/
            createBackRec10();
            BackRec10();
            break;
        case 2:
            /*do {
                cout << "Введите размер доски: ";
                cin >> N;
                if (N <= 1 || N >= 80) cout << "Размер должен быть 1<N<80." << endl;
            } while (N <= 1 || N>=80);*/
            createHomeDyn1();
            HomeDyn1();
            break;
        case 3:
            int N, K;
            do {
                cout << "Введите основание системы счисления (2<=K<=10): ";
                cin >> K;
                cout << "Введите количество чисел (1<N<20): ";
                cin >> N;
                if ((K < 2 || K > 10) || (N <= 1 || N >= 20) || (N + K >= 26))
                    cout << "N+K должна быть меньше 26, но больше 3." << endl <<
                    "(2<K<10) И (1<N<20)." << endl;

            } while ((K < 2 ||K > 10) || (N <= 1 || N >= 20) || (N + K >= 26));
            HomeDyn17(N, K);
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
}