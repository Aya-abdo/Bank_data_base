#include "bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
extern customer arr[SIZE];
extern int counter;
void create_customer(void)
{
    int i;
    printf("please enter the name of customer %i: ",counter+1);
    fflush(stdin);
    gets(arr[counter].name);
    printf("\n");
    printf("please enter the cash of customer %i: ",counter+1);
    scanf("%lf",&arr[counter].cash);
    printf("\n");
    printf("please enter the type of cash of customer %i (debit or credit): ",counter+1);
    fflush(stdin);
    gets(arr[counter].type);
    printf("\n");
    printf("please enter the id of customer %i: ",counter+1);
     scanf("%i",&arr[counter].id);
     for(i=0;i<=counter;i++)
     {
         if(i==counter)
         {
             continue;
         }
         else{
            while(arr[counter].id==arr[i].id)
            {
                printf("wrong id please enter valid id: ");
                scanf("%i",&arr[counter].id);

            }
         }
     }

    counter++;

}
void edit_customer(int id)
{
    int i;
    for(i=0;i<=counter;i++)
    {
        if(arr[i].id==id)
        {
             printf("please enter the new name of customer %i: ",i+1);
               fflush(stdin);
            gets(arr[i].name);
            printf("\n");
            printf("please enter the new cash of customer %i: ",i+1);
            scanf("%lf",&arr[i].cash);

            printf("please enter the new type of cash of customer %i (debit or credit): ",i+1);
            fflush(stdin);

            gets(arr[i].type);
              printf("\n");
            printf("please enter the new id of customer %i: ",i+1);
            scanf("%i",&arr[i].id);
            break;
        }



    }
        if(i>counter){
            printf("invalid id\n");
        }
}
void delete_customer(int id)
{

    int i,j;
    for(i=0;i<=counter;i++){
        if(arr[i].id==id)
        {

            for(j=i;j<counter;j++)
            {
                arr[j]=arr[j+1];
            }
            counter--;
            break;
        }

    }

     if(i>counter){
            printf("invalid id\n");
        }


}
void print_data_customer(int id)
{
     int i;
    for(i=0;i<=counter;i++)
    {
        if(arr[i].id==id)
        {
            printf("your name is %s\n",arr[i].name);
            printf("your cash is %0.3f\n",arr[i].cash);
            printf("your type is %s\n",arr[i].type);
            printf("your id is %i\n",arr[i].id);
            break;

        }
    }
      if(i>counter){
            printf("invalid id\n");
        }
}
transfer_cash(int id1,int id2,double cash)
{
    int i,im,ex;
    for(i=0;i<=counter;i++)
    {
        if(arr[i].id==id1){
          im=i;
        }
        if(arr[i].id==id2)
        {
            ex=i;
        }

    }
    if(cash<=(arr[im].cash))
    {
           arr[im].cash-=cash;
           arr[ex].cash+=cash;
    }else
    {
        printf("invalid process,the cash you want to transfer from customer %i to customer %i is more than the cash he has\n",im+1,ex+1);
    }


}
