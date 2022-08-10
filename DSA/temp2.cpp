#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        string s1;
        string s2;
        cin >> s1;
        cin >> s2;

        int i = 0;
        while (s1[i] != s2[0] && i < m)
        {
            i++;
        }
        if (i == m)
        {
            cout << "NO" << endl;
            continue;
        }
        i++;
        while (s1[i] != s2[1] && i < m)
        {
            i++;
        }
        if (i == m)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            if (s1.at(s2[0]))
            {
                cout << "Yes " << s1.at(s2[2]) << endl;
                continue;
            }
        }
    }
}
