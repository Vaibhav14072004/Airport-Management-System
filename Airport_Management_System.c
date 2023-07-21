

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int login();
void options();
void availableflights();
void bookflight();
void cancelflight();
void status();

static char seat1[30][16];
static char seat2[30][16];
static char seat3[30][16];
static char seat4[30][16];
static char seat5[30][16];
int hmt = 1;

int main()
{

    int l = login();

    if (l == 0)
    {
        system("cls");
        printf("\t\t\t\t\t\t\t\tTHANKS FOR VISITING US");
    }

    else
    {

        options();
    }

    system("cls");
    printf("\t\t\t\t\t\t\t\tTHANKS FOR VISITING US");

    return 0;
}

int login()
{

    char username[] = "jiit";
    char password[] = "jiit";

    printf("\n\tUsername : ");
    char user[32];
    gets(user);

    printf("\tPassword : ");
    char pass[32];
    gets(pass);

    if (strcmp(username, user) || strcmp(password, pass))
    {
        system("cls");
        printf("\t\t\tInvalid Password!!!\n");
        printf("Do you want to try again ?\nPress 1 for yes and 2 for no : ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            char ignore[10];
            gets(ignore);
            login();
        }
        else if (choice == 2)
            return 0;
    }

    else
    {
        system("cls");
        printf("\t\t\tWelcome\n");
        return 1;
    }
}

void options()
{

    printf("1) Flights List\n");
    printf("2) Book Flights \n");
    printf("3) Cancel Flights \n");
    printf("4) See Status \n");
    printf("5) Exit \n");

    printf("Enter Choice : ");

    char CHOICE[32];
    scanf("%s", &CHOICE);

    if (!(strcmp(CHOICE, "1") && strcmp(CHOICE, "2") && strcmp(CHOICE, "3") && strcmp(CHOICE, "4") && strcmp(CHOICE, "5")))
    {

        system("cls");
        int choice;
        if (!strcmp(CHOICE, "1"))
        {
            choice = 1;
        }
        else if (!strcmp(CHOICE, "2"))
        {
            choice = 2;
        }
        else if (!strcmp(CHOICE, "3"))
        {
            choice = 3;
        }
        else if (!strcmp(CHOICE, "4"))
        {
            choice = 4;
        }
        else
        {
            choice = 5;
        }

        switch (choice)
        {
        case 1:
            availableflights();
            return;
            break;

        case 2:
            bookflight();
            return;
            break;

        case 3:
            cancelflight();
            return;
            break;

        case 4:
            status();
            return;
            break;

        case 5:
        A:
            printf("Do you really want to exit?\n");
            printf("1) No\t\t\t 2) Yes\n");
            int yesorno;
            scanf("%d", &yesorno);

            if (yesorno == 1)
            {
                system("cls");
                options();
            }
            else if (yesorno == 2)
            {
                return;
            }
            else
            {
                char ignore[20];
                gets(ignore);
                system("cls");
                printf("Invalid Input\n\n");
                goto A;
            }
        }
    }

    else
    {
        system("cls");
        printf("\t\t\t\tInvalid choice!\n\n");
        options();
    }
}

void availableflights()
{

    printf("\t\t1) Flight nO. 1\n");
    printf("\t\t2) Flight nO. 2\n");
    printf("\t\t3) Flight nO. 3\n");
    printf("\t\t4) Flight nO. 4\n");
    printf("\t\t5) Flight nO. 5\n\n");

    printf("Press b to go back : ");
    char back[32];
    scanf("%s", &back);

    if (strcmp(back, "b"))
    {
        system("cls");
        printf("\t\t\t\t\t\tInvalid Input...\n\n");
        availableflights();
    }
    else
    {
        system("cls");
        return options();
    }
}

