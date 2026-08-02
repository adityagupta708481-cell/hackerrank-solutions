// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// Problem     Mini-Max Sum
// Difficulty  Easy
// Subdomain   Warmup
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-08-02, 01:36 p.m.
// Technique   total-sum-minus-extremes
// Time        O(n)
// Space       O(1)
// Insight     The algorithm calculates the total sum of all elements and subtracts the maximum element to find the minimum sum, and subtracts the minimum element to find the maximum sum.
// Interview   Before: "I should sort the array and sum the first four and last four elements." After: "Sorting takes O(n log n), but we can achieve O(n) time by calculating the total sum and subtracting the min and max values, which handles the 64-bit integer requirement efficiently."
// Pitfalls    (1) Failing to use a 64-bit integer for the sum, which causes overflow since the sum of five large integers can exceed the 32-bit signed integer limit.  (2) Initializing the minimum and maximum variables with values that are not within the range of the input integers, leading to incorrect results.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    long long mini=INT_MAX,maxi=INT_MIN,total=0;
    for(auto i:arr){
        total+=i;
        mini=min((long long)i,mini);
        maxi=max((long long)i,maxi);
    }
    cout<<total-maxi<<" "<<total-mini;
}

int main()
{

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

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
