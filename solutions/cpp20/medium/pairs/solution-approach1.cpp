// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/pairs/problem?isFullScreen=true
// Problem     Pairs
// Difficulty  Medium
// Subdomain   Search
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-08-19, 11:56 a.m.
// Technique   hash-set-lookup
// Time        O(n)
// Space       O(n)
// Insight     The algorithm iterates through each unique element in the set and checks for the existence of its complement, defined as the element plus the target difference k, in constant time.
// Interview   Before: "I would sort the array and use two pointers to find pairs with difference k." After: "Using an unordered_set allows for O(n) time complexity by performing O(1) lookups for each element's complement, which is more efficient than sorting for this problem."
// Pitfalls    (1) The implementation assumes all input integers are unique as per the problem constraints, which simplifies the logic by avoiding duplicate pair counting.  (2) The code does not explicitly handle negative values for k, though the problem implies k is a target difference.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int pairs(int k, vector<int> arr) {
    unordered_set<int>info(arr.begin(),arr.end());
    int count=0;
    for(auto i:info){
        if(info.find(i+k)!=info.end())count++;
    }
    return count;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

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
