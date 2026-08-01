// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true
// Problem     Staircase
// Difficulty  Easy
// Subdomain   Warmup
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-08-01, 07:53 p.m.
// Technique   nested-loop-string-construction
// Time        O(n^2)
// Space       O(1)
// Insight     The algorithm iterates through each row from 1 to n, printing n-i spaces followed by i hash symbols to maintain right-alignment.
// Interview   Before: "How would you print a right-aligned staircase of size n?" After: "I use nested loops to print n-i spaces and i hashes per row, resulting in O(n^2) time complexity, which is optimal for printing n lines of length n."
// Pitfalls    (1) Incorrectly calculating the number of spaces as n-i+1 instead of n-i, which violates the right-alignment requirement.  (2) Using an incorrect loop range for the hash symbols, such as starting from 1 instead of 0, which would print an extra character per line.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    for(int i=1;i<n+1;i++){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        for(int k=0;k<i;k++){
            cout<<"#";
        }
        cout<<endl;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    staircase(n);

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
