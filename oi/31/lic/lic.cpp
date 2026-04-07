/*
 * Task: Liczniki (LIC)
 * Competition: XXXI Olimpiada Informatyczna, Etap II
 * Score: 100/100 (Verified on Szkopuł) Problem Link: https://szkopul.edu.pl/problemset/problem/9Xg3SiF9DZ-Xn65OWbu9B42J/site/
 * Technique: Greedy Approach + Binary Search (multiset::lower_bound)
 */


#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n; // how long each row is
    long long m; // how many rows
    cin >> n;
    cin >> m;
    vector<pair<long long, long long>> cost_water(n);
    long long a; // variable used for inputs
    for(long long i = 0; i < n; i++)
    {
        cin >> a;
        cost_water[i] = {a, 0};
    }
    for(long long i = 0; i < n; i++)
    {
        cin >> a;
        cost_water[i] = {cost_water[i].first, a};
    }   
    long long result = 0;
    for(long long i = 0; i < n; i++)
    {
        result -= cost_water[i].first * cost_water[i].second;
    }

    sort(cost_water.begin(), cost_water.end(), greater<pair<long long, long long>>());

    for(long long i = 0; i < m; i++)
    {
        multiset<long long> row; // for each row we use multiset to use lowerbound
        for(long long j = 0; j < n; j++)
        {
            cin >> a;
            row.insert(a);
        }
        for(long long j = 0; j < n; j++)
        {
            // greed approach, for the most expensive water counter we are taking the lowers possible water usage
            auto z = row.lower_bound(cost_water[j].second);
            if(z != row.end())
            {
                cost_water[j].second = *z; 
                row.erase(z);
            }
            else
            {
                cout<<"NIE";  // its impossible
                return 0;
            }
        }
    }        
    for(long long i = 0; i < n; i++)
    {
        result += cost_water[i].first * cost_water[i].second;
    }
    cout<<result<<endl;
    return 0;
}
