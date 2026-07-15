// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true
// Problem     Solve Me First
// Difficulty  Easy
// Subdomain   Warmup
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-07-15, 10:33 p.m.
// Technique   basic-arithmetic-sum
// Time        O(1)
// Space       O(1)
// Trick       The solution uses the standard addition operator + to compute the sum of two integers passed to the solveMeFirst function.
// Hint        cin ignores whitespace, which simplifies reading input values.
// ──────────────────────────────────────────────────

#include<bits/stdc++.h>
using namespace std;

int solveMeFirst(int a, int b) {
    return a+b;
  
}

int main() {
    int num1, num2;
    int sum;
    cin>>num1>>num2;
    sum = solveMeFirst(num1,num2);
    cout<<sum;
    return 0;
}
