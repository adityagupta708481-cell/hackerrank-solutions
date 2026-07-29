// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/three-month-preparation-kit-array-left-rotation/problem?isFullScreen=true
// Problem     Left Rotation
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-07-29, 12:24 p.m.
// Technique   triple-reverse-array-rotation
// Time        O(n)
// Space       O(1)
// Insight     The algorithm performs a left rotation by reversing the entire array, then reversing the two segments created by the split point at n-d to restore their original relative order.
// Interview   Before: "I could create a new array and copy elements using modulo arithmetic." After: "I used a triple-reverse approach to achieve O(n) time and O(1) auxiliary space, which handles the rotation efficiently even when d is greater than the array size n."
// Pitfalls    (1) Failing to account for d > n by not using modulo arithmetic if d were not guaranteed to be within bounds.  (2) Incorrectly calculating the split index n as arr.size() - d, which assumes d is always less than or equal to the array size.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'rotateLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

vector<int> rotateLeft(int d, vector<int> arr) {
    int n=arr.size()-d;
    reverse(arr.begin(),arr.end());
    reverse(arr.begin()+n,arr.end());
    reverse(arr.begin(),arr.begin()+n);
    return arr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = rotateLeft(d, arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
