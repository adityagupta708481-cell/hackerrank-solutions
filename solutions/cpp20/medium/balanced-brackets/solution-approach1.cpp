// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/balanced-brackets/problem?isFullScreen=true
// Problem     Balanced Brackets
// Difficulty  Medium
// Subdomain   Stacks
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-07-29, 12:17 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    stack<char> info;
    for (auto a : s) {
        if (a == '(' || a == '[' || a == '{')info.push(a);
        else {
            if (info.empty())return "NO";
            char top = info.top();
            if ((a == ')' && top == '(')||(a == ']' && top == '[')||(a == '}' && top == '{'))info.pop();
            else return "NO";
        }
    }
    if(info.empty())return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

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
