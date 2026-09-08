// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/priyanka-and-toys/problem?isFullScreen=true
// Problem     Priyanka and Toys
// Difficulty  Easy
// Subdomain   Greedy
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-09-08, 04:36 p.m.
// Technique   sorting-and-greedy-linear-scan
// Time        O(N log N)
// Space       O(1)
// Insight     The algorithm sorts the weights and greedily groups all items within a four-unit range of the current minimum weight into a single container.
// Interview   Before: "I would use a hash map to count frequencies." After: "Sorting is more efficient here, allowing an O(N log N) greedy approach to group items by the weight constraint, which is optimal for this problem."
// Pitfalls    (1) The code contains a redundant increment in the return statement (cnt++) which does not affect the final result but is logically incorrect.  (2) Failing to sort the input array prevents the greedy strategy from correctly identifying the minimum weight item for each container.  (3) Assuming the container limit is a fixed count rather than a relative range based on the minimum weight item.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'toys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY w as parameter.
 */

int toys(vector<int> w) {
    sort(w.begin(),w.end());
    int cnt=0;
    int i=0;
    while(i<w.size()){
        cnt++;
        int limit=w[i]+4;
        while(i<w.size() && w[i]<=limit)i++;
    }
    return cnt++;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string w_temp_temp;
    getline(cin, w_temp_temp);

    vector<string> w_temp = split(rtrim(w_temp_temp));

    vector<int> w(n);

    for (int i = 0; i < n; i++) {
        int w_item = stoi(w_temp[i]);

        w[i] = w_item;
    }

    int result = toys(w);

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
