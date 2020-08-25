#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();
void sub_menu(int);
void login_option();
struct date{
    int month,day,year;
    };
struct{

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

//Account Creating Function...

void new_acc()
{
    int choice;
    FILE *ptr;
    ptr=fopen("record.txt","a+");
    account_no:
    system("cls");
    printf("\n\n\t\t\t\xB2\xB2\xB2<<<<CREATE A ACCOUNT>>>>\xB2\xB2\xB2\xB2");
    printf("\n\n\n\tCURRENT DATE(M/D/Y):\t");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\a\n\tACCOUNT NUMBER:\t\t");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("\n\n\nACCOUNT ALREADY USED!");
            fordelay(1000000000);
            goto account_no;
            }
    }
    add.acc_no=check.acc_no;
        printf("\a\n\n\tFULL NAME:\t\t");
    scanf("%s",add.name);
    printf("\a\n\n\tDATE OF BIRTH(M/D/Y):\t");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\a\n\n\tAGE:\t\t\t");
    scanf("%d",&add.age);
    printf("\a\n\n\tADDRESS:\t\t");
    scanf("%s",add.address);
    printf("\a\n\n\tNATIONALITY:\t\t");
    scanf("%s",add.citizenship);
    printf("\a\n\n\tPHONE NUMBER: \t\t");
    scanf("%lf",&add.phone);
    printf("\a\n\n\tAMOUNT to DEPOSIT:TK \t");
    scanf("%f",&add.amt);
    printf("\a\n\tACCOUNT TYPE:\n\n\t#SAVING\n\t#CURRENT\n\n\tENTER YOUR CHOICE:\t\t");
    scanf("%s",add.acc_type);
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    fclose(ptr);
    printf("\a\n\nACCOUNT SECCESSFULLY CREATED!");
    add_invalid:
    printf("\n\n\t\t #0 => TRY AGAIN\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            login_option();
    else
        {
            printf("\nInvalid Input!\a");
            goto add_invalid;
        }
}

//Account checking function...


void view_list()
{
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;
    system("cls");
    printf("\a\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2<<<< ALL RECORD OVERVIEW >>>>\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }
    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\a\a\a\nNO RECORDS!!\n");
        }
    view_list_invalid:
     printf("\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            login_option();
        else
        {
            printf("\nInvalid Input!\a");
            goto view_list_invalid;
        }
}

//Account editing function;

void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("\a\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2<<<< ACCOUNT EDITION >>>>\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\nENTER THE ACCOUNT NUMBER : ");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        system("cls");
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\a\n\n\t\tWHICH INFORMATION YOU WANT TO CHANGE?\n\n\t\t#1 => ADDRESS\n\n\t\t#2 => PHONE\n\n\t\tENTER YOUR CHOICE : ");
            scanf("%d",&choice);
            if(choice==1)
                {printf("\n\n\aENTER A NEW ADDRESS :");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\a\n\n\t\tCHANGES SAVED!!!");
                }
            else if(choice==2)
                {
                    printf("\n\n\aENTER A NEW PHONE NUMBER:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

                printf("\a\n\n\t\tCHANGES SAVED!!!");
                }
        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");
if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\n\n\t\t #0 => TRY AGAIN\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    login_option();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid Input!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            login_option();
        }
}

//money Transacting function...

