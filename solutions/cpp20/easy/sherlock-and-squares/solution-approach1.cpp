// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true
// Problem     Sherlock and Squares
// Difficulty  Easy
// Subdomain   Implementation
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-09-23, 12:37 p.m.
// Technique   mathematical-range-boundary-calculation
// Time        O(1)
// Space       O(1)
// Insight     The number of perfect squares in an inclusive range [a, b] is determined by the count of integers whose squares fall within the interval, calculated as the difference between the floor of the square root of b and the ceiling of the square root of a, plus one.
// Interview   Before: "I would iterate from a to b and check if each number is a perfect square." After: "That would be O(b-a), which is inefficient. Instead, I calculate the range of roots [ceil(sqrt(a)), floor(sqrt(b))] in O(1) time, which handles the constraints effectively."
// Pitfalls    (1) Failing to handle cases where the calculated range is invalid, resulting in a negative count when m > n.  (2) Using integer division or truncation incorrectly when calculating the ceiling of the square root of a.  (3) Assuming the range [a, b] always contains at least one square integer.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'squares' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 */

int squares(int a, int b) {
    int m=ceil(sqrt(a));
    int n=floor(sqrt(b));
    return n-m+1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int a = stoi(first_multiple_input[0]);

        int b = stoi(first_multiple_input[1]);

        int result = squares(a, b);

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
