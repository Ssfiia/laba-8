#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

void BackRec10() {
    using namespace std;
    cout << "Выбор артефактов" << endl;
    ifstream fin("BackRec10_input.txt");
    if (!fin.is_open()) {
        cout << "Ошибка: не найден файл " << endl;
    }
    int N, Z;
    fin >> N >> Z;
    vector<int> c(N);
    vector<int> d(N);

    for (int i = 0; i < N; i++) fin >> c[i];
    for (int i = 0; i < N; i++) fin >> d[i];
    fin.close();
    int maxd = 0;
    for (int i = 0; i < N; i++) {
        maxd += d[i];
    }
    vector<int> dp(maxd + 1, 100000000);
    vector<vector<bool>> taken(maxd + 1, vector<bool>(N, false));

    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int t = maxd; t >= d[i]; t--) {
            if (dp[t - d[i]] != 100000000) {
                int newc = dp[t - d[i]] + c[i];
                if (newc < dp[t]) {
                    dp[t] = newc;
                    taken[t] = taken[t - d[i]];
                    taken[t][i] = true;
                }
            }
        }
    }
    int mind = 100000000;
    int bestc = 0;
    vector<bool> bestChoice(N, false);

    for (int t = 1; t <= maxd; t++) {
        if (dp[t] != 100000000 && dp[t] > Z) {
            if (t < mind) {
                mind = t;
                bestc = dp[t];
                bestChoice = taken[t];
            }
        }
    }
    ofstream fout("BackRec10_output.txt");
    cout << "Выбранные находки: ";
    fout << "Выбранные находки: ";

    bool first = true;
    for (int i = 0; i < N; i++) {
        if (bestChoice[i]) {
            if (!first) {
                cout << " ";
                fout << " ";
            }
            cout << i + 1;
            fout << i + 1;
            first = false;
        }
    }
    cout << "\nСуммарный вес: " << bestc << " кг" << endl;
    cout << "Общее налоговое бремя: " << mind << endl;
    fout << "\nСуммарный вес: " << bestc << " кг" << endl;
    fout << "Общее налоговое бремя: " << mind << endl;

    fout.close();
}

void HomeDyn1() {
    using namespace std;
    cout << "Черепашка" << endl;
    ifstream fin("HomeDyn1_input.txt");
    if (!fin.is_open()) {
        cout << "Ошибка: не найден файл " << endl;
    }

    int N;
    fin >> N;
    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> board[i][j];
        }
    }
    fin.close();
    vector<vector<int>> dp(N, vector<int>(N));
    dp[0][N - 1] = board[0][N - 1];
    for (int j = N - 2; j >= 0; j--) {
        dp[0][j] = dp[0][j + 1] + board[0][j];
    }
    for (int i = 1; i < N; i++) {
        dp[i][N - 1] = dp[i - 1][N - 1] + board[i][N - 1];
    }
    for (int i = 1; i < N; i++) {
        for (int j = N - 2; j >= 0; j--) {
            dp[i][j] = board[i][j] + max(dp[i - 1][j], dp[i][j + 1]);
        }
    }
    int answer = dp[N - 1][0];

    ofstream fout("HomeDyn1_output.txt");
    fout << answer << endl;
    fout.close();
    cout << "Максимальная сумма на пути: " << answer << endl;
}

void HomeDyn17(int N, int K) {
    using namespace std;
    cout << "K-ичные числа " << endl;
    cout << "Основание системы счисления K = " << K << endl;
    cout << "Количество разрядов N = " << N << endl;
    double a, b, c, _a, _b, _c;
    a = K - 1;
    b = 1;
    c = 0;
    for (int i = 2; i <= N; i++) {
        _a = a;
        _b = b;
        _c = c;
        a = (_a + _b + c) * (K - 1);
        b = _a;
        c = _b;
    }
    double res = a + b + c;
    cout.precision(0);
    cout << fixed << "Количество " << K << "-ичных чисел из " << N << " разрядов: " << res << endl;
}

void createBackRec10() {
    using namespace std;
    ofstream fout("BackRec10_input.txt");
    srand(time(0));
    int N = 10 + rand() % 11;
    int Z = 30 + rand() % 50; 
    fout << N << " " << Z << endl;
    cout << "Задача 1: \nВеса артефактов: ";
    for (int i = 0; i < N; i++) {
        int c = 1+ rand() % 40;
        fout << setw(3) << c << " ";
        cout << setw(3) << c << " ";
    }
    fout << endl;
    cout << endl;
    cout << "Налоговое бремя: ";
    for (int i = 0; i < N; i++) {
        int d = 1 + rand() % 20;
        fout << setw(3) << d << " ";
        cout << setw(3) << d << " ";
    }
    fout << endl;
    cout << endl;
    fout.close();
    cout << "N = " << N << ", Z = " << Z << " кг" << endl;
}

void createHomeDyn1() {
    using namespace std;
    ofstream fout("HomeDyn1_input.txt");
    srand(time(0));
    int N = 5 + rand() % 10;
    fout << N << endl;
    cout << "Задача 2: \nДоска " << N << "x" << N << ":" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int v = rand() % 100; 
            fout << setw(3) << v << " ";
            cout << " " << setw(3) << v << " ";
        }
        fout << endl;
        cout << endl;
    }
    fout.close();
}