void transact(int account_no ,int acc_type)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    system("cls");
    printf("\a\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2<<<< ACCOUNT TRANSACTION >>>>\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==account_no)
            {   test=1;
                printf("\a\n\nDO YOU WANT TO:\n\n\n\t\t#1 => DEPOSIT\n\n\n\t\t#2 => WITHDROW\n\n\nENTER YOUR CHOICE : ");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("\a\n\nENTER THE AMOUNT YOU WANT TO DEPOSIT: ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\a\n\nDEPOSITED SUCCESSFULLY!!!!");
                }
                else
                {
                    printf("\a\n\nENTER THE AMOUNT YOU WANT TO WITHDROW : ");
                    scanf("%f",&transaction.amt);
                    if(transaction.amt<=add.amt){
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\a\n\nWITHWROEN SUCCESSFULLY!!!!");}
                    else
                        system("color 4");
                        printf("YOUR ACCOUNT IS NOT SUFFICIENT");
                }
            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test!=1)
   {
       printf("\a\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\t\t #0 => TRY AGAIN\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact(account_no,acc_type);
    else if (main_exit==1)
        sub_menu(account_no);
    else if (main_exit==2)
        login_option();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }
   }
   else
   {
       printf("\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1){if(acc_type==1)sub_menu(account_no);else menu();}
        else
            login_option();
   }

}


//Account Deleting function..


void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("\a\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2<<<< REVOME A ACCOUNT >>>>\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\tENTER A ACCOUNT NUMBER :");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\a\n\n\t\tRECORD DELETED SUCCESSFULLY!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\n\n\t\t #0 => TRY AGAIN\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    login_option();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid Input!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            login_option();
        }
}

//Account details displaying function...

