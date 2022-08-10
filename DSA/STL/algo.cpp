#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<pair<string, int>> v;
    v.push_back(make_pair("broo", 15));
    v.push_back(make_pair("shah", 92));
    v.push_back(make_pair("andh", 35));
    v.push_back(make_pair("ddfgh", 34));
    v.push_back(make_pair("egfd", 55));
    v.push_back(make_pair("sdf", 62));
    sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b)
         { return a.second < b.second; });
    // sort(v.begin(),v.end());
    for (auto i : v)
    {
        cout << i.first << " " << i.second << endl;
    }

    // int n;
    // cin >> n;
    // string s;
    // getline(cin, s);
    // getline(cin, s);
    // cout << s << endl;
    // string b = s.substr(0, s.find(' '));
    // cout << s << endl;
    // cout << b << endl;

    // Using all the functions of algorithm library
    // sort(A, A + n);
    // reverse(A, A + n);
    // stable_sort(A, A + n);
    // partial_sort(A, A + n, A + n);
    // partial_sort_copy(A, A + n, A, A + n);
    // nth_element(A, A + n, A + n);
    // binary_search(A, A + n, n);
    // lower_bound(A, A + n, n);
    // upper_bound(A, A + n, n);
    // equal_range(A, A + n, n);
    // min_element(A, A + n);
    // max_element(A, A + n);
    // next_permutation(A, A + n);
    // prev_permutation(A, A + n);
    // random_shuffle(A, A + n);
    // random_device rd;
    // mt19937 mt(rd());
    // shuffle(A, A + n, mt);
    // generate(A, A + n, mt);
    // generate_n(A, n, mt);
    // generate_n(A, n, mt);
    // generate_n(A, n, mt);
    // generate_n(A, n, mt);
    // generate_n(A, n, mt);

    // generate_n(A, n, mt);
    // generate_n(A, n, mt);

    return 0;
}