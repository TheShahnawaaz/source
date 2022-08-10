#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
char *clean_initial_spaces(char *str);
char *single_spaced(char *str);
char *lower(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    return str;
}
char *upper(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    return str;
}
char *capitalize(char *str)
{
    str = single_spaced(str);
    str = lower(str);
    str[0] = str[0] - 32;
    return str;
}
int vowel(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            count++;
        i++;
    }
    return count;
}
char *clean_initial_spaces(char *str)
{
    int i = 0;
    while (str[i] == ' ')
        i++;
    return str + i;
}
char *single_spaced(char *str)
{
    str = clean_initial_spaces(str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            int j = i;
            while (str[j] != '\0')
            {
                str[j] = str[j + 1];
                j++;
            }
            i--;
        }
        i++;
    }
    return str;
}
int words(char *str)
{
    str = single_spaced(str);
    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        // cout << str[i];
        if (str[i] == ' ' && ((str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'A' && str[i + 1] <= 'Z')))
            count++;
        i++;
    }
    return count + 1;
}
int validate(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}
char *reverse(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}
void find_duplicates(char *str)
{
    char A[100];
    strcpy(A, str);
    long int H = 0, x = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 'a');
        if (x & H)
        {
            printf("%c", A[i]);
        }
        else
        {
            H = H | x;
        }
    }
}
int anagram(char *str1, char *str2)
{
    str1 = single_spaced(str1);
    str2 = single_spaced(str2);
    str1 = lower(str1);
    str2 = lower(str2);
    if (strlen(str1) != strlen(str2))
        return 0;
    int H[26] = {0};
    int i = 0;
    while (str1[i] != '\0')
    {
        H[str1[i] - 'a']++;
        i++;
    }
    i = 0;
    while (str2[i] != '\0')
    {
        H[str2[i] - 'a']--;
        i++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (H[i] != 0)
            return 0;
    }
    return 1;
}
void permutation(char s[], int k)
{
    static int A[5] = {0};
    static char B[5] = {0};
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (A[i] == 0)
        {
            A[i] = 1;
            B[k] = s[i];
            if (k == strlen(s) - 1)
            {
                printf("%s\n", B);
            }
            else
            {
                permutation(s, k + 1);
            }
            A[i] = 0;
        }
    }
}
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void permutation2(char s[], int l, int r)
{
    if (l == r)
    {
        printf("%s\n", s);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            permutation2(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    // char *str = new char[5];
    // cout << "Enter a string: ";
    // gets(str);
    // cout << str << endl;
    // permutation(str, 0);
    // str = lower(str);
    // cout << "Lowercase: " << str << endl;
    // str = upper(str);
    // cout << "Uppercase: " << str << endl;
    // str = capitalize(str);
    // cout << "Capitalized: " << str << endl;
    // cout << "Number of vowels: " << vowel(str) << endl;
    // cout << "Number of words: " << words(str) << endl;
    // cout << "Cleaned spaces: " << clean_initial_spaces(str) << endl;
    // cout << "Single spaced: " << single_spaced(str) << endl;
    return 0;
}