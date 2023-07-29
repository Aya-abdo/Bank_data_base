#include <stdio.h>
#include <stdlib.h>
#include "bank.h"
#define SIZE 100

customer arr[SIZE];
int counter=0;
int main()
{
    int choice;
    printf("please select one of the following options:\n\n\
           1-press 1 to create a new customer\n\
           2-press 2 to edit a customer\n\
           3-press 3 to delete a customer\n\
           4-press 4 to print a customer data\n\
           5-press 5 to transfer cash from customer to another\n\
           6- press 6 to exit\n");
     printf("enter your choice:");
     scanf("%i",&choice);
     int flag=1;
     while(1)
     {
         int id,id1,id2;
         double cash;

         switch(choice)
         {
         case 1:
            if (counter>SIZE-1)
                printf("the maximum number of clients is %i you can't add more\n",SIZE);
            else{
                create_customer();

            }
         break;
         case 2:
            printf("please enter your id: ");
            scanf("%i",&id);
            edit_customer(id);
         break;
         case 3:
            printf("please enter your id: ");
            scanf("%i",&id);
            delete_customer(id);

         break;
          case 4:
            printf("please enter your id: ");
            scanf("%i",&id);
            print_data_customer(id);
         break;
           case 5:
            printf("please enter the id you want to make the transfer from: ");
            scanf("%i",&id1);
            printf("\n");
            printf("please enter the id you want to make the transfer to: ");
            scanf("%i",&id2);
            printf("\n");
            printf("please enter the cash you want to  transfer to customer: ");
            scanf("%lf",&cash);
            printf("\n");
            transfer_cash(id1,id2,cash);
         break;
          case 6:
              flag=0;

         break;



         }
         if(flag==0)
            break;
         else
         {
             printf("\n\n\n");

          printf("please select one of the following options:\n\n\
           1-press 1 to create a new customer\n\
           2-press 2 to edit a customer\n\
           3-press 3 to delete a customer\n\
           4-press 4 to print a customer data\n\
           5-press 5 to transfer cash from customer to another\n\
           6- press 6 to exit\n");
           printf("enter your choice:");
          scanf("%i",&choice);
         }
     }
    return 0;
}
