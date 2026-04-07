#include<bits/stdc++.h>
using namespace std;
/*
 * Task: Wagony (wag)
 * Competition: XXX Olimpiada Informatyczna, Etap II
 * Score: 100/100 (Verified on Szkopuł) Problem Link: https://szkopul.edu.pl/problemset/problem/UtJx9fM6UT2oxXFenSPjiz5C/site/
 * Technique: dynamic programic + divide and conquer
 * time complexity: O(dlogn)
 */ 
int a;
int b;
unsigned long long maxx(long long c, long long d)
{
    if(c > d) return c;
    return d;
}
unsigned long long cost_function(unsigned long long w1, unsigned long long w2) // function from tast content that calculates cost of merging two carriages
{
    return (w1*a + w2 * b)%1001;
}
unsigned long long F(unsigned long long n, int d, unordered_map<unsigned long long, unsigned long long> &result) // recursion spliting data in half +- d/2
{
    if(n == 1) return 0;

    unsigned long long j = 0;  // j represent right half
    for(unsigned long long i = maxx( (n/2 - d), 1); i <= n/2 + d; i++) //i represent left half
    {
        j = 0;
        if(n > i) j = n - i;

        if( ((i >= j) && i - j > d) || (j > i) && j - i > d) continue;

        if(j > 0)
        {
            if(result.find(i) == result.end()) result[i] = F(i, d, result);
            if(result.find(j) == result.end()) result[j] = F(j, d, result);

            if(result.find(n) == result.end()) result[n] = result[i] + result[j] + cost_function(i, j);
            else result[n] = min(result[n], result[i] + result[j] + cost_function(i, j));
        }
    }
    return result[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned long long n;
    int d;
    cin >> n;
    cin >> d;
    cin >> a;
    cin >> b;
    unordered_map<unsigned long long, unsigned long long> result;
    cout<<F(n, d, result)<<endl;
    
    return 0;
}