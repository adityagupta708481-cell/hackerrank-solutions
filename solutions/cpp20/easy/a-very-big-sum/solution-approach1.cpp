// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true
// Problem     A Very Big Sum
// Difficulty  Easy
// Subdomain   Warmup
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-07-30, 02:54 a.m.
// Technique   linear-accumulation-long-integer
// Time        O(n)
// Space       O(n)
// Insight     The implementation iterates through the input vector once, accumulating the sum into a 64-bit long variable to prevent overflow.
// Interview   Before: "I will use a standard integer to sum the array." After: "I used a long type to accommodate values up to 10^10, ensuring the O(n) summation does not overflow the 32-bit integer limit specified in the constraints."
// Pitfalls    (1) Using a 32-bit int instead of a long type will cause integer overflow when the sum exceeds 2,147,483,647.  (2) Failing to account for the input constraints where individual elements can reach 10^10 requires a 64-bit integer type for the accumulator.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'aVeryBigSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY ar as parameter.
 */

long aVeryBigSum(vector<long> ar) {
    long ans=0;
    for(auto i:ar){
        ans+=i;
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ar_count_temp;
    getline(cin, ar_count_temp);

    int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<long> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        long ar_item = stol(ar_temp[i]);

        ar[i] = ar_item;
    }

    long result = aVeryBigSum(ar);

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
