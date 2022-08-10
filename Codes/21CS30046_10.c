/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Assignment no : 10
*/
// Adding library to the library
#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct user // Defining the structure for Name.
{
    char username[100];
    char password[100];
} user;
int Hamming_distance(char s1[100], char s2[100]) // Hamming distance
{
    int count = 0;
    int n = (strlen(s1) >= strlen(s2)) ? strlen(s1) : strlen(s2);
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            count++;
        }
    }
    return count;
}
int match(user *data, int index, char username[100]) // Function for matching the username
{
    int status = -1;
    for (int i = 0; i < index; i++)
    {
        int temp = Hamming_distance(data[i].username, username);
        if (temp == 0)
        {
            status = i;
        }
    }
    return status;
}
void add_user(user *database, int *i) // Function for adding new user
{
    char temp[100];
    printf("Enter the username of user %d: ", *i + 1);
    scanf("%s", temp);
    if (match(database, *i, temp) >= 0)
    {
        printf("This username is already taken.\n");
        return;
    }
    strcpy(database[*i].username, temp);
    printf("Enter the password of user %d: ", *i + 1);
    scanf("%s", temp);
    strcpy(database[*i].password, temp);
    *i = *i + 1;
}
int c1_check(char password[100]) // Function for checking condition 1.
{
    for (int i = 0; i < strlen(password); i++) // Checking it later
    {
        if (password[i] == 'a' || password[i] == 'A')
        {
            return i;
        }
        if (password[i] == 'e' || password[i] == 'E')
        {
            return i;
        }
        if (password[i] == 'i' || password[i] == 'I')
        {
            return i;
        }
        if (password[i] == 'o' || password[i] == 'O')
        {
            return i;
        }
        if (password[i] == 'U' || password[i] == 'u')
        {
            return i;
        }
    }
    return -1;
}
int main()

{
    int n; // taking input from user
    printf("Enter positive integer: ");
    scanf("%d", &n);
    user database[n];
    for (int i = 0; i < n;)
    {
        add_user(database, &i);
    }
    int login = 3;
    do
    {
        printf("Enter your username to login: ");
        char temp[100];
        scanf("%s", temp);

        printf("Enter your password to login: ");
        char temp1[100];
        scanf("%s", temp1);

        if (match(database, n, temp) == -1)
        {
            printf("This username is not registered!\n");
            printf("Do you want to register NEW USER?\n1->YES\n0->NO\nEnter your choice: ");
            int c;
            scanf("%d", &c);

            if (c == 1)
            {
                int a = n;
                do
                {
                    add_user(database, &n);
                } while (a == n);
            }
            else
            {
                continue;
            }
        }
        else
        {
            int user_index = match(database, n, temp);
            if (Hamming_distance(database[user_index].password, temp1) == 0)
            {
                printf("Great,Login was successful");
                login = 0;
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    printf("Your password does not match, Please enter a new password: ");
                    scanf("%s", temp1);
                    if (c1_check(temp1) >= 0 && Hamming_distance(database[user_index].password, temp1) <= (strlen(temp1) + strlen(database[user_index].password)) / 3)
                    {
                        strcpy(database[user_index].password, temp1);
                        printf("Thank you, your password has been reset.");
                        login = 0;
                        break;
                    }
                    else
                    {
                        printf("Condition for new password is not satisfied.\nPlease try again.\n");
                        continue;
                    }
                }
            }
        }
        login--;

    } while (login >= 0);
    return 0;
}