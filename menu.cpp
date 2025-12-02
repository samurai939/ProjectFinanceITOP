#include "finance.h"
#include <iostream>
using namespace std;
void show_menu() {
    cout << "\n=== УПРАВЛЕНИЕ ФИНАНСАМИ ===" << endl;
    cout << "1. Добавить транзакцию" << endl;
    cout << "2. Показать все" << endl;
    cout << "3. Показать баланс" << endl;
    cout << "4. Удалить транзакцию" << endl;
    cout << "5. Сохранить" << endl;
    cout << "6. Загрузить" << endl;
    cout << "7. Выход" << endl;
    cout << "Выберите: ";
}
void handle_choice(int choice) {
    switch (choice) {
    case 1:
        add_trans();
        break;
    case 2:
        show_all();
        break;
    case 3:
        show_balance();
        break;
    case 4:
        delete_trans();
        break;
    case 5:
        save_data();
        break;
    case 6:
        load_data();
        break;
    case 7:
        cout << "До свидания!" << endl;
        break;
    default:
        cout << "Неверный выбор!" << endl;
    }
}