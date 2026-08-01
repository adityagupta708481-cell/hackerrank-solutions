// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// Problem     Plus Minus
// Difficulty  Easy
// Subdomain   Warmup
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-08-01, 07:43 p.m.
// Technique   linear-scan-counter
// Time        O(n)
// Space       O(n)
// Insight     The algorithm iterates through the array once to maintain three separate counters for positive, negative, and zero values, then calculates their respective ratios relative to the total array size.
// Interview   Before: "How would you calculate the proportions of different integer types in an array?" After: "I would perform a single O(n) linear scan to count occurrences of positive, negative, and zero values, then divide each by the total size n to achieve the required O(n) time and O(n) space complexity."
// Pitfalls    (1) Failing to use floating-point division, which results in integer truncation and incorrect ratios.  (2) Assuming the input array size n is always greater than zero without considering potential division by zero.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    int n=arr.size();
    float pos=0,neg=0,zero=0;
    for(auto i:arr){
        if(i>0)pos++;
        else if(i==0)zero++;
        else if(i<0)neg++;
    }
    cout<<float(pos/n)<<endl;
    cout<<float(neg/n)<<endl;
    cout<<float(zero/n)<<endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

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
