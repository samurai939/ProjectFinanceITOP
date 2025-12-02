#include "finance.h"
#include <iostream>
#include <fstream>
using namespace std;
Transaction trans[MAX_TRANS];
int trans_count = 0;
void init() {
    trans_count = 0;
    cout << "Система запущена!" << endl;
}
void add_trans() {
    if (trans_count >= MAX_TRANS) {
        cout << "Нельзя добавить больше транзакций!" << endl;
        return;
    }
    cout << "Описание: ";
    cin.ignore();
    cin.getline(trans[trans_count].desc, 50);

    cout << "Сумма: ";
    cin >> trans[trans_count].amount;

    cout << "Тип (1=доход, 0=расход): ";
    cin >> trans[trans_count].type;

    trans[trans_count].id = trans_count + 1;
    trans_count++;

    cout << "Добавлено! ID: " << trans_count << endl;
}
void show_all() {
    if (trans_count == 0) {
        cout << "Нет транзакций" << endl;
        return;
    }
    cout << "\n=== ВСЕ ТРАНЗАКЦИИ ===" << endl;
    for (int i = 0; i < trans_count; i++) {
        cout << trans[i].id << ". " << trans[i].desc;
        cout << " - " << trans[i].amount << " руб. ";
        if (trans[i].type == 1) {
            cout << "(ДОХОД)" << endl;
        }
        else {
            cout << "(РАСХОД)" << endl;
        }
    }
}
void show_balance() {
    double income = 0;
    double expense = 0;
    for (int i = 0; i < trans_count; i++) {
        if (trans[i].type == 1) {
            income += trans[i].amount;
        }
        else {
            expense += trans[i].amount;
        }
    }
    double balance = income - expense;
    cout << "\n=== БАЛАНС ===" << endl;
    cout << "Доходы: " << income << " руб." << endl;
    cout << "Расходы: " << expense << " руб." << endl;
    cout << "Баланс: " << balance << " руб." << endl;
}
void delete_trans() {
    if (trans_count == 0) {
        cout << "Нет транзакций для удаления" << endl;
        return;
    }
    show_all();
    int id;
    cout << "Введите ID для удаления: ";
    cin >> id;
    for (int i = 0; i < trans_count; i++) {
        if (trans[i].id == id) {
            for (int j = i; j < trans_count - 1; j++) {
                trans[j] = trans[j + 1];
            }
            trans_count--;
            cout << "Удалено!" << endl;
            return;
        }
    }

    cout << "Транзакция не найдена!" << endl;
}
void save_data() {
    ofstream file("data.txt");
    if (!file) {
        cout << "Ошибка сохранения!" << endl;
        return;
    }
    file << trans_count << endl;
    for (int i = 0; i < trans_count; i++) {
        file << trans[i].id << endl;
        file << trans[i].desc << endl;
        file << trans[i].amount << endl;
        file << trans[i].type << endl;
    }

    file.close();
    cout << "Данные сохранены!" << endl;
}
void load_data() {
    ifstream file("data.txt");
    if (!file) {
        cout << "Нет сохраненных данных" << endl;
        return;
    }

    file >> trans_count;
    for (int i = 0; i < trans_count; i++) {
        file >> trans[i].id;
        file.ignore();
        file.getline(trans[i].desc, 50);
        file >> trans[i].amount;
        file >> trans[i].type;
    }

    file.close();
    cout << "Данные загружены!" << endl;
}