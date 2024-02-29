#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n = 5, n2 = 0;
int src = 0, p = 0;
int dist[10], path[10], visited[10], min_num = 999, min;

void menu(void);
void close1();
void dijkstra();
void dijkstra1();
void dijkstra2();
void dijkstra3();
void heapify();

int i, j;
int main_exit;

struct date
{
    int month, day, year;
};

struct
{

    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

} add, upd, check, rem, transaction;

float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.0;
    return (SI);
}

void fordelay(int j)
{
    int i, k;

    for (i = 0; i < j; i++)
        k = i;
}

void new_acc()

{
    int choice;
    FILE *ptr;

    ptr = fopen("record.txt", "a+");
account_no:
    system("cls");
    printf("\t\t\t ADD RECORD ");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d", &check.acc_no);

    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {

        if (check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;
        }
    }

    add.acc_no = check.acc_no;
    printf("\nEnter the name:");
    scanf("%s", add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter the age:");
    scanf("%d", &add.age);
    printf("\nEnter the address:");
    scanf("%s", add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s", add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf", &add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f", &add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s", add.acc_type);

    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

    fclose(ptr);
    printf("\nAccount created successfully!");
add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close1();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

void view_list()
{
    FILE *view;
    view = fopen("record.txt", "r");
    int test = 0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }

    fclose(view);
    if (test == 0)
    {
        system("cls");
        printf("\nNO RECORDS!!\n");
    }

view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close1();
    else
    {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
}

void edit(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d", &upd.acc_no);

    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {

        if (add.acc_no == upd.acc_no)
        {

            test = 1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d", &choice);
            system("cls");

            if (choice == 1)
            {
                printf("Enter the new address:");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
            else if (choice == 2)
            {

                printf("Enter the new phone number:");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
        }
        else
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)

            menu();
        else if (main_exit == 2)
            close1();
        else if (main_exit == 0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close1();
    }
}

void transact(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("Enter the account no. of the customer:");
    scanf("%d", &transaction.acc_no);

    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {

        if (add.acc_no == transaction.acc_no)
        {
            test = 1;

            if (strcmpi(add.acc_type, "fixed1") == 0 || strcmpi(add.acc_type, "fixed2") == 0 || strcmpi(add.acc_type, "fixed3") == 0)
            {

                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu();
            }

            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d", &choice);
            if (choice == 1)
            {

                printf("Enter the amount you want to deposit:$ ");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nDeposited successfully!");
            }
            else
            {

                printf("Enter the amount you want to withdraw:$ ");
                scanf("%f", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nWithdrawn successfully!");
            }
        }
        else
        {

            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1)
    {

        printf("\n\nRecord not found!!");
    transact_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");

        if (main_exit == 0)
            transact();
        else if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close1();
        else
        {

            printf("\nInvalid!");
            goto transact_invalid;
        }
    }
    else
    {

        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close1();
    }
}
void erase(void)
{
    FILE *old, *newrec;
    int test = 0;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d", &rem.acc_no);

    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {

        if (add.acc_no != rem.acc_no)
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

        else
        {

            test++;
            printf("\nRecord deleted successfully!\n");
        }
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test == 0)
    {

        printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);

        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close1();
        else if (main_exit == 0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {

        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close1();
    }
}

void see(void)
{

    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;
    ptr = fopen("record.TXT", "r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter the account number:");
        scanf("%d", &check.acc_no);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {

            if (add.acc_no == check.acc_no)
            {
                system("cls");
                test = 1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                       add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmpi(add.acc_type, "fixed1") == 0)
                {

                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmpi(add.acc_type, "fixed2") == 0)
                {

                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmpi(add.acc_type, "fixed3") == 0)
                {

                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmpi(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmpi(add.acc_type, "current") == 0)
                {

                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }

    else if (choice == 2)
    {
        printf("Enter the name:");
        scanf("%s", &check.name);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {

            if (strcmpi(add.name, check.name) == 0)
            {

                system("cls");
                test = 1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                       add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmpi(add.acc_type, "fixed1") == 0)
                {

                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmpi(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmpi(add.acc_type, "fixed3") == 0)
                {

                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmpi(add.acc_type, "saving") == 0)
                {

                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get Rs.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmpi(add.acc_type, "current") == 0)
                {

                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }

    fclose(ptr);

    if (test != 1)
    {

        system("cls");
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close1();
        else if (main_exit == 0)
            see();
        else
        {

            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {

        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
    }
    if (main_exit == 1)
    {

        system("cls");
        menu();
    }

    else
    {

        system("cls");
        close1();
    }
}

void close1()
{
    printf("\n\n\n\nThankyou for using our banking service!!!");
}

void menu(void)
{

    int choice;
    system("cls");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");

    printf("\n\n\n\t\t\t WELCOME TO THE MAIN MENU ");

    printf("\n\n\t\t1.Create new account\n\t");

    printf("\t2.Update information of existing account\n\t");

    printf("\t3.For transactions\n\t");

    printf("\t4.Check the details of existing account\n\t");

    printf("\t5.Removing existing account\n\t\t");

    printf("6.View customer's list\n\t\t");

    printf("7.Exit\n\n\n\n\n\t\t");

    printf("Enter your choice:");

    scanf("%d", &choice);

    system("cls");

    switch (choice)
    {

    case 1:
        new_acc();
        break;

    case 2:
        edit();
        break;

    case 3:
        transact();
        break;

    case 4:
        see();
        break;

    case 5:
        erase();
        break;

    case 6:
        view_list();
        break;

    case 7:
        close1();
        break;

    default:
        printf("\n\t\tYou Pressed wrong key");
        break;
    }
}

struct cit
{

    int id;
    char name[100];
    float income;
    char gender[10];
    char addr[100];
    char phone[15];
};

struct population
{

    char name[30];
    int pop;
};

typedef struct population P;

P ar[90];

typedef struct cit CITIZEN;

struct node
{

    int u, v, w;
};

void insertionsort(struct node a[36], int n1)
{
    int j, i, k;
    struct node m;

    for (j = 1; j < n1; j++)
    {
        i = 0;

        while (a[j].w > a[i].w)
        {

            i += 1;
        }

        m = a[j];

        for (k = 0; k < j - i; k++)
        {

            a[j - k] = a[j - k - 1];
        }

        a[i] = m;
    }
}

void union1(int arr[], int n1, int u, int v)
{

    for (int i = 0; i < n1; i++)
    {

        if (arr[i] == arr[u])
            arr[i] = arr[v];
    }
}

int find(int arr[9], int n1, int u, int v)
{

    if (arr[u] == arr[v])
        return 1;
    return 0;
}

void kruskals(struct node a[36], int n1, int arr[9])
{

    FILE *fp;
    int d;
    char s[100];
    int k = 0;
    int cost = 0, count = 0;

    for (k = 0; k < 36; k++)
    {

        if (find(arr, n1, a[k].u, a[k].v) == 0)
        {

            fp = fopen("city.txt", "r");

            for (int i = 0; i < 9; i++)
            {

                fscanf(fp, "%s %d", s, &d);
                if (d == a[k].u || d == a[k].u)
                {
                    printf("\t\t%s -->\t", s);
                }
                else if (d == a[k].v || d == a[k].v)
                {
                    printf("%s\n", s);
                }
            }
            fclose(fp);
            cost += a[k].w;
            count++;
            union1(arr, n1, arr[a[k].u], arr[a[k].v]);
            if (count == n1 - 1)
                break;
        }
    }

    printf("%d is the minimum length(in km) to install the wires for street lights across the city\n", cost);
}

struct node a1[36] = {{0, 1, 15},
                      {0, 2, 16},
                      {0, 3, 37},
                      {0, 4, 18},
                      {0, 5, 10},
                      {0, 6, 41},
                      {0, 7, 29},
                      {0, 8, 30},
                      {1, 2, 13},
                      {1, 3, 26},
                      {1, 4, 37},
                      {1, 5, 25},
                      {1, 6, 24},
                      {1, 7, 28},
                      {1, 8, 18},
                      {2, 3, 20},
                      {2, 4, 34},
                      {2, 5, 29},
                      {2, 6, 45},
                      {2, 7, 21},
                      {2, 8, 30},
                      {3, 4, 25},
                      {3, 5, 30},
                      {3, 6, 35},
                      {3, 7, 29},
                      {3, 8, 40},
                      {4, 5, 45},
                      {4, 6, 36},
                      {4, 7, 27},
                      {4, 8, 29},
                      {5, 6, 28},
                      {5, 7, 38},
                      {5, 8, 40},
                      {6, 7, 18},
                      {6, 8, 15},
                      {7, 8, 16}};

int arr[36], n1 = 9;

void union2(int arr[], int n1, int u, int v)
{

    for (int i = 0; i < n1; i++)
    {

        if (arr[i] == arr[u])
            arr[i] = arr[v];
    }
}

int find1(int arr[9], int n1, int u, int v)
{

    if (arr[u] == arr[v])
        return 1;
    return 0;
}

void kruskals2(struct node a[36], int n1, int arr[9])
{

    FILE *fp;
    int d;
    char s[100];
    int k = 0;
    int cost = 0, count = 0;

    for (k = 0; k < 36; k++)
    {

        if (find1(arr, n1, a[k].u, a[k].v) == 0)
        {

            fp = fopen("city.txt", "r");

            for (int i = 0; i < 9; i++)
            {

                fscanf(fp, "%s %d", s, &d);
                if (d == a[k].u || d == a[k].u)
                {

                    printf("\t\t%s -->\t", s);
                }
                else if (d == a[k].v || d == a[k].v)
                {

                    printf("%s\n", s);
                }
            }

            fclose(fp);
            cost += a[k].w;
            count++;
            union2(arr, n1, arr[a[k].u], arr[a[k].v]);
            if (count == n1 - 1)
                break;
        }
    }
    printf("%d is the minimum length(in km) to install the wires for television across the city\n", cost);
}

void union3(int arr[], int n1, int u, int v)
{

    for (int i = 0; i < n1; i++)
    {

        if (arr[i] == arr[u])
            arr[i] = arr[v];
    }
}

int find2(int arr[9], int n1, int u, int v)
{

    if (arr[u] == arr[v])
        return 1;
    return 0;
}

void kruskals3(struct node a[36], int n1, int arr[9])
{

    FILE *fp;
    int d;
    char s[100];
    int k = 0;
    int cost = 0, count = 0;

    for (k = 0; k < 36; k++)
    {

        if (find2(arr, n1, a[k].u, a[k].v) == 0)
        {

            fp = fopen("city.txt", "r");

            for (int i = 0; i < 9; i++)
            {

                fscanf(fp, "%s %d", s, &d);
                if (d == a[k].u || d == a[k].u)
                {

                    printf("\t\t%s -->\t", s);
                }
                else if (d == a[k].v || d == a[k].v)
                {

                    printf("%s\n", s);
                }
            }

            fclose(fp);
            cost += a[k].w;
            count++;
            union3(arr, n1, arr[a[k].u], arr[a[k].v]);
            if (count == n1 - 1)
                break;
        }
    }

    printf("%d is the minimum length(in km) to install the wires for installing mobile towers across the city\n", cost);
}

void printChar(char ch, int n)
{

    while (n--)
    {
        putchar(ch);
    }
}

void printHead()
{

    system("cls");
    printf("\t");
    printChar('=', 65);
    printf("\n\t");
    printChar('=', 16);
    printf("[CITY] [MANAGEMENT] [SYSTEM]");
    printChar('=', 16);
    printf("\n\t");
    printChar('=', 65);
}

FILE *del(FILE *fp)
{

    printf("\n\t\t\t\tRemove citizen");
    CITIZEN e;
    int flag = 0, tempid, siz = sizeof(e);
    FILE *ft;

    if ((ft = fopen("temp.txt", "w+")) == NULL)
    {

        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEnter ID number of citizen to Delete the Record");
    printf("\n\n\t\t\tID No. : ");
    scanf("%d", &tempid);

    for (int i = 0; i < n; i++)
    {

        fscanf(fp, "%d %s %f %s %s %s", &e.id, e.name, &e.income, e.gender, e.addr, e.phone);
        if (e.id == tempid)
        {

            flag = 1;
            printf("\n\tRecord Deleted for");

            printf("\n\n\t\tID : %d", e.id);

            printf("\n\n\t\tNAME : %s", e.name);

            printf("\n\n\t\tINCOME : %.2f", e.income);

            printf("\n\n\t\tGENDER : %s", e.gender);

            printf("\n\n\t\tADDRESS : %s", e.addr);

            printf("\n\n\t\tPHONE : %s", e.phone);

            continue;
        }
        fprintf(ft, "%d %s %f %s %s %s\n", e.id, e.name, e.income, e.gender, e.addr, e.phone);
    }

    fclose(fp);
    fclose(ft);

    remove("text.txt");

    rename("temp.txt", "text.txt");

    if ((fp = fopen("text.txt", "r+")) == NULL)
    {

        printf("ERROR");
        return NULL;
    }

    if (flag == 0)
        printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");
    printf("\n");
    printChar('-', 65);
    printf("\n\t");
    system("pause");
    return fp;
}

void add1(FILE *fp)
{

    printf("\n\t\t\tAdd citizen");
    char another = 'y';
    CITIZEN e;
    int d = 0, k;

    fseek(fp, 0, SEEK_END);

    while (another == 'y' || another == 'Y')
    {

        printf("\n\n\t\tEnter ID number: ");
        scanf("%d", &e.id);
        printf("\n\n\t\tEnter Full Name of Citizen: ");
        fflush(stdin);
        fgets(e.name, 100, stdin);
        e.name[strlen(e.name) - 1] = '\0';

        printf("\n\n\t\tEnter the income: ");
        scanf("%f", &e.income);

        printf("\n\n\t\tEnter Gender: ");
        fflush(stdin);
        fgets(e.gender, 10, stdin);
        e.gender[strlen(e.gender) - 1] = '\0';

        printf("\n\n\t\tEnter Present Address: ");
        fflush(stdin);
        fgets(e.addr, 200, stdin);
        e.addr[strlen(e.addr) - 1] = '\0';

        printf("\n\n\t\tEnter Phone: ");
        fflush(stdin);
        fgets(e.phone, 50, stdin);
        e.phone[strlen(e.phone) - 1] = '\0';

        fprintf(fp, "\n%d %s %f %s %s %s\n", e.id, e.name, e.income, e.gender, e.addr, e.phone);
        d++;

        printf("\n\n\t\tDo you want to enter another citizen info (Y/N)\t");
        fflush(stdin);
        another = getchar();
    }

    fclose(fp);
    fp = fopen("popln.txt", "r");
    fscanf(fp, "%d", &k);
    fclose(fp);
    fp = fopen("popln.txt", "w");
    fprintf(fp, "%d", k + d);
    fclose(fp);
}

void searchRecord(FILE *fp)
{

    printf("\n\t\t\t Search citizen");
    int tempid, flag, siz, i;
    CITIZEN e;
    char another = 'y';

    siz = sizeof(e);

    while (another == 'y' || another == 'Y')
    {

        printf("\n\n\tEnter ID Number of citizen to search the record : ");
        scanf("%d", &tempid);

        rewind(fp);

        for (int i = 0; i < n; i++)
        {

            fscanf(fp, "%d %s %f %s %s %s", &e.id, e.name, &e.income, e.gender, e.addr, e.phone);
            if (e.id == tempid)
            {

                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {

            printf("\n\n\t\tID : %d", e.id);

            printf("\n\n\t\tNAME : %s", e.name);

            printf("\n\n\t\tINCOME : %.2f", e.income);

            printf("\n\n\t\tGENDER : %s", e.gender);

            printf("\n\n\t\tADDRESS : %s", e.addr);

            printf("\n\n\t\tPHONE : %s", e.phone);

            printf("\n\n");

            printChar('=', 65);
        }
        else
            printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");

        printf("\n\n\t\tWant to enter another search (Y/N)");
        fflush(stdin);
        another = getchar();
    }
}

void displayList(FILE *fp)
{

    int i;
    printf("\n\t\tList  of citizens");
    CITIZEN e;

    for (i = 0; i < n; i++)
    {

        fscanf(fp, "%d %s %f %s %s %s", &e.id, e.name, &e.income, e.gender, e.addr, e.phone);

        printf("\n\n\t\tID : %d", e.id);

        printf("\n\n\t\tNAME : %s", e.name);

        printf("\n\n\t\tINCOME : %.2f", e.income);

        printf("\n\n\t\tGENDER : %s", e.gender);

        printf("\n\n\t\tADDRESS : %s", e.addr);

        printf("\n\n\t\tPHONE : %s", e.phone);

        printf("\n\n");
    }

    printf("\n\n\n\t");

    printf("\n\n\t");
    system("pause");
    fclose(fp);
}

void popl(FILE *fp)
{

    int d;
    fscanf(fp, "%d", &d);
    printf("\n\n\t\tTOTAL POPULATION : %d\n", d);
    fclose(fp);
}

void maps()
{

    char curr[30], dest[30], a[30];
    int i, j, d, flag = 0;
    FILE *fp;
    printf("\n\t\tENTER CURRENT AREA AND DESTINATION AREA\n");
    fflush(stdin);
    scanf("%s", curr);
    fflush(stdin);
    scanf("%s", dest);
    fp = fopen("city.txt", "r");

    for (i = 0; i < 9; i++)
    {

        fscanf(fp, "%s %d", a, &d);
        if (strcmp(a, curr) == 0)
        {

            src = d;
            flag = 1;
        }
        if (strcmp(a, dest) == 0)
        {

            p = d;
            flag = 2;
        }
    }

    fclose(fp);
    if (flag == 0)
    {

        printf("INVALID AREA LOCATONS\n");
        return;
    }
    dijkstra();
}

void dijkstra()
{

    FILE *fp;
    char s[30];
    int d;

    int i, j, a[9][9] = {{0, 15, 16, 37, 18, 10, 41, 29, 30}, {15, 0, 13, 26, 37, 25, 24, 28, 18}, {16, 13, 0, 20, 34, 29, 45, 21, 30}, {37, 26, 20, 0, 25, 30, 35, 29, 40}, {18, 37, 34, 25, 0, 45, 36, 27, 29}, {10, 25, 29, 30, 45, 0, 28, 38, 40}, {41, 24, 29, 35, 36, 28, 0, 18, 15}, {29, 28, 21, 29, 27, 38, 18, 0, 12}, {30, 18, 30, 40, 29, 40, 15, 16, 0}};

    for (i = 0; i < 9; i++)
    {

        dist[i] = a[src][i];
        path[i] = src;
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (visited[j] == 0)
            {
                if (dist[j] < min_num)
                {
                    min_num = dist[j];
                    min = j;
                }
            }
        }

        for (j = 0; j < 9; j++)
        {

            if (a[min][j] + dist[min] < dist[j] && visited[j] == 0 && a[min][j] != 0)
            {

                dist[j] = a[min][j] + dist[min];
                path[j] = min;
            }
        }

        visited[min] = 1;
        min_num = 999;
    }
    printf("\n\t\tROUTE THAT COSTS LESS TO REACH DESTINATION IS:--\n");

    if (path[p] == src)
    {

        fp = fopen("city.txt", "r");

        for (i = 0; i < 9; i++)
        {

            fscanf(fp, "%s %d", s, &d);
            if (d == src)
            {

                printf("\t\t%s -->\t", s);
            }
            if (d == p)
            {

                printf("%s\n", s);
            }
        }

        fclose(fp);
        return;
    }
    fp = fopen("city.txt", "r");

    for (i = 0; i < 9; i++)
    {

        fscanf(fp, "%s %d", s, &d);
        if (d == src)
        {

            printf("\t\t%s -->\t", s);
        }
        if (d == path[p])
        {

            printf("%s -->\t", s);
        }
        if (d == p)
        {

            printf("%s\n", s);
        }
    }
    fclose(fp);
    return;
}

void maps1()
{

    char curr[30], dest[30], a[30];
    int i, j, d, flag = 0;
    FILE *fp;
    printf("\n\t\tCRIME LOCATION AREA\n");
    strcpy(curr, "vidyanagar");

    scanf("%s", dest);
    fp = fopen("city.txt", "r");

    for (i = 0; i < 9; i++)
    {

        fscanf(fp, "%s %d", a, &d);
        if (strcmp(a, curr) == 0)
        {

            src = d;
            flag = 1;
        }
        if (strcmp(a, dest) == 0)
        {

            p = d;
            flag = 2;
        }
    }

    fclose(fp);
    if (flag == 0)
    {

        printf("INVALID AREA LOCATIONS\n");
        return;
    }
    dijkstra1();
}

void dijkstra1()
{

    FILE *fp;
    char s[30];
    int d;

    int i, j, a[9][9] = {{0, 15, 16, 37, 18, 10, 41, 29, 30}, {15, 0, 13, 26, 37, 25, 24, 28, 18}, {16, 13, 0, 20, 34, 29, 45, 21, 30}, {37, 26, 20, 0, 25, 30, 35, 29, 40}, {18, 37, 34, 25, 0, 45, 36, 27, 29}, {10, 25, 29, 30, 45, 0, 28, 38, 40}, {41, 24, 29, 35, 36, 28, 0, 18, 15}, {29, 28, 21, 29, 27, 38, 18, 0, 12}, {30, 18, 30, 40, 29, 40, 15, 16, 0}};

    for (i = 0; i < 9; i++)
    {

        dist[i] = a[src][i];
        path[i] = src;
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {

            if (visited[j] == 0)
            {

                if (dist[j] < min_num)
                {

                    min_num = dist[j];
                    min = j;
                }
            }
        }

        for (j = 0; j < 9; j++)
        {

            if (a[min][j] + dist[min] < dist[j] && visited[j] == 0 && a[min][j] != 0)
            {

                dist[j] = a[min][j] + dist[min];
                path[j] = min;
            }
        }
        visited[min] = 1;
        min_num = 999;
    }

    printf("\n\t\tROUTE THAT COSTS LESS TIME TO REACH CRIME SCENE IS:--\n");

    if (path[p] == src)
    {

        fp = fopen("city.txt", "r");

        for (i = 0; i < 9; i++)
        {

            fscanf(fp, "%s %d", s, &d);
            if (d == src)
            {

                printf("\t\t%s -->\t", s);
            }
            if (d == p)
            {

                printf("%s\n", s);
            }
        }

        fclose(fp);
        return;
    }
    fp = fopen("city.txt", "r");

    for (i = 0; i < 9; i++)
    {

        fscanf(fp, "%s %d", s, &d);
        if (d == src)
        {

            printf("\t\t%s -->\t", s);
        }
        if (d == path[p])
        {

            printf("%s -->\t", s);
        }
        if (d == p)
        {

            printf("%s\n", s);
        }
    }

    fclose(fp);
    return;
}

void maps2()
{
    char curr[30], dest[30], a[30];
    int i, j, d, flag = 0;
    FILE *fp;
    printf("\n\t\tENTER CURRENT AREA AND DESTINATION AREA(ENTER ANY OF VIDYANAGAR/VIJAYNAGAR/AMARGOL)\n");
    fflush(stdin);
    scanf("%s", curr);
    fflush(stdin);
    scanf("%s", dest);
    fp = fopen("city.txt", "r");

    for (i = 0; i < 9; i++)
    {

        fscanf(fp, "%s %d", a, &d);
        if (strcmp(a, curr) == 0)
        {

            src = d;
            flag = 1;
        }
        if (strcmp(a, dest) == 0)
        {

            p = d;
            flag = 2;
        }
    }
    fclose(fp);

    if (flag == 0)
    {

        printf("INVALID AREA LOCATONS\n");
        return;
    }
    dijkstra2();
}

void dijkstra2()
{

    FILE *fp;
    char s[30];
    int d;

    int i, j, a[9][9] = {{0, 15, 16, 37, 18, 10, 41, 29, 30}, {15, 0, 13, 26, 37, 25, 24, 28, 18}, {16, 13, 0, 20, 34, 29, 45, 21, 30}, {37, 26, 20, 0, 25, 30, 35, 29, 40}, {18, 37, 34, 25, 0, 45, 36, 27, 29}, {10, 25, 29, 30, 45, 0, 28, 38, 40}, {41, 24, 29, 35, 36, 28, 0, 18, 15}, {29, 28, 21, 29, 27, 38, 18, 0, 12}, {30, 18, 30, 40, 29, 40, 15, 16, 0}};

    for (i = 0; i < 9; i++)
    {

        dist[i] = a[src][i];
        path[i] = src;
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    for (i = 0; i < 9; i++)
    {

        for (j = 0; j < 9; j++)
        {

            if (visited[j] == 0)
            {

                if (dist[j] < min_num)
                {

                    min_num = dist[j];
                    min = j;
                }
            }
        }

        for (j = 0; j < 9; j++)
        {

            if (a[min][j] + dist[min] < dist[j] && visited[j] == 0 && a[min][j] != 0)
            {

                dist[j] = a[min][j] + dist[min];
                path[j] = min;
            }
        }
        visited[min] = 1;
        min_num = 999;
    }
    printf("\n\t\tROUTE THAT COSTS LESS TO REACH DESTINATION IS:--\n");

    if (path[p] == src)
    {

        fp = fopen("city.txt", "r");

        for (i = 0; i < 9; i++)
        {

            fscanf(fp, "%s %d", s, &d);
            if (d == src)
            {

                printf("\t\t%s -->\t", s);
            }
            if (d == p)
            {

                printf("%s\n", s);
            }
        }
        fclose(fp);

        return;
    }
    fp = fopen("city.txt", "r");

    for (i = 0; i < 9; i++)
    {

        fscanf(fp, "%s %d", s, &d);
        if (d == src)
        {

            printf("\t\t%s -->\t", s);
        }
        if (d == path[p])
        {

            printf("%s -->\t", s);
        }
        if (d == p)
        {

            printf("%s\n", s);
        }
    }

    fclose(fp);
    return;
}

void maps3()
{

    char curr[30], dest[30], a[30];
    int i, j, d, flag = 0;
    FILE *fp;
    printf("\n\t\tENTER THE AREA WHERE THE NATURAL DISASTER HAS OCCURED AND THE AREA WHERE YOU NEED TO GET SUPPLIES FROM(ENTER ANY OF VIDYANAGAR/VIJAYNAGAR/AMARGOL)\n");
    fflush(stdin);
    scanf("%s", curr);
    fflush(stdin);
    scanf("%s", dest);
    fp = fopen("city.txt", "r");

    for (i = 0; i < 9; i++)
    {

        fscanf(fp, "%s %d", a, &d);
        if (strcmp(a, curr) == 0)
        {

            src = d;
            flag = 1;
        }
        if (strcmp(a, dest) == 0)
        {

            p = d;
            flag = 2;
        }
    }
    fclose(fp);

    if (flag == 0)
    {

        printf("INVALID AREA LOCATONS\n");
        return;
    }
    dijkstra3();
}

void dijkstra3()
{
    FILE *fp;
    char s[30];
    int d;

    int i, j, a[9][9] = {{0, 15, 16, 37, 18, 10, 41, 29, 30}, {15, 0, 13, 26, 37, 25, 24, 28, 18}, {16, 13, 0, 20, 34, 29, 45, 21, 30}, {37, 26, 20, 0, 25, 30, 35, 29, 40}, {18, 37, 34, 25, 0, 45, 36, 27, 29}, {10, 25, 29, 30, 45, 0, 28, 38, 40}, {41, 24, 29, 35, 36, 28, 0, 18, 15}, {29, 28, 21, 29, 27, 38, 18, 0, 12}, {30, 18, 30, 40, 29, 40, 15, 16, 0}};

    for (i = 0; i < 9; i++)
    {

        dist[i] = a[src][i];
        path[i] = src;
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    for (i = 0; i < 9; i++)
    {

        for (j = 0; j < 9; j++)
        {

            if (visited[j] == 0)
            {

                if (dist[j] < min_num)
                {

                    min_num = dist[j];
                    min = j;
                }
            }
        }

        for (j = 0; j < 9; j++)
        {

            if (a[min][j] + dist[min] < dist[j] && visited[j] == 0 && a[min][j] != 0)
            {

                dist[j] = a[min][j] + dist[min];
                path[j] = min;
            }
        }

        visited[min] = 1;
        min_num = 999;
    }

    printf("\n\t\tROUTE THAT COSTS LESS TO REACH THE DESTINATION IS:--\n");

    if (path[p] == src)
    {
        fp = fopen("city.txt", "r");

        for (i = 0; i < 9; i++)
        {

            fscanf(fp, "%s %d", s, &d);
            if (d == src)
            {

                printf("\t\t%s -->\t", s);
            }
            if (d == p)
            {

                printf("%s\n", s);
            }
        }
        fclose(fp);

        return;
    }

    fp = fopen("city.txt", "r");

    for (i = 0; i < 9; i++)
    {

        fscanf(fp, "%s %d", s, &d);
        if (d == src)
        {

            printf("\t\t%s -->\t", s);
        }
        if (d == path[p])
        {

            printf("%s -->\t", s);
        }
        if (d == p)
        {

            printf("%s\n", s);
        }
    }

    fclose(fp);
    return;
}

void calculateTax(FILE *fp)
{

    CITIZEN e;
    float tax_amt;

    for (int i = 0; i < n; i++)
    {

        fscanf(fp, "%d %s %f %s %s %s", &e.id, e.name, &e.income, e.gender, e.addr, e.phone);
        if (e.income < 10000)
        {

            tax_amt = 0;
        }
        else if (e.income < 50000)
        {

            tax_amt = e.income * 0.1;
        }
        else if (e.income < 100000)
        {

            tax_amt = e.income * 0.2;
        }
        else
        {

            tax_amt = e.income * 0.3;
        }
        printf("The tax amount of the citizen with the id %d is %.2f\n", e.id, tax_amt);
    }
}

void welcome()
{

    printf("\n\n\n\n\n\t\t[ [ [ WELCOME TO OUR CITY MANAGEMENT SYSTEM ] ] ]\n\n\n\n\n\n\n\t");
    system("pause");
}

void bfs(int m[9][9], int v, int source)
{

    FILE *fp;
    char s[100];
    int d;
    int queue[20], r = 0, f = 0, i, u, visited[10];

    for (i = 0; i < v; i++)
        visited[i] = 0;

    queue[r] = source;
    visited[source] = 1;
    printf("The path to be followed to supply the water to the city can be\n");

    while (f <= r)
    {

        u = queue[f];
        fp = fopen("city.txt", "r");
        for (int j = 0; j < 9; j++)
        {

            fscanf(fp, "%s %d", s, &d);
            if (u == d)
            {

                printf("%s -->", s);
            }
        }
        fclose(fp);

        f += 1;
        for (i = 0; i < v; i++)
        {

            if (m[u][i] == 1 && visited[i] == 0)
            {

                visited[i] = 1;
                r += 1;
                queue[r] = i;
            }
        }
    }
}

void heapsort()
{

    P temp;
    int i = 0;
    FILE *fp;
    fp = fopen("sort.txt", "r");

    while (!feof(fp))
    {

        fscanf(fp, "%s %d", ar[i].name, &ar[i].pop);
        i++;
    }

    n2 = i;
    fclose(fp);

    for (i = (n2 / 2) - 1; i >= 0; i--)
    {

        heapify(ar, n2, i);
    }

    for (i = n2 - 1; i > 0; i--)
    {

        temp = ar[0];
        ar[0] = ar[i];
        ar[i] = temp;
        heapify(ar, i, 0);
    }
}

void heapify(P ar[90], int n2, int i)
{

    P temp;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n2 && ar[l].pop > ar[largest].pop)
    {

        largest = l;
    }

    if (r < n2 && ar[r].pop > ar[largest].pop)
    {
        largest = r;
    }

    if (largest != i)
    {

        temp = ar[i];
        ar[i] = ar[largest];
        ar[largest] = temp;
        heapify(ar, n2, largest);
    }
}

void printarray()
{

    int i;

    for (i = 0; i < n2; i++)
    {
        printf("%s %d\n", ar[i].name, ar[i].pop);
    }
}

void login()
{

    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do
    {

        printf("\n  ======================  LOGIN FORM  ======================  \n");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n                       ENTER PASSWORD:-");
        while (i < 10)
        {

            pword[i] = getchar();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }

        pword[i] = '\0';

        i = 0;

        if (strcmp(uname, "user") == 0 && strcmp(pword, "pass") == 0)
        {
            printf("  \n\n\n    WELCOME TO POLICE FIR RECORD MANAGEMENT SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\tPress any key to continue...");
            getchar(); // holds the screen
            break;
        }

        else
        {

            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;

            getchar();
            system("cls");
        }
    } while (a <= 2);
    if (a > 2)
    {

        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getchar();
    }
    system("cls");
}

void addrecord();

void viewrecord();

void editrecord();

void searchrecord();

void deleterecord();

void login();

void close2()
{

    printf("\n\n\t\tTHANK YOU");
}

struct record

{
    char id[10];

    char name[30];

    char age[6];

    char gender[10];

    char weight[20];

    char height[20];

    char haircolor[20];

    char eyecolor[20];

    char crime[40];

    char details[20];

    char court[20];

    char act[20];

    char punishment[50];

    char faddress[20];

    char fir[20];

    char emergencyc[20];

    char emergencyr[20];

    char datearr[20];

} a;

void menu1()
{
    login();

    int ch;
    printf("\n\n\t====================================\n");
    printf("\t   -POLICE FIR RECORD MANAGEMENT SYSTEM-\n");
    printf("\t====================================");

    while (1)
    {

        printf("\n\n\t\t::MAIN MENU::");

        printf("\n\n\t\tADD FIR RECORD\t[ENTER-1]");

        printf("\n\t\tSEARCH RECORD\t[ENTER-2]");

        printf("\n\t\tMODIFY RECORD\t[ENTER-3]");

        printf("\n\t\tLIST RECORD\t[ENTER-4]");

        printf("\n\t\tDELETE RECORD\t[ENTER-5]");

        printf("\n\t\tEXIT\t\t[ENTER-6]");

        printf("\n\n\t=> ENTER YOUR CHOICE:");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            addrecord();
            break;

        case 2:
            searchrecord();
            break;

        case 3:
            editrecord();
            break;

        case 4:
            viewrecord();
            break;

        case 5:
            deleterecord();
            break;
        }

        printf("\n\n\tENTER 1 TO GO TO THE MAINMENU AND 0 TO EXIT\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            continue;
            system("cls");
        }
        else if (ch == 0)
            break;
    }
}

void addrecord()

{
    system("cls");
    FILE *fp;
    char another = 'Y', id[10];
    char filename[30];
    int choice;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t  - ADD RECORDS -");
    printf("\n\t\t====================================\n");
    printf("\n\n\tENTER FIRST NAME OF CONVICT(To Check whether record exists or not): ");

    fflush(stdin);
    gets(filename);

    fp = fopen("filename", "ab+");

    if (fp == NULL)
    {

        fp = fopen("filename", "wb+");
        if (fp == NULL)
        {

            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getchar();
            return;
        }
    }

    while (another == 'Y' || another == 'y')

    {
        choice = 0;
        fflush(stdin);

        printf("\tENTER CONVICT CODE(To check whether it matches or not): ");
        scanf("%s", id);

        rewind(fp);

        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (strcmp(a.id, id) == 0)
            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice = 1;
            }
        }

        if (choice == 0)
        {

            strcpy(a.id, id);

            printf("\n\tENTER NAME OF CONVICT: ");
            fflush(stdin);
            gets(a.name);

            printf("\tENTER SEX: ");
            gets(a.gender);
            fflush(stdin);

            printf("\tENTER AGE: ");
            gets(a.age);
            fflush(stdin);

            printf("\tENTER WEIGHT: ");
            gets(a.weight);
            fflush(stdin);

            printf("\tENTER HEIGHT(FT): ");
            gets(a.height);
            fflush(stdin);

            printf("\tENTER HAIRCOLOR: ");
            gets(a.haircolor);
            fflush(stdin);

            printf("\tENTER EYECOLOR: ");
            gets(a.eyecolor);
            fflush(stdin);

            printf("\tENTER FACE DETAILS: ");
            gets(a.details);
            fflush(stdin);

            printf("\tENTER CRIME: ");
            gets(a.crime);
            fflush(stdin);

            printf("\tENTER COURT: ");
            gets(a.court);
            fflush(stdin);

            printf("\tACT(under which convicted): ");
            gets(a.act);
            fflush(stdin);

            printf("\tENTER CONVICTION: ");
            gets(a.punishment);
            fflush(stdin);

            strcpy(a.faddress, "VIDYANAGAR");
            fflush(stdin);

            printf("\tENTER FIR NUMBER: ");
            gets(a.fir);
            fflush(stdin);

            printf("\tENTER EMERGENCY CONTACT: ");
            gets(a.emergencyc);
            fflush(stdin);

            printf("\tENTER RELATION OF EMERGENCY CONTACT WITH CONVICT: ");
            gets(a.emergencyr);
            fflush(stdin);

            printf("\tENTER DATE OF ARREST: ");
            gets(a.datearr);

            fwrite(&a, sizeof(a), 1, fp);
            printf("\nYOUR RECORD IS ADDED...\n");
        }

        printf("\n\tADD ANOTHER RECORD...(Y/N) \t");
        fflush(stdin);
        another = getchar();
    }

    fclose(fp);
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getchar();
}

void searchrecord()

{
    system("cls");
    FILE *fp;
    char id[16], choice, filename[14];
    int ch;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- SEARCH RECORDS -");
    printf("\n\t\t====================================\n\n");

    do
    {

        printf("\n\tENTER THE PRISONER NAME TO BE SEARCHED:");
        fflush(stdin);
        gets(filename);

        fp = fopen("filename", "rb");

        printf("\nENTER CONVICT CODE:");
        gets(id);
        system("cls");
        printf("\nTHE WHOLE RECORD IS:");

        while (fread(&a, sizeof(a), 1, fp) == 1)

            if (strcmpi(a.id, id) == 0)
            {
                printf("\n");
                printf("\nCONVICT'S NAME IS: %s", a.name);

                printf("\nCONVICT'S GENDER IS: %s", a.gender);

                printf("\nCONVICT'S AGE IS: %s", a.age);

                printf("\nCONVICT'S WEIGHT IS: %s", a.weight);

                printf("\nCONVICT'S HEIGHT IS: %s", a.height);

                printf("\nCONVICT'S HAIRCOLOR IS: %s", a.haircolor);

                printf("\nCONVICT'S EYECOLOR IS: %s", a.eyecolor);

                printf("\nCONVICT'S CRIME IS: %s", a.crime);

                printf("\nFACE DETAIL: %s", a.details);

                printf("\nCOURT IS: %s", a.court);
                printf("\nACT IS: %s", a.act);

                printf("\nPRISONER'S CONVICTION IS: %s", a.punishment);

                printf("\nADDRESS OF POLICE STATION: %s", a.faddress);

                printf("\nFIR NUMBER IS: %s", a.fir);
                printf("\nCONVICT'S EMERGENCY CONTACT IS: %s", a.emergencyc);

                printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s", a.emergencyr);

                printf("\nARRESTED DATE: %s", a.datearr);

                printf("\n");
            }

        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
        fflush(stdin);

        scanf("%c", &choice);

    } while (choice == 'Y' || choice == 'y');

    fclose(fp);
    getchar();
    return;
    getchar();
}

void editrecord()

{

    system("cls");
    FILE *fp;
    char id[10], choice, filename[14];
    int num, count = 0;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- MODIFY RECORDS -");
    printf("\n\t\t====================================\n\n");

    do
    {

        printf("\n\tENTER THE CONVICT'S' NAME TO BE EDITED:");
        fflush(stdin);
        gets(filename);

        printf("\n\tENTER ID:");
        gets(id);
        fp = fopen("filename", "rb+");

        while (fread(&a, sizeof(a), 1, fp) == 1)
        {

            if (strcmp(a.id, id) == 0)
            {

                printf("\nYOUR OLD RECORD WAS AS:");

                printf("\nCONVICT'S NAME: %s", a.name);

                printf("\nCONVICT'S SEX: %s", a.gender);
                printf("\nCONVICT'S AGE: %s", a.age);

                printf("\nCONVICT'S WEIGHT: %s", a.weight);

                printf("\nCONVICT'S HEIGHT: %s", a.height);

                printf("\nCONVICT'S HAIRCOLOR: %s", a.haircolor);

                printf("\nCONVICT'S EYECOLOR: %s", a.eyecolor);

                printf("\nCONVICT'S CRIME: %s", a.crime);

                printf("\nFACE DETAILS: %s", a.details);
                printf("\nCOURT: %s", a.court);

                printf("\nCONVICT'S ACT: %s", a.act);

                printf("\nCONVICT'S CONVICTION: %s", a.punishment);
                printf("\nADDRESS OF POLICE STATION: %s", a.faddress);

                printf("\nFIR NUMBER: %s", a.fir);
                printf("\nCONVICT'S EMERGENCY CONTACT: %s", a.emergencyc);

                printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT: %s", a.emergencyr);
                printf("\nARRESTED DATE: %s", a.datearr);

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                printf("\n1.NAME.");

                printf("\n2.SEX.");

                printf("\n3.AGE.");

                printf("\n4.WEIGHT.");

                printf("\n5.HEIGHT.");

                printf("\n6.HAIRCOLOR.");

                printf("\n7.EYECOLOR.");

                printf("\n8.CRIME.");

                printf("\n9.FACE DETAILS.");

                printf("\n10.COURT.");

                printf("\n11.ACT.");
                printf("\n12.CONVICTION.");
                printf("\n13.ADDRESS OF POLICE STATION.");
                printf("\n14.FIR NUMBER.");
                printf("\n15.EMERGENCY CONTACT.");
                printf("\n16.RELATION OF EMERGENCY CONTACT.");
                printf("\n17.ARRESTED DATE.");
                printf("\n18.WHOLE RECORD.");
                printf("\n19.GO BACK TO MAIN MENU.");

                do
                {

                    printf("\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                    scanf("%d", &num);
                    fflush(stdin);

                    switch (num)
                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNAME:");
                        gets(a.name);
                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nSEX:");
                        gets(a.gender);
                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nAGE:");
                        gets(a.age);
                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nWEIGHT:");
                        gets(a.weight);
                        break;

                    case 5:
                        printf("ENTER THE NEW DATA:");
                        printf("\nHEIGHT:");
                        gets(a.height);
                        break;

                    case 6:
                        printf("ENTER THE NEW DATA:");
                        printf("\nHAIRCOLOR:");
                        gets(a.haircolor);
                        break;

                    case 7:
                        printf("ENTER THE NEW DATA:");
                        printf("\nEYECOLOR:");
                        gets(a.eyecolor);
                        break;

                    case 8:
                        printf("ENTER THE NEW DATA:");
                        printf("\nCRIME:");
                        gets(a.crime);
                        break;

                    case 9:
                        printf("ENTER THE NEW DATA:");
                        printf("\nFACE DETAILS:");
                        gets(a.details);
                        break;

                    case 10:
                        printf("ENTER THE NEW DATA:");
                        printf("\nCOURT:");
                        gets(a.court);
                        break;

                    case 11:
                        printf("ENTER THE NEW DATA:");
                        printf("\nACT:");
                        gets(a.act);
                        break;

                    case 12:
                        printf("ENTER THE NEW DATA:");
                        printf("\nCONVICTION:");
                        gets(a.punishment);
                        break;

                    case 13:
                        printf("ENTER THE NEW DATA:");
                        printf("\nADDRESS OF POLICE STATION:");
                        gets(a.faddress);
                        break;

                    case 14:
                        printf("ENTER THE NEW DATA:");
                        printf("\nFIR NUMBER:");
                        gets(a.fir);
                        break;

                    case 15:
                        printf("ENTER THE NEW DATA:");
                        printf("\nEMERGENCY CONTACT:");
                        gets(a.emergencyc);
                        break;

                    case 16:
                        printf("ENTER THE NEW DATA:");
                        printf("\nRELATION OF EMERGENCY CONTACT:");
                        gets(a.emergencyr);
                        break;

                    case 17:
                        printf("ENTER THE NEW DATA:");
                        printf("\nARRESTED DATE:");
                        gets(a.emergencyc);
                        break;

                    case 18:
                        printf("ENTER THE NEW DATA:");
                        printf("\tCONVICT'S NAME:");
                        gets(a.name);
                        printf("\tSEX:");
                        gets(a.gender);
                        printf("\tAGE:");
                        gets(a.age);
                        printf("\tWEIGHT:");
                        gets(a.weight);
                        printf("\tHEIGHT:");
                        gets(a.height);
                        printf("\tHAIRCOLOR:");
                        gets(a.haircolor);
                        printf("\tEYECOLOR:");
                        gets(a.eyecolor);
                        printf("\tCRIME:");
                        gets(a.age);
                        printf("\tFACE DETAILS:");
                        gets(a.details);
                        printf("\tCOURT:");
                        gets(a.court);
                        printf("\tACT:");
                        gets(a.act);
                        printf("\tCONVICTION:");
                        gets(a.punishment);
                        printf("\tADDRESS OF POLICE STATION:");
                        gets(a.faddress);
                        printf("\tFIR NUMBER:");
                        gets(a.fir);
                        printf("\tEMERGENCY CONTACT:");
                        gets(a.emergencyc);
                        printf("\tRELATION OF EMERGENCY CONTACT WITH CONVICT:");
                        gets(a.emergencyr);
                        printf("\tARRESTED DATE:");
                        gets(a.datearr);
                        break;

                    case 19:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");
                        getchar();
                        return;
                        break;

                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                        break;
                    }

                } while (num < 1 || num > 20);

                fseek(fp, -sizeof(a), SEEK_CUR);

                fwrite(&a, sizeof(a), 1, fp);

                fseek(fp, -sizeof(a), SEEK_CUR);

                fread(&a, sizeof(a), 1, fp);

                choice = 5;

                break;
            }
        }

        if (choice == 5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");
            printf("--------------------\n");
            printf("THE NEW RECORD IS:\n");
            printf("--------------------\n");
            printf("\nCONVICT'S NAME IS: %s", a.name);
            printf("\nCONVICT'S SEX IS: %s", a.gender);
            printf("\nCONVICT'S AGE IS: %s", a.age);
            printf("\nCONVICT'S WEIGHT IS: %s", a.weight);
            printf("\nCONVICT'S HEIGHT IS: %s", a.height);
            printf("\nCONVICT'S HAIRCOLOR IS: %s", a.haircolor);
            printf("\nCONVICT'S EYECOLOR IS: %s", a.eyecolor);
            printf("\nCONVICT'S CRIME IS: %s", a.crime);
            printf("\nFACE DETAILS: %s", a.details);
            printf("\nCOURT IS: %s", a.court);
            printf("\nACT: %s", a.act);
            printf("\nCONVICT'S CONVICTION IS: %s", a.punishment);
            printf("\nADDRESS OF POLICE STATION: %s", a.faddress);
            printf("\nFIR NUMBER: %s", a.fir);
            printf("\nCONVICT'S EMERGENCY CONTACT IS: %s", a.emergencyc);
            printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s", a.emergencyr);
            printf("\nARRESTED DATE: %s", a.datearr);

            fclose(fp);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
            scanf("%c", &choice);
            count++;
        }

        else
        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
            scanf("%c", &choice);
        }
    }

    while (choice == 'Y' || choice == 'y');

    fclose(fp);
    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    getchar();
}

void viewrecord()

{
    system("cls");
    FILE *fp;

    char filename[30];

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t - LIST RECORDS -");
    printf("\n\t\t====================================\n");

    fp = fopen("filename", "rb");
    rewind(fp);

    while ((fread(&a, sizeof(a), 1, fp)) == 1)
    {

        printf("\n\n\t\t::PRESS ENTER TO VIEW MORE RECORDS!::\n");
        printf("\nCONVICT'S NAME IS: %s", a.name);
        printf("\nCONVICT'S SEX IS: %s", a.gender);
        printf("\nCONVICT'S AGE IS: %s", a.age);
        printf("\nCONVICT'S WEIGHT IS: %s", a.weight);
        printf("\nCONVICT'S HEIGHT IS: %s", a.height);
        printf("\nCONVICT'S HAIRCOLOR IS: %s", a.haircolor);
        printf("\nCONVICT'S EYECOLOR IS: %s", a.eyecolor);
        printf("\nCONVICT'S CRIME IS: %s", a.crime);
        printf("\nFACE DETAILS: %s", a.details);
        printf("\nCOURT IS: %s", a.court);
        printf("\nACT: %s", a.act);
        printf("\nCONVICT'S CONVICTION IS: %s", a.punishment);
        printf("\nADDRESS OF POLICE STATION: %s", a.faddress);
        printf("\nFIR NUMBER: %s", a.fir);
        printf("\nCONVICT'S EMERGENCY CONTACT IS: %s", a.emergencyc);
        printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s", a.emergencyr);
        printf("\nARRESTED DATE: %s", a.datearr);
        getchar();
    }
    fclose(fp);
    getchar();
}

void deleterecord()

{

    system("cls");
    FILE *fp, *ft;
    struct record file;
    char filename[15], another = 'Y', id[16];
    ;
    int choice, check;
    int j = 0;
    char pass[8];

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- DELETE RECORDS -");
    printf("\n\t\t====================================\n\n");

    printf("\nENTER PASSWORD\n");
    int i;

    for (i = 0; i < 4; i++)
    {
        pass[i] = getchar();
        printf("*");
    }

    if (strcmpi(pass, "pass") == 0)
    {

        printf("\n\t\t*ACCESS GRANTED*\n\n");
        while (another == 'Y' || another == 'y')

        {

            printf("\n\tENTER THE NAME OF CONVICT TO BE DELETED:");
            fflush(stdin);
            gets(filename);
            fp = fopen("filename", "rb");

            if (fp == NULL)
            {
                printf("\nTHE FILE DOES NOT EXIST");
                printf("\nPRESS ANY KEY TO GO BACK.");
                getchar();
                return;
            }
            ft = fopen("temp", "wb");

            if (ft == NULL)
            {
                printf("\nSYSTEM ERROR");
                printf("\nPRESS ANY KEY TO GO BACK");
                getchar();
                return;
            }
            printf("\n\tENTER THE ID OF RECORD TO BE DELETED:");
            fflush(stdin);
            gets(id);

            while (fread(&file, sizeof(file), 1, fp) == 1)

            {

                if (strcmp(file.id, id) != 0)

                    fwrite(&file, sizeof(file), 1, ft);
            }
            fclose(ft);
            fclose(fp);
            remove("filename");
            rename("temp", "filename");
            printf("\nDELETED SUCCESFULLY...");
            getchar();

            printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
            fflush(stdin);
            scanf("%c", &another);
        }

        printf("\n\n\tPRESS ANY KEY TO EXIT...");

        getchar();
    }

    else
    {
        printf("\nSorry!Invalid password\n");
        exit(0);
    }
}

void hospital()
{

    char curr[30], a[30];
    int i, j, d1, flag = 0, src = 0;
    FILE *fp;
    printf("\n\t\tENTER CURRENT AREA\n");
    fflush(stdin);
    scanf("%s", curr);
    fp = fopen("city.txt", "r");

    for (i = 0; i < 9; i++)
    {
        fscanf(fp, "%s %d", a, &d1);

        if (strcmp(a, curr) == 0)
        {
            src = d1;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        fclose(fp);
        printf("\t\tPLEASE ENTER VALID LOCATION\n");
        return;
    }

    fclose(fp);

    int k, d[9][9] = {{0, 1, 0, 0, 0, 1, 0, 0, 0},
                      {0, 0, 0, 0, 1, 0, 1, 0, 0},
                      {0, 0, 1, 0, 0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 0, 1, 0, 1, 0},
                      {0, 0, 0, 0, 1, 0, 0, 0, 0},
                      {0, 0, 1, 0, 0, 0, 0, 0, 1},
                      {0, 0, 0, 0, 1, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    for (k = 0; k < 9; k++)
    {
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (d[i][j] != 1)
                {
                    if (d[i][k] == 1 && d[k][j] == 1)
                        d[i][j] = 1;
                }
            }
        }
    }

    if (src == 4)
    {
        printf("YUP!!! YOU HAVE A ROUTE TO HOSPITAL FROM YOUR LOCATION\n");
    }

    else if (d[src][4] == 1)
    {
        printf("YUP!!! YOU HAVE A ROUTE TO HOSPITAL FROM YOUR LOCATION\n");
    }

    else
    {
        printf("NOPE!!! YOU DON'T HAVE A ROUTE TO HOSPITAL FROM YOUR LOCATION\n");
    }
}

int main()
{
    int m[9][9] = {{0, 1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 0, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 0, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 0, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 0, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 0, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 0, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 0, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1, 0}};

    int source = 0, v = 9;
    FILE *fp;
    char username[10], password[10];
    int option, c, i, k, d;
    char a[100];

    if ((fp) == NULL)
    {
        printf("cant open file\n");
    }

    else
    {
        printHead();
        welcome();
        printHead();
        int i;
        i = 0;
    }

    printHead();

    while (1)
    {
        printf("\n\n\n\t\t\t\tMain Menu");

        printf("\n\n\n");

        printf("\n\n\t\t\t1. Add Citizen");

        printf("\n\n\t\t\t2. Delete Citizen");

        printf("\n\n\t\t\t3. Search Record");

        printf("\n\n\t\t\t4. Display Citizen List");

        printf("\n\n\t\t\t5. Display population of the city");

        printf("\n\n\t\t\t6. THE PATH TO BE FOLLOWED TO GET MINIMUM LENGTH(IN KM) OF WIRES REQUIRED FOR INSTALLING MOBILE TOWERS\n");

        printf("\n\n\t\t\t7. DISPLAY THE NAMES OF AREAS IN THE CITY");

        printf("\n\n\t\t\t8. SHORTEST ROUTE TO MOVE FROM ONE AREA TO ANOTHER");

        printf("\n\n\t\t\t9. CALCULATE TAX OF CITIZEN");

        printf("\n\n\t\t\t10. THE PATH TO BE FOLLOWED TO GET MINIMUM LENGTH(IN KM) OF WIRES TO INSTALL THE STREET LIGHTS ACROSS THE CITY");

        printf("\n\n\t\t\t11. THE PATH TO FOLLOW TO SUPPLY WATER ACROSS THE CITY");

        printf("\n\n\t\t\t12. THE SHORTEST PATH FOLLOWED TO REACH THE CRIME DESTINATION FROM THE SOURCE(VIDYANAGAR)");

        printf("\n\n\t\t\t13. THE SHORTEST PATH FOLLOWED FOR THE AMBULANCE TO REACH THE DESTINATION FROM ANY OF THE 3 HOSPITALS");

        printf("\n\n\t\t\t14. SORT THE AREAS WITH RESPECT TO NO.OF FAMILIES LIVING IN IT AND DISPLAY THEM");
        printf("\n\n\t\t\t15. BANK MANAGEMENT SYSTEM(LOCATED IN VIDYANAGAR)");

        printf("\n\n\t\t\t16. THE PATH TO BE FOLLOWED TO GET MINIMUM LENGTH(IN KM) OF WIRES REQUIRED FOR TELEVISION\n");

        printf("\n\n\t\t\t17. THE SHORTEST PATH FOLLOWED TO REACH THE DESTINATION WHERE NATURAL DISASTER HAS OCCURED FROM THE SOURCE\n");

        printf("\n\n\t\t\t18. POLICE FIR RECORD MANAGEMENT SYSTEM(LOCATED IN VIDYANAGAR)");

        printf("\n\n\t\t\t19. CHECK IF YOU HAVE A HOSPITAL ROUTE TO THE CURRENT LOCATION");

        printf("\n\n\t\t\t20. EXIT");

        printf("\n\n\t\tEnter Your Option :--> ");

        scanf("%d", &option);

        switch (option)
        {

        case 1:
            fp = fopen("text.txt", "a");
            add1(fp);
            fclose(fp);
            break;

        case 2:
            fp = fopen("text.txt", "r");
            fp = del(fp);
            fclose(fp);
            fp = fopen("popln.txt", "r");
            fscanf(fp, "%d", &k);
            fclose(fp);
            fp = fopen("popln.txt", "w");
            fprintf(fp, "%d", k - 1);
            fclose(fp);
            break;

        case 3:
            fp = fopen("text.txt", "r");
            searchRecord(fp);
            fclose(fp);
            break;

        case 4:
            fp = fopen("text.txt", "r");
            displayList(fp);
            fclose(fp);
            break;

        case 5:
            fp = fopen("popln.txt", "r");
            if ((fp) == NULL)
            {
                printf("cant open file\n");
                fclose(fp);
            }
            else
            {
                popl(fp);
                fclose(fp);
            }
            break;

        case 6:
            for (int i = 0; i < n1; i++)
            {
                arr[i] = i;
            }

            insertionsort(a1, 36);
            kruskals3(a1, n1, arr);
            break;

        case 7:
            fp = fopen("city.txt", "r");
            printf("\n\t\tAREAS IN THE CITY ARE:-\n\n");

            for (i = 0; i < 9; i++)
            {
                fscanf(fp, "%s %d", a, &d);
                printf("\t\t%s\n", a);
            }

            fclose(fp);
            break;

        case 8:
            maps();
            break;

        case 9:
            fp = fopen("text.txt", "r");
            if ((fp) == NULL)
            {
                printf("cant open file\n");
                fclose(fp);
            }
            else
            {
                calculateTax(fp);
                fclose(fp);
            }
            break;

        case 10:
            for (int i = 0; i < n1; i++)
            {
                arr[i] = i;
            }

            insertionsort(a1, 36);
            kruskals(a1, n1, arr);
            break;

        case 11:
            bfs(m, v, source);
            break;

        case 12:
            maps1();
            break;

        case 13:
            maps2();
            break;

        case 14:
            heapsort();
            printarray();
            break;

        case 15:
            menu();
            break;

        case 16:
            for (int i = 0; i < n1; i++)
            {
                arr[i] = i;
            }

            insertionsort(a1, 36);
            kruskals2(a1, n1, arr);
            break;

        case 17:
            maps3();
            break;

        case 18:
            menu1();
            break;

        case 19:
            hospital();
            break;

        case 20:
            exit(0);
            break;

        default:
            printf("\n\t\tYou Pressed wrong key");
            break;
        }
        fp = fopen("popln.txt", "r");
        fscanf(fp, "%d", &c);
        fclose(fp);
        n = c;
    }
}
