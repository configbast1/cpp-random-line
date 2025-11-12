#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    ofstream fout("data.txt");
    if (!fout) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return 1;
    }

    for (int i = 1; i <= 10; i++) {
        fout << "Строка номер " << i << endl;
    }
    fout.close();

    srand(time(0));
    int randomLine = rand() % 10 + 1;

    ifstream fin("data.txt");
    if (!fin) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        return 1;
    }

    string line;
    int count = 0;
    while (getline(fin, line)) {
        count++;
        if (count == randomLine) {
            cout << "Случайная строка: " << line << endl;
            break;
        }
    }

    fin.close();
    return 0;
}
