#include <iostream>

using namespace std;
void fun(int a[4][4],int n)
{
    int max = 0;
    int sum = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        sum = 0;
        if (i < n)
        {
            for (int j = 0; i + j < n && j < n; j++)
            {
                sum += a[i + j][j];
            }
        }
        else
        {
            int k = i - n;
            for (int j = 0; k + j < n && j < n; j++)
            {
                sum += a[n - k - j - 1][n - j - 1];
            }
        }
        // cout<<sum<<endl;
        if (sum > max)
        {
            max = sum;
        }
    }
    cout << max << endl;
}
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
        // cout << n << endl;
        int a[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        fun(a,n);
    }
    return 0;
}
