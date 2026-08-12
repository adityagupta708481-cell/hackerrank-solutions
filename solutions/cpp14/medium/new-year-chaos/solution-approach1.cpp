// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/new-year-chaos/problem?isFullScreen=true
// Problem     New Year Chaos
// Difficulty  Medium
// Subdomain   Constructive Algorithms
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-08-12, 11:50 a.m.
// Technique   reverse-bribe-counting
// Time        O(n)
// Space       O(1)
// Insight     The algorithm validates the chaotic condition by checking if any person moved more than two positions forward and counts total bribes by identifying how many people originally behind the current person are now in front.
// Interview   Before: "I would simulate the swaps directly." After: "Instead, I iterate through the queue and check if each person's current position minus their original position exceeds two. If not, I count how many people originally behind them are now ahead, resulting in an O(n) time complexity solution."
// Pitfalls    (1) Failing to check the chaotic condition q[i] - (i + 1) > 2 before counting bribes.  (2) Incorrectly setting the inner loop range, which must start from max(0, q[i] - 2) to only count relevant preceding elements.  (3) Assuming the queue is 0-indexed when calculating the original position, which is actually (i + 1).
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

void minimumBribes(vector<int> q) {
    int count = 0;
    for (int i = 0; i < q.size(); i++) {
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(0, q[i] - 2); j < i; j++) {
            if (q[j] > q[i]) {
                count++;
            }
        }
    } 
    cout << count << endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
