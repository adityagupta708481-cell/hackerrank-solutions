// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true
// Problem     Diagonal Difference
// Difficulty  Easy
// Subdomain   Warmup
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-08-01, 07:36 p.m.
// Technique   single-pass-diagonal-summation
// Time        O(n)
// Space       O(1)
// Insight     The algorithm iterates through the matrix rows once, simultaneously accumulating the primary diagonal element at index [m][m] and the secondary diagonal element at index [m][n-m].
// Interview   Before: "How would you calculate the diagonal difference?" After: "I iterate through the matrix once, using the row index to access both diagonals in O(n) time. By calculating the primary diagonal [m][m] and secondary diagonal [m][n-m] simultaneously, I avoid redundant traversals while maintaining O(1) auxiliary space."
// Pitfalls    (1) Incorrectly calculating the secondary diagonal index as [m][m+1] instead of [m][n-m] leads to an out-of-bounds access or incorrect summation.  (2) Failing to use the absolute value function abs() on the final difference violates the problem requirement for the absolute difference.  (3) Initializing the secondary diagonal index using the matrix size instead of size-1 causes an index-out-of-bounds error on the first iteration.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr) {
    int n=arr.size()-1;
    int m=0;
    int left=0,right=0;
    while(m<arr.size()){
        left+=arr[m][m];
        right+=arr[m][n-m];
        m++;
    }
    return abs(left-right);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
