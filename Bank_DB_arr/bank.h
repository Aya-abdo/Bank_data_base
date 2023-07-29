#pragma once
typedef struct customers
{
    char name[50];
    double cash;
    char type[7];
    int id;
}customer;
void create_customer(void);
void edit_customer(int id);
void delete_customer(int id);
void transfer_cash(int id1,int id2,double cash);
void print_data_customer(int id);
