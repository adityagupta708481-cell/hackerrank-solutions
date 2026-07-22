// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/three-month-preparation-kit-pylons/problem?isFullScreen=true
// Problem     Goodland Electricity
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-07-22, 11:56 a.m.
// ──────────────────────────────────────────────────

#include<bits/stdc++.h>
using namespace std;
int pylons(vector<int>city,int k){
    int n=city.size();
    int count=0,i=0;
    while(i<n){
        int r=min(i+k-1,n-1);
        while(r>=0 && city[r]==0){
            r--;
        }
        if(r<(i-k+1))return -1;
        count++;
        i=r+k;
    }
    return count;
}
int main(){
    int x,k;
    cin>>x>>k;
    vector<int>city(x);
    for(int i=0;i<x;i++){
        cin>>city[i];
    }
    cout<<pylons(city,k);
}
