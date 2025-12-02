#pragma once
#ifndef FINANCE_H
#define FINANCE_H

struct Transaction {
    int id;
    char desc[50];
    double amount;
    int type;
};
const int MAX_TRANS = 100;
extern Transaction trans[];
extern int trans_count;
void init();
void add_trans();
void show_all();
void show_balance();
void delete_trans();
void save_data();
void load_data();

#endif