void see(int account_no,int acc_type)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.txt","r");
    printf("\a\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2<<<< DETAILS OF THE ACCOUNT >>>>\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==account_no)
            {   system("cls");
                test=1;

                printf("\a\n\n\t\tACCOUNT NO.:\t\t%d\n\n\t\tNAME:\t\t\t%s \n\n\t\tDOB:\t\t\t%d/%d/%d \n\n\t\tAGE:\t\t\t%d \n\n\t\tADDRESS:\t\t%s \n\n\t\tNATIONALITY:\t\t%s \n\n\t\tPHONE NUMBER:\t\t%.0lf \n\n\t\tACCOUNT TYPE:\t%s \n\n\t\tAMOUNT DEPOSITED:\t%.2f tk\n\n\t\tDEPOSIT DATE:\t%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

            }
        }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\n\n\t\t #0 => TRY AGAIN\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t"); scanf("%d",&main_exit);system("cls");
                 if (main_exit==1)
                    sub_menu(account_no);
                else if (main_exit==2)
                    login_option();
                else if(main_exit==0)
                   { see(account_no,acc_type);}
                else
                    {
                        system("cls"); printf("\nInvalid Input!\a"); goto see_invalid;}
                    }
    else
        {printf("\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        { if(acc_type==1) sub_menu(account_no); else menu();}
        else
           {system("cls");login_option();}
}

//Balance transfer function...


void bal_transfer(int account_no, int i)
{   int choice,test=0,dist_acc;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    system("cls");
    printf("\a\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BALANCE TRANSFORMATION \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t#1 => BRACK BANK BANGLADESH (BCASH).\n\n\t\t#2 => DUTCH BANGLA BANK.\n\n\t\t#3 => ISLAMIC BANK BANGLADESH.\n\n\t\t#4 => AB BANK BANGLADESH.\n\n\t\t#5 => CITY BANK BANGLADESH.\n\n\t\t#6 => MAIN MENU.");
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {


            if(add.acc_no==account_no)
            {   test=1;
                printf("\a\n\n");printf("\n\n\n\tCHOOSE YOUR TRANSFORMATION METHOD: ");
                scanf("%d",&choice);system("cls");printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BALANCE TRANSFORMATION \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\n\n\t\tENTER YOUR ");
                if(choice==1)printf("BCASH ACCOUNT NO : ");else if(choice==2)printf("DBBL ACCOUNT NO : ");else if(choice==3)printf("IBBL ACCOUNT NO : ");else if(choice==4)printf("ABBL ACCOUNT NO : ");else if(choice==5)printf("CBBL ACCOUNT NO : ");
                scanf("%d",&dist_acc);

                printf("\n\n\a\t\tENTER THE AMMOUNT : ");
                scanf("%f",&transaction.amt);
                add.amt-=transaction.amt;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\a\n\n\tACCOUNT TRANSFERED SUCCESSFULLY TO YOUR ");
                if(choice==1)printf("=>BCASH %d",dist_acc);else if(choice==2)printf("=>DBBL %d",dist_acc);else if(choice==3)printf("=>IBBL %d",dist_acc);else if(choice==4)printf("=>ABBL %d",dist_acc);else if(choice==5)printf("=>CBBL %d",dist_acc);
                printf("\n\n\t<<<<< THANKS FOR STAYING WITH US >>>>>>");
            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test!=1)
   {
       printf("\a\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\t\t #0 => TRY AGAIN\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        bal_transfer(account_no,1);
    else if (main_exit==1)
        sub_menu(account_no);
    else if (main_exit==2)
        login_option();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }
   }
   else
   {
       printf("\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)sub_menu(account_no);
        else
            login_option();
   }

}
//About us Function...

void aboutus(int acc_type, int account_no)
{
    printf("\a\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 <<<<ABOUT DEVELOPER>>>> \xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t| HELLO EVERYBODY!! WE ARE A GROUP of PROJECT DEVELOPMENT of |\n\t| 'SOFTWARE DEVELOPMENT' COURSE. WE HAD DECIDED  TO BUILD A  |\n\t| BANK MANEGEMENT SOFTWARE AND FINALLY WE HAVE BUILT THAT. WE|\n\t| HAVE INCLUDED SOME EXTRA FEATURE AS WELL AS POSSIBLE.      |");

    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\tName of Developer's : \n\n\t\t#1 =>> MD.YASIR ARAFAT \t\tID: 100;\n\n\t\t#2 =>> MD.FAISAL AHMED \t\tID: 111;\n\n\t\t#3 =>> MD.MANIK SARKAR \t\tID: 125;\n\n\t\t#2 =>> MD.MONZUR HASAN \t\tID: 129;\n\n\t\t#2 =>> MD.REJAUL KARIM \t\tID: 106;");
    printf("\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
   // printf("\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT");
    scanf("%d",&main_exit);
    if (main_exit==1)
    { system("cls");if(acc_type==0&&account_no==0) menu(); else sub_menu(account_no); }
    else
    {system("cls");login_option();}

}

//Balance Checking function...

void check_balance(int account_no, int acc_type)
{
    FILE *ptr;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.txt","r");
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==account_no)
            {
                printf("\a\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BALANCE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\a\a \n\n\n\n\tYOUR ACCOUNT BALANCE IS: %.2f (taka only).",add.amt);
            }
        }
    printf("\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");
    scanf("%d",&main_exit);
    if (main_exit==1)
    { system("cls");if(acc_type==1) sub_menu(account_no); else menu(); }
    else
    {system("cls");login_option();}


}

//ADMIN MENU Functioin....


void menu(void)
{   int choice,account_no;system("cls"); system("color 6");
    printf("\a\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t#1 => CREATE NEW ACCOUNT\n\n\t\t#2 => UPDATE INFORMATION\n\n\t\t#3 => TRANSACTION\n\n\t\t#4 => CHECK A ACCOUNT DETAILS\n\n\t\t#5 =>  DELETE A ACCOUNT\n\n\t\t#6 => ALL ACCOUNT OVERVIEW\n\n\t\t#7 => ABOUT DEVELOPER'S\n\n\t\t#8 => LOGOUT\n\n\n\t\tENTER YOUR CHOICE:");
    scanf("%d",&choice);system("cls");
    switch(choice)
    {
        case 1:
        printf("\a");
            new_acc();
        break;
        case 2:printf("\a");edit();
        break;
        case 3:printf("\a");
            printf("ENTER A ACCOUNT NUMBER: ");
            scanf("%d",&account_no);
            transact(account_no,0);
        break;
        case 4:printf("\a");
            printf("ENTER A ACCOUNT NUMBER: ");
            scanf("%d",&account_no);
            see(account_no,0);
        break;
        case 5:printf("\a");erase();
        break;
        case 6:printf("\a");view_list();
        break;
        case 7:printf("\a");aboutus(0,0);
        break;
        case 8:login_option();
        break;
    }
}

//Subscriber account menu function..

void sub_menu(int account_no)
{   int choice;system("cls"); system("color 6");
    printf("\a\n\t\t\_____________________________________________________");
    printf("\a\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2<<<<SUBSCRIBER MOBILE BANKING PANEL>>>> \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\a\n\t\t\_____________________________________________________");
    //printf("\a\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  <<<< Logged in as '%d' >>>> \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2",account_no);
    printf("\n\n\t\t#1.BALANCE\n\n\t\t#2.TRANSACTION\n\n\t\t#3.TRANSFER\n\n\t\t#4.ACCOUNT DETAILS\n\n\t\t#5.CONTACT US\n\n\t\t#6.LOGOUT\n\n\n\t\t ENTER YOUR CHOICE:");

    scanf("%d",&choice);system("cls");
    switch(choice)
    {
        case 1: printf("\a");check_balance(account_no ,1);
        break;
        case 2:printf("\a");transact(account_no,1);
        break;
        case 3:printf("\a");bal_transfer(account_no,1);
        break;
        case 4:printf("\a");see(account_no,1);
        break;
        case 5:printf("\a");aboutus(1,account_no);
        case 6:login_option();
        break;
    }
}

//Login option function..

void login_option()
{
    int a,choice,carry=0,account_no;
    FILE *ptr;
    //float time;
    //float intrst;
    char pass[10],admin_password[10]="bubt",sub_password[10];
    printf("\a\a\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ENTER YOUR CHOICE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\t\t\t#1 => Login as ADMINISTRATOR\n\n\t\t\t#2 => Login as SUBSCRIBER\n\n\n\n\t\t\tENTER YOUR CHOICE: ");
    scanf("%d\a",&choice);

    //choice..1
    if(choice==1)
    {
        system("cls");
        printf("\a\n\n\n\n\n\n\n\t\tENTER YOUR PASSWORD:");scanf("%s",pass);
        if (strcmp(pass,admin_password)==0)
            {   system("color 2");
                printf("\a\a\n\nPASSWORD MATCHED!\nLOADING");
                for(i=0;i<=60;i++) {fordelay(10000000); printf("."); } system("cls");menu();
            }
        else
            {   system("color 4");
                printf("\n\nWrong password!!\a\a\a");login_try:
                printf("\n\n\t\t#1 => TRY AGAIN\n\n\t\t#0 => LOGOUT\n\t\t"); scanf("%d",&main_exit);
                if (main_exit==1){ system("cls"); main(); }
                else if (main_exit==0){ system("cls"); login_option();}
                else {printf("\nInvalid!"); fordelay(1000000000); system("cls"); goto login_try;}
            }
    }

    //choice..2
    else if(choice==2)
    {
        system("cls");
        ptr=fopen("record.txt","r");
        printf("\a\a\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ENTER YOUR ACCOUNT \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\a\n\n\n\t\t\tENTER A ACCOUNT NUMBER:");scanf("%d",&account_no);
        printf("\a\n\n\n\t\t\tENTER YOUR PASSWORD:");scanf("%s",&sub_password);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {

            if((add.acc_no==check.acc_no)&&strcmp(sub_password,"1234")==0)
            {carry=1; system("color 2");system("cls");fclose(ptr);sub_menu(account_no);}
        }
        if(carry==0)
        {  system("color 4");
            printf("\n\nWrong password!!\a\a\a");
            printf("\n\n\t\t#1 => MAIN MENU\n\n\t\t#2 => LOGOUT\n\t\t");scanf("%d",&main_exit);
            if (main_exit==1){ system("cls"); main(); }
            else if (main_exit==0){ system("cls"); login_option();}
            else {printf("\nInvalid!"); fordelay(1000000000); system("cls"); goto login_try;}
        }
    }
}

///Main function............................................................................

int main()
{
    char pass[10];//,password[10]="1";
    //int i=0;
    system("color 17");
    login_option();
        return 0;
}
