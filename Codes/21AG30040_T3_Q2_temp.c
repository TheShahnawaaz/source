#include <stdio.h>
#include <string.h>
struct password
{
  int Length;
  int Uppercase;
  int Lowercase;
  int Number;
  int Special;
  int Size;
  int Strength;
  char Content[50];
};

void main()
{
  int n;
  printf("Enter how many password you want to input: ");
  scanf("%d", &n);
  struct password p[n];
  int i;
  for (i = 0; i < n; i++)
  {
    printf("Enter password %d: ", i + 1);
    scanf("%s", p[i].Content);
    p[i].Length = strlen(p[i].Content);
    p[i].Uppercase = 0;
    p[i].Lowercase = 0;
    p[i].Number = 0;
    p[i].Special = 0;
    p[i].Size = 0;
    p[i].Strength = 0;

    int j;
    for (j = 0; j < p[i].Length; j++)
    {
      if (p[i].Content[j] >= 'A' && p[i].Content[j] <= 'Z')
      {
        p[i].Uppercase++;
      }
      else if (p[i].Content[j] >= 'a' && p[i].Content[j] <= 'z')
      {
        p[i].Lowercase++;
      }
      else if (p[i].Content[j] >= '0' && p[i].Content[j] <= '9')
      {
        p[i].Number++;
      }
      else
      {
        p[i].Special++;
      }
      p[i].Size += sizeof(p[i].Content[j]);
    }

    /*
    a password ‘XVBghy7J’ has a strength of 4 (number of
    characters from ‘X’ till ‘g’), ‘ghfVbn@’ has a strength of 2 (starting from ‘V’ and ending at
    ‘b’). In case a password has no next lowercase characters after the first uppercase character,
    then strength is 1 (for example ‘ghjtJLI’ or ‘fb$76bhK’) and in case the password has no
    uppercase character at all, the strength is zero (for example, ‘fft67%uj’)
    */
    int lower_found = 0;

    if (p[i].Uppercase > 0)
    {
      int k;
      for (k = 0; k < p[i].Length; k++)
      {
        if (p[i].Content[k] >= 'A' && p[i].Content[k] <= 'Z')
        {
          if (p[i].Content[k + 1] >= 'a' && p[i].Content[k + 1] <= 'z')
          {
            p[i].Strength++;
            p[i].Strength++;
            lower_found = 1;
            break;
          }
          else
          {
            p[i].Strength++;
          }
        }
      }
    }
    else if (lower_found == 0)
    {
      p[i].Strength = 1;
    }
    else
    {
      p[i].Strength = 0;
    }
  }

  /*

  INPUT:
  Enter the number of password: 3
  Enter the paswords:
  XVBghy7J
  ghjtJLI
  fft67%uj

  OUTPUT:
  XVBghy7J: length=8, no. of upper case=4, no. of lower case =3, no .of digits=1, no. of special charecters=0, size=8, strength=4
  ghjtJLI: length=7, no. of upper case=3, no. of lower case=4, no .of digits=0, no. of special charecters=0, size=7, strength=1
  fft67%uj: length=8, no. of upper case=0, no. of lower case=5, no .of digits=2, no. of special charecters=1, size=8, strength=0
  Similarity index between 1-2: 14.28%
  Similarity index between 2-3: 0%
  Similarity index between 1-3: 28.57%

  */

  int k;
  for (k = 0; k < n; k++)
  {
    printf("%s: length=%d, no. of upper case=%d, no. of lower case=%d, no .of digits=%d, no. of special charecters=%d, size=%d, strength=%d\n", p[k].Content, p[k].Length, p[k].Uppercase, p[k].Lowercase, p[k].Number, p[k].Special, p[k].Size, p[k].Strength);
  }

  int j;
  for (j = 0; j < n; j++)
  {
    int l;
    for (l = j + 1; l < n; l++)
    {
      int similarity = 0;
      int i;

      if (p[j].Length == p[l].Length)
      {
        similarity++;
      }
      if (p[j].Uppercase == p[l].Uppercase)
      {
        similarity++;
      }
      if (p[j].Lowercase == p[l].Lowercase)
      {
        similarity++;
      }
      if (p[j].Number == p[l].Number)
      {
        similarity++;
      }
      if (p[j].Size == p[l].Size)
      {
        similarity++;
      }
      if (p[j].Special == p[l].Special)
      {
        similarity++;
      }
      if (p[j].Strength == p[l].Strength)
      {
        similarity++;
      }
      float similarity_index = (similarity);
      printf("Similarity index between %d-%d: %.2f%%\n", j + 1, l + 1, similarity_index * 100 / 7);
    }
  }
}