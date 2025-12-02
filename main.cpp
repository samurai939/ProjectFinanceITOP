#include "finance.h"
#include <iostream>
using namespace std;
void show_menu();
void handle_choice(int choice);

int main() {
    setlocale(0, "");
    init();
    load_data();
    int choice;
    do {
        show_menu();
        cin >> choice;
        handle_choice(choice);

    } while (choice != 7);
    return 0;
}