#include <stdio.h>
#include <stdlib.h>
#include "bank.h"
int counter;

int main()
{
    customer *head='\0';
      int choice;
    printf("please select one of the following options:\n\n\
           1-press 1 to create a new customer\n\
           2-press 2 to edit a customer\n\
           3-press 3 to delete a customer\n\
           4-press 4 to print a customer data\n\
           5-press 5 to transfer cash from customer to another\n\
           6- press 6 to retrun number of customers\n\
           7- press 7 to exit the program\n");
     printf("enter your choice:");
     scanf("%i",&choice);
     int id,id1,id2;
         double cash;
         while(1)
         {
        switch(choice)
         {

         case 1:
                create_customer(head,&head);
                 break;

         case 2:
            printf("please enter your id: ");
            scanf("%i",&id);
            edit_customer(head,id);
         break;
         case 3:
            printf("please enter your id: ");
            scanf("%i",&id);
            delete_customer(&head,head,id);

         break;
          case 4:
            printf("please enter your id: ");
            scanf("%i",&id);
            print_data_customer(head,id);
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
            transfer_cash(head,id1,id2,cash);
         break;
           case 6:
           printf("number of customers is :%i\n",print_num_of_cust());
            break;
          case 7:
              exit(0);
           break;
          default:
            printf("wrong choice");
            break;

         }
                      printf("\n\n\n");
                          printf("please select one of the following options:\n\n\
           1-press 1 to create a new customer\n\
           2-press 2 to edit a customer\n\
           3-press 3 to delete a customer\n\
           4-press 4 to print a customer data\n\
           5-press 5 to transfer cash from customer to another\n\
           6- press 6 to retrun number of customers\n\
           7- press 7 to exit the program\n");


           printf("enter your choice:");
          scanf("%i",&choice);



                         }

    return 0;
}
