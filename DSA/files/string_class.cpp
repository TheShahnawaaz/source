#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
class String
{
private:
    char *str;
    int length;
    void swap(char &a, char &b);

public:
    String()
    {

        str = NULL;
        length = 0;
    }
    String(char s[20])
    {
        str = s;
        length = strlen(s);
    }
    ~String()
    {
        delete[] str;
    }
    char *clean_initial_spaces(char *str);
    char *single_spaced(char *str);
    String lower();
    String upper();
    String capitalize();
    int vowel();
    String clean_initial_spaces();
    String single_spaced();
    int words();
    int validate();
    String reverse();
    void find_duplicates();
    void permutation(int k);
    void permutation2(int l, int r);
    void print();
};
void String::print()
{
    for (int i = 0; i < length; i++)
        cout << str[i];
    cout << endl;
}
String String::lower()
{
    String s;
    s.str = str;
    int i = 0;
    while (s.str[i] != '\0')
    {
        if (s.str[i] >= 'A' && s.str[i] <= 'Z')
            s.str[i] = s.str[i] + 32;
        i++;
    }
    return s;
}
String String::upper()
{
    String s;
    s.str = str;
    int i = 0;
    while (s.str[i] != '\0')
    {
        if (s.str[i] >= 'a' && s.str[i] <= 'z')
            s.str[i] = s.str[i] - 32;
        i++;
    }
    return s;
}
String String::capitalize()
{
    String s;
    s = single_spaced();
    s.lower();
    s.str[0] = s.str[0] - 32;
    return s;
}
int String::vowel()
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
String String::clean_initial_spaces()
{
    String s;
    int i = 0;
    while (str[i] == ' ')
        i++;
    s.str = str + i;
    str=s.str;
    return s;
}
String String::single_spaced()
{
    String s;
    s = clean_initial_spaces();
    int i = 0;
    while (s.str[i] != '\0')
    {
        if (s.str[i] == ' ' && s.str[i + 1] == ' ')
        {
            int j = i;
            while (s.str[j] != '\0')
            {
                s.str[j] = s.str[j + 1];
                j++;
            }
            i--;
        }
        i++;
    }
    return s;
}
int String::words()
{
    String s;
    s = single_spaced();
    int i = 0;
    int count = 0;
    while (s.str[i] != '\0')
    {
        if (s.str[i] == ' ')
            count++;
        i++;
    }
    return count + 1;
}
int String::validate()
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
String String::reverse()
{
    String s;
    s.str = str;
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j)
    {
        s.swap(s.str[i], s.str[j]);
        i++;
        j--;
    }
    return s;
}
void String::find_duplicates()
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
// int String::anagram( char *str2)
// {
//     str1 = single_spaced(str1);
//     str2 = single_spaced(str2);
//     str1 = lower(str1);
//     str2 = lower(str2);
//     if (strlen(str1) != strlen(str2))
//         return 0;
//     int H[26] = {0};
//     int i = 0;
//     while (str1[i] != '\0')
//     {
//         H[str1[i] - 'a']++;
//         i++;
//     }
//     i = 0;
//     while (str2[i] != '\0')
//     {
//         H[str2[i] - 'a']--;
//         i++;
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         if (H[i] != 0)
//             return 0;
//     }
//     return 1;
// }
void String::permutation(int k)
{
    static int A[20] = {0};
    static char B[20] = {0};
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (A[i] == 0)
        {
            A[i] = 1;
            B[k] = str[i];
            if (k == strlen(str) - 1)
            {
                printf("%s\n", B);
            }
            else
            {
                permutation(k + 1);
            }
            A[i] = 0;
        }
    }
}
void String::swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

// void String::permutation2(int l, int r)
// {
//     String s;
//     s.str = str;
//     if (l == r)
//     {
//         printf("%s\n", s.str);
//     }
//     else
//     {
//         for (int i = l; i <= r; i++)
//         {
//             swap(s.str[l], s.str[i]);
//             s.permutation2(l + 1, r);
//             swap(s.str[l], s.str[i]);
//         }
//     }
// }

int main()
{
    char sttttt[40] = "Hello World";
    char stttt2[40] = "ABCD";
    String s(sttttt);

    // s.print();
    // s.print();
    String a(stttt2);
    // a.lower();

    // a.print();
    // a.upper();
    // a.print();
    // a.capitalize();
    // a.print();
    // cout << a.vowel() << endl;
    // a.print();
    a.clean_initial_spaces();
    a.print();
    a.single_spaced();
    a.print();
    cout << a.words() << endl;
    a.print();
    cout << a.validate() << endl;
    // a.print();
    a.reverse();
    a.print();
    a.find_duplicates();
    // a.print();

    // a.anagram(sttttt);
    // a.print();
    a.permutation(0);
    // a.print();
    a.permutation2(0, strlen(sttttt) - 1);
    // a.print();
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