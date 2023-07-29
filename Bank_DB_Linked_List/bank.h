#pragma once
typedef struct customers
{
    char name[50];
    double cash;
    char type[7];
    int id;
    struct customers *next;
}customer;
void push_last(customer *head,customer **head_ptr);
void push_head(customer **head_ptr);
void create_customer(customer *head,customer **head_ptr);
void edit_customer(customer *head,int id);
void delete_customer(customer **head_ptr,customer *head,int id);
void transfer_cash(customer *head,int id1,int id2,double cash);
void print_data_customer(customer *head,int id);
int print_num_of_cust(void);
