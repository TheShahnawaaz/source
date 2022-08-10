#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // submatrix with largest trace
    //  your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int max = 0;
        int sum = 0;

        for (int i = 0; i < 2 * n - 1; i++)
        {
            sum=0;
            if (i < n)
            {
                for (int j = 0; i + j < n && j < n - 1; j++)
                {
                    sum += a[i + j][j];
                }
            }
            else
            {
                int k = i-n;
                for (int j = 0; k + j < n && j < n - 1; j++)
                {
                    sum += a[n-k-j][n-j];
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