void bookflight()
{

    printf("\t\t1) Flight nO. 1\n");
    printf("\t\t2) Flight nO. 2\n");
    printf("\t\t3) Flight nO. 3\n");
    printf("\t\t4) Flight nO. 4\n");
    printf("\t\t5) Flight nO. 5\n\n\n");

    printf("Select plane no : ");
    char planeno[32];
    scanf("%s", &planeno);

    if ((strcmp(planeno, "1") && strcmp(planeno, "2") && strcmp(planeno, "3") && strcmp(planeno, "4") && strcmp(planeno, "5")))
    {

        printf("\t\t\t\t\tInvalid Input\n\n");
        return bookflight();
    }

    else
    {
        int Plane;
        if (!strcmp(planeno, "1"))
        {
            Plane = 1;
        }
        else if (!strcmp(planeno, "2"))
        {
            Plane = 2;
        }
        else if (!strcmp(planeno, "3"))
        {
            Plane = 3;
        }
        else if (!strcmp(planeno, "4"))
        {
            Plane = 4;
        }
        else
        {
            Plane = 5;
        }

        if (hmt == 1)
        {
            for (int i = 0; i < 30; i++)
            {
                strcpy(seat1[i], "Empty");
            }
            for (int i = 0; i < 30; i++)
            {
                strcpy(seat2[i], "Empty");
            }
            for (int i = 0; i < 30; i++)
            {
                strcpy(seat3[i], "Empty");
            }
            for (int i = 0; i < 30; i++)
            {
                strcpy(seat4[i], "Empty");
            }
            for (int i = 0; i < 30; i++)
            {
                strcpy(seat5[i], "Empty");
            }
        }

        hmt = 2;

        switch (Plane)
        {
        case 1:
            printf("\t\t\t\t\t\tPlane No. 1\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat1[i], i + 2, seat1[i + 1], i + 3, seat1[i + 2]);
            printf("How many tickets you want to book? ");
            int tickets1;
            scanf("%d", &tickets1);

            for (int i = 1; i <= tickets1; i++)
            {
                printf("Passenger NO %d\n", i);
                printf("Enter preferred seat no. ");
                int seat;
                scanf("%d", &seat);

                while (strcmp(seat1[seat - 1], "Empty") || seat > 30 || seat < 1)
                {
                    printf("Sorry seat is already occupied....Enter diff seat : ");
                    scanf("%d", &seat);
                }
                printf("Enter the name of the passenger : ");
                char name[16];
                scanf("%s", &name);
                strcpy(seat1[seat - 1], name);
            }

            printf("\nThanks for booking..The total cost is %d\n", 2000 * tickets1);

            printf("Press b to go back : ");

            char back1[32] = {'h'};
            scanf("%s", &back1);

            while (strcmp(back1, "b"))
            {
                printf("\t\t\t\t\t\tInvalid Input...\n\n");
                printf("Press b to go back : ");
                scanf("%s", &back1);
            }

            system("cls");
            options();
            return;
            break;

        case 2:
            printf("\t\t\t\t\t\tPlane No. 2\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat2[i], i + 2, seat2[i + 1], i + 3, seat2[i + 2]);
            printf("How many tickets you want to book? ");
            int tickets2;
            scanf("%d", &tickets2);

            for (int i = 1; i <= tickets2; i++)
            {
                printf("Passenger NO %d\n", i);
                printf("Enter preferred seat no. ");
                int seat;
                scanf("%d", &seat);

                while (strcmp(seat2[seat - 1], "Empty") || seat > 30 || seat < 1)
                {
                    printf("Sorry seat is already occupied....Enter diff seat : ");
                    scanf("%d", &seat);
                }
                printf("Enter the name of the passenger : ");
                char name[16];
                scanf("%s", &name);
                strcpy(seat2[seat - 1], name);
            }

            printf("\nThanks for booking..The total cost is %d\n", 2000 * tickets2);

            printf("Press b to go back : ");

            char back2[32] = {'h'};
            scanf("%s", &back2);

            while (strcmp(back2, "b"))
            {
                printf("\t\t\t\t\t\tInvalid Input...\n\n");
                printf("Press b to go back : ");
                scanf("%s", &back2);
            }

            system("cls");
            options();
            return;
            break;

        case 3:
            printf("\t\t\t\t\t\tPlane No. 3\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat3[i], i + 2, seat3[i + 1], i + 3, seat3[i + 2]);
            printf("How many tickets you want to book? ");
            int tickets3;
            scanf("%d", &tickets3);

            for (int i = 1; i <= tickets3; i++)
            {
                printf("Passenger NO %d\n", i);
                printf("Enter preferred seat no. ");
                int seat;
                scanf("%d", &seat);

                while (strcmp(seat3[seat - 1], "Empty") || seat > 30 || seat < 1)
                {
                    printf("Sorry seat is already occupied....Enter diff seat : ");
                    scanf("%d", &seat);
                }
                printf("Enter the name of the passenger : ");
                char name[16];
                scanf("%s", &name);
                strcpy(seat3[seat - 1], name);
            }

            printf("\nThanks for booking..The total cost is %d\n", 2000 * tickets3);

            printf("Press b to go back : ");

            char back3[32] = {'h'};
            scanf("%s", &back3);

            while (strcmp(back3, "b"))
            {
                printf("\t\t\t\t\t\tInvalid Input...\n\n");
                printf("Press b to go back : ");
                scanf("%s", &back3);
            }

            system("cls");
            options();
            return;
            break;

        case 4:
            printf("\t\t\t\t\t\tPlane No. 4\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat4[i], i + 2, seat4[i + 1], i + 3, seat4[i + 2]);
            printf("How many tickets you want to book? ");
            int tickets4;
            scanf("%d", &tickets4);

            for (int i = 1; i <= tickets4; i++)
            {
                printf("Passenger NO %d\n", i);
                printf("Enter preferred seat no. ");
                int seat;
                scanf("%d", &seat);

                while (strcmp(seat4[seat - 1], "Empty") || seat > 30 || seat < 1)
                {
                    printf("Sorry seat is already occupied....Enter diff seat : ");
                    scanf("%d", &seat);
                }
                printf("Enter the name of the passenger : ");
                char name[16];
                scanf("%s", &name);
                strcpy(seat4[seat - 1], name);
            }

            printf("\nThanks for booking..The total cost is %d\n", 2000 * tickets4);

            printf("Press b to go back : ");

            char back4[32] = {'h'};
            scanf("%s", &back4);

            while (strcmp(back4, "b"))
            {
                printf("\t\t\t\t\t\tInvalid Input...\n\n");
                printf("Press b to go back : ");
                scanf("%s", &back4);
            }

            system("cls");
            options();
            return;
            break;

        case 5:
            printf("\t\t\t\t\t\tPlane No. 5\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat5[i], i + 2, seat5[i + 1], i + 3, seat5[i + 2]);
            printf("How many tickets you want to book? ");
            int tickets5;
            scanf("%d", &tickets5);

            for (int i = 1; i <= tickets5; i++)
            {
                printf("Passenger NO %d\n", i);
                printf("Enter preferred seat no. ");
                int seat;
                scanf("%d", &seat);

                while (strcmp(seat5[seat - 1], "Empty") || seat > 30 || seat < 1)
                {
                    printf("Sorry seat is already occupied....Enter diff seat : ");
                    scanf("%d", &seat);
                }
                printf("Enter the name of the passenger : ");
                char name[16];
                scanf("%s", &name);
                strcpy(seat5[seat - 1], name);
            }

            printf("\nThanks for booking..The total cost is %d\n", 2000 * tickets5);

            printf("Press b to go back : ");

            char back5[32] = {'h'};
            scanf("%s", &back5);

            while (strcmp(back5, "b"))
            {
                printf("\t\t\t\t\t\tInvalid Input...\n\n");
                printf("Press b to go back : ");
                scanf("%s", &back5);
            }

            system("cls");
            options();
            return;
            break;
        }
    }
}

void cancelflight()
{

    if (hmt == 1)
    {
        for (int i = 0; i < 30; i++)
        {
            strcpy(seat1[i], "Empty");
        }
        for (int i = 0; i < 30; i++)
        {
            strcpy(seat2[i], "Empty");
        }
        for (int i = 0; i < 30; i++)
        {
            strcpy(seat3[i], "Empty");
        }
        for (int i = 0; i < 30; i++)
        {
            strcpy(seat4[i], "Empty");
        }
        for (int i = 0; i < 30; i++)
        {
            strcpy(seat5[i], "Empty");
        }
    }

    hmt = 2;

    printf("Enter plane no for which the ticket is to be cancelled (b to go back) : ");
    char planeno[32];
    scanf("%s", &planeno);
    if (!strcmp(planeno, "b"))
    {
        system("cls");
        return options();
    }
    else if ((strcmp(planeno, "1") && strcmp(planeno, "2") && strcmp(planeno, "3") && strcmp(planeno, "4") && strcmp(planeno, "5")))
    {
        system("cls");
        printf("\t\t\t\t\tInvalid Input\n\n");
        return cancelflight();
    }

    else
    {
        int Plane;
        if (!strcmp(planeno, "1"))
        {
            Plane = 1;
        }
        else if (!strcmp(planeno, "2"))
        {
            Plane = 2;
        }
        else if (!strcmp(planeno, "3"))
        {
            Plane = 3;
        }
        else if (!strcmp(planeno, "4"))
        {
            Plane = 4;
        }
        else
        {
            Plane = 5;
        }

        switch (Plane)
        {
        case 1:
            system("cls");
        B:
            printf("\t\t\t\t\t\tPlane No. 1\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat1[i], i + 2, seat1[i + 1], i + 3, seat1[i + 2]);

            printf("Enter seat number corresponding to which the seat is supposed to be cancelled (0 to go back) : ");
            int cancel1;
            scanf("%d", &cancel1);
            while (cancel1 != 0)
            {
                if (strcmp(seat1[cancel1 - 1], "Empty"))
                {
                    strcpy(seat1[cancel1 - 1], "Empty");
                    system("cls");
                    printf("\t\t\t\t\tRupees 1500 have been refunded !!!\n\n\n\n");
                    goto B;
                }
                else
                {
                    system("cls");
                    printf("\t\t\t\t\t\tInvalid seat !!!\n\n\n\n");
                    goto B;
                }
            }

            system("cls");
            cancelflight();
            return;
            break;

        case 2:
            system("cls");
        C:
            printf("\t\t\t\t\t\tPlane No. 2\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat2[i], i + 2, seat2[i + 1], i + 3, seat2[i + 2]);

            printf("Enter seat number corresponding to which the seat is supposed to be cancelled (0 to go back) : ");
            int cancel2;
            scanf("%d", &cancel2);
            while (cancel2 != 0)
            {
                if (strcmp(seat2[cancel2 - 1], "Empty"))
                {
                    strcpy(seat2[cancel2 - 1], "Empty");
                    system("cls");
                    printf("\t\t\t\t\tRupees 1500 have been refunded !!!\n\n\n\n");
                    goto C;
                }
                else
                {
                    system("cls");
                    printf("\t\t\t\t\t\tInvalid seat !!!\n\n\n\n");
                    goto C;
                }
            }

            system("cls");
            cancelflight();
            return;
            break;

        case 3:
            system("cls");
        D:
            printf("\t\t\t\t\t\tPlane No. 3\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat3[i], i + 2, seat3[i + 1], i + 3, seat3[i + 2]);

            printf("Enter seat number corresponding to which the seat is supposed to be cancelled (0 to go back) : ");
            int cancel3;
            scanf("%d", &cancel3);
            while (cancel3 != 0)
            {
                if (strcmp(seat3[cancel3 - 1], "Empty"))
                {
                    strcpy(seat3[cancel3 - 1], "Empty");
                    system("cls");
                    printf("\t\t\t\t\tRupees 1500 have been refunded !!!\n\n\n\n");
                    goto D;
                }
                else
                {
                    system("cls");
                    printf("\t\t\t\t\t\tInvalid seat !!!\n\n\n\n");
                    goto D;
                }
            }

            system("cls");
            cancelflight();
            return;
            break;

        case 4:
            system("cls");
        E:
            printf("\t\t\t\t\t\tPlane No. 4\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat4[i], i + 2, seat4[i + 1], i + 3, seat4[i + 2]);

            printf("Enter seat number corresponding to which the seat is supposed to be cancelled (0 to go back) : ");
            int cancel4;
            scanf("%d", &cancel4);
            while (cancel4 != 0)
            {
                if (strcmp(seat4[cancel4 - 1], "Empty"))
                {
                    strcpy(seat4[cancel4 - 1], "Empty");
                    system("cls");
                    printf("\t\t\t\t\tRupees 1500 have been refunded !!!\n\n\n\n");
                    goto E;
                }
                else
                {
                    system("cls");
                    printf("\t\t\t\t\t\tInvalid seat !!!\n\n\n\n");
                    goto E;
                }
            }

            system("cls");
            cancelflight();
            return;
            break;

        case 5:
            system("cls");
        F:
            printf("\t\t\t\t\t\tPlane No. 5\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat5[i], i + 2, seat5[i + 1], i + 3, seat5[i + 2]);

            printf("Enter seat number corresponding to which the seat is supposed to be cancelled (0 to go back) : ");
            int cancel5;
            scanf("%d", &cancel5);
            while (cancel5 != 0)
            {
                if (strcmp(seat5[cancel5 - 1], "Empty"))
                {
                    strcpy(seat5[cancel5 - 1], "Empty");
                    system("cls");
                    printf("\t\t\t\t\tRupees 1500 have been refunded !!!\n\n\n\n");
                    goto F;
                }
                else
                {
                    system("cls");
                    printf("\t\t\t\t\t\tInvalid seat !!!\n\n\n\n");
                    goto F;
                }
            }

            system("cls");
            cancelflight();
            return;
            break;
        }
    }
}

void status()
{

    printf("\t\t1) Flight nO. 1\n");
    printf("\t\t2) Flight nO. 2\n");
    printf("\t\t3) Flight nO. 3\n");
    printf("\t\t4) Flight nO. 4\n");
    printf("\t\t5) Flight nO. 5\n\n");

    if (hmt == 1)
    {
        for (int i = 0; i < 30; i++)
        {
            strcpy(seat1[i], "Empty");
        }
        for (int i = 0; i < 30; i++)
        {
            strcpy(seat2[i], "Empty");
        }
        for (int i = 0; i < 30; i++)
        {
            strcpy(seat3[i], "Empty");
        }
        for (int i = 0; i < 30; i++)
        {
            strcpy(seat4[i], "Empty");
        }
        for (int i = 0; i < 30; i++)
        {
            strcpy(seat5[i], "Empty");
        }
    }

    hmt = 2;

    printf("Enter plane no to see status (b to go back) : ");
    char planeno[32];
    scanf("%s", &planeno);
    if (!strcmp(planeno, "b"))
    {
        system("cls");
        return options();
    }
    else if ((strcmp(planeno, "1") && strcmp(planeno, "2") && strcmp(planeno, "3") && strcmp(planeno, "4") && strcmp(planeno, "5")))
    {
        system("cls");
        printf("\t\t\t\t\tInvalid Input\n\n");
        return status();
    }

    else
    {

        int Plane;
        if (!strcmp(planeno, "1"))
        {
            Plane = 1;
        }
        else if (!strcmp(planeno, "2"))
        {
            Plane = 2;
        }
        else if (!strcmp(planeno, "3"))
        {
            Plane = 3;
        }
        else if (!strcmp(planeno, "4"))
        {
            Plane = 4;
        }
        else
        {
            Plane = 5;
        }

        switch (Plane)
        {
        case 1:
            system("cls");
            printf("\t\t\t\t\t\tPlane No. 1\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat1[i], i + 2, seat1[i + 1], i + 3, seat1[i + 2]);

            printf("Press b to go back : ");

            char back1[32] = {'h'};
            scanf("%s", &back1);

            while (strcmp(back1, "b"))
            {
                printf("\t\t\t\t\t\tInvalid Input...\n\n");
                printf("Press b to go back : ");
                scanf("%s", &back1);
            }

            system("cls");
            status();
            return;
            break;

        case 2:
            system("cls");
            printf("\t\t\t\t\t\tPlane No. 2\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat2[i], i + 2, seat2[i + 1], i + 3, seat2[i + 2]);

            printf("Press b to go back : ");

            char back2[32] = {'h'};
            scanf("%s", &back2);

            while (strcmp(back2, "b"))
            {
                printf("\t\t\t\t\t\tInvalid Input...\n\n");
                printf("Press b to go back : ");
                scanf("%s", &back2);
            }

            system("cls");
            status();
            return;
            break;

        case 3:
            system("cls");
            printf("\t\t\t\t\t\tPlane No. 3\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat3[i], i + 2, seat3[i + 1], i + 3, seat3[i + 2]);

            printf("Press b to go back : ");

            char back3[32] = {'h'};
            scanf("%s", &back3);

            while (strcmp(back3, "b"))
            {
                printf("\t\t\t\t\t\tInvalid Input...\n\n");
                printf("Press b to go back : ");
                scanf("%s", &back3);
            }

            system("cls");
            status();
            return;
            break;

        case 4:
            system("cls");
            printf("\t\t\t\t\t\tPlane No. 4\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat4[i], i + 2, seat4[i + 1], i + 3, seat4[i + 2]);

            printf("Press b to go back : ");

            char back4[32] = {'h'};
            scanf("%s", &back4);

            while (strcmp(back4, "b"))
            {
                printf("\t\t\t\t\t\tInvalid Input...\n\n");
                printf("Press b to go back : ");
                scanf("%s", &back4);
            }

            system("cls");
            status();
            return;
            break;

        case 5:
            system("cls");
            printf("\t\t\t\t\t\tPlane No. 5\n");
            for (int i = 0; i < 30; i = i + 3)
                printf("%2d) %7s\t\t %2d) %7s\t\t %2d) %7s\t\t \n", i + 1, seat5[i], i + 2, seat5[i + 1], i + 3, seat5[i + 2]);

            printf("Press b to go back : ");

            char back5[32] = {'h'};
            scanf("%s", &back5);

            while (strcmp(back5, "b"))
            {
                printf("\t\t\t\t\t\tInvalid Input...\n\n");
                printf("Press b to go back : ");
                scanf("%s", &back5);
            }

            system("cls");
            status();
            return;
            break;
        }
    }
}
