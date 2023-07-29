#include "bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int counter;

void push_last(customer *head,customer **head_ptr)
{
    customer *valid=head;
        if(*head_ptr=='\0')
    {
        push_head(head_ptr);
    }
    else
    {

        while((head->next) != '\0')
        {
            head=head->next;
        }
        head->next=(customer *)malloc(sizeof(customer));
          printf("please enter the name of customer %i: ",counter+1);
    fflush(stdin);
    gets(head->next->name);
    printf("\n");
    printf("please enter the cash of customer %i: ",counter+1);
    scanf("%lf",&(head->next->cash));
    printf("\n");
    printf("please enter the type of cash of customer %i (debit or credit): ",counter+1);
    fflush(stdin);
    gets(head->next->type);
    printf("\n");
    printf("please enter the id of customer %i: ",counter+1);
     scanf("%i",&(head->next->id));
        head->next->next='\0';
    }
    if(valid!='\0'){
    while(valid->next!='\0')
    {
        if((head->next->id)==valid->id)
        {
            printf("invalid id please enter right one");
            scanf("%i",&(head->next->id));
        }
        else{
            valid=valid->next;
        }
    }
    }
}
void push_head(customer **head_ptr)
{

        customer *temp=*head_ptr;
    *head_ptr=(customer *)malloc(sizeof(customer));
    (*head_ptr)->next=temp;
    printf("please enter the name of customer %i: ",counter+1);
    fflush(stdin);
    gets((*head_ptr)->name);
    printf("\n");
    printf("please enter the cash of customer %i: ",counter+1);
    scanf("%lf",&((*head_ptr)->cash));
    printf("\n");
    printf("please enter the type of cash of customer %i (debit or credit): ",counter+1);
    fflush(stdin);
    gets((*head_ptr)->type);
    printf("\n");
    printf("please enter the id of customer %i: ",counter+1);
     scanf("%i",&((*head_ptr)->id));

}
void create_customer(customer *head,customer **head_ptr)
{
    push_last(head,head_ptr);
    counter++;

}
void edit_customer(customer *head,int id)
{
    int i=1,flag=0;
    while(head!='\0')
    {
        if((head->id)!=id){
        head=head->next;
        i++;
        }
        else{
                   printf("please enter the new name of customer %i: ",i);
               fflush(stdin);
            gets(head->name);
            printf("\n");
            printf("please enter the new cash of customer %i: ",i);
            scanf("%lf",&(head->cash));

            printf("please enter the new type of cash of customer %i (debit or credit): ",i);
            fflush(stdin);

            gets(head->type);
              printf("\n");
            printf("please enter the new id of customer %i: ",i);
            scanf("%i",&(head->id));
            flag=1;
            break;

        }

    }
    if(flag==0)
    {
        printf("invalid id");
    }
}

void delete_customer(customer **head_ptr,customer *head,int id)
{
    customer *temp;
    int flag=0;
    if(head->next=='\0')
    {
         temp=*head_ptr;
        *head_ptr=temp->next;
        free(temp);
        counter--;
        flag=1;
    }
    while((head->next)!='\0')
    {
        if((head->next->id)!=id)
        {
            head=head->next;
        }
        else
        {
            temp=head->next;
            head->next=head->next->next;
            free(temp);
            counter--;
            flag=1;
            break;

        }
    }
    if(flag==0)
    {
        printf("invalid id");
    }

}
void transfer_cash(customer *head,int id1,int id2,double cash)
{
    int im=1,ex=1,flag1=0,flag2=0;
    customer *temp=head;
    while(head!='\0')
    {
        if((head->id)!=id1)
        {
            head=head->next;
            im++;

        }
        else
        {
            flag1=1;
             break;
        }

    }
        while(temp!='\0')
      {
            if((temp->id)!=id2)
        {
            temp=temp->next;
            ex++;

        }
        else
        {
            flag2=1;
            break;
        }
      }
    if(flag1&&flag2){
    if(cash > (head->cash))
    {
         printf("invalid process,the cash you want to transfer from customer %i to customer %i is more than the cash he has\n",im,ex);

    }
    else
{
   (head->cash)-=cash;
    (temp->cash)+=cash;
}

    }
    else
    {
        printf("there's an invalid id please enter the two ids again: ");


    }


}
void print_data_customer(customer *head,int id)
{
    int flag=0;
   while(head!='\0')
   {
       if(head->id!=id)
       {
           head=head->next;
       }
       else
       {
             printf("your name is %s\n",head->name);
            printf("your cash is %0.3f\n",head->cash);
            printf("your type is %s\n",head->type);
            printf("your id is %i\n",head->id);
            flag=1;
            break;
       }

   }
      if(flag==0)
       {
           printf("invalid id,please enter valid one: ");


       }
}
int print_num_of_cust(void)
{
    return counter;
}

