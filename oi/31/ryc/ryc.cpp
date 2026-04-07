 /*
 * Zadanie: Rycerze (Knights)
 * Zawody: XXXI Olimpiada Informatyczna, Etap II
  * Score: 100/100 (Verified on Szkopuł) https://szkopul.edu.pl/problemset/problem/ryc/site/
 * Technika: Bitmask DP + BFS + Meet-in-the-middle
 * Complexity: O(K * (N * 2^K + M * 2^K)) where K is the number of swords
 * * Opis algorytmu:
 * 1. Process swords one by one (greedily, starting from the highest weight).
 * 2. For each sword, build a state graph (vertex, mask of collected swords).
 * 3. Perform BFS from both ends: start (1) and end (n).
 * 4. Find an edge that connects both halves within time <= d,
 * summing the masks of collected swords to ensure all required ones are covered.
 */

#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int a;
    int b;
    int w;
    int i;
};
struct vertex
{
    int w;
    int key;
};
// Operator for sorting edges by weight (descending) because we want to take the best sword (with the biggest number)
bool operator<(edge a, edge b)
{
    return a.w > b.w;
}

/*
 * BFS to find the shortest paths in the state graph.
 * O[v][mask] stores the minimum steps to reach vertex v with the set of swords 'mask'.
 */
void BFS(int start, vector<vector<int>> &O, int d, int z, vector<vector<int>> &G, vector<vector<vector<int>>> &swords, vector<int> &results) //bfs checks if i can collect all of the swords
{
        queue<vertex> k1;
        vector<int> sword_indexes;
        O[start][0] = 0;
        k1.push({start, 0});
        while(k1.empty() == false)
        {
            int w = k1.front().w;
            int key = k1.front().key;
            k1.pop();
            
            for(int i = 0; i < G[w].size(); i++)
            {
                int s = G[w][i];
                sword_indexes.clear();
                for(int j = 0; j < z; j++)
                {
                    if(swords[w][i][j] == results[j] && ( (key & (1 << j)) == 0))
                        sword_indexes.push_back(j);
                }
                for(int j = 0; j < (1 << sword_indexes.size()); j++)
                {
                    int key2 = key;
                    for(int g = 0; g < sword_indexes.size(); g++)
                    {
                        if(j & (1 << g))
                        key2 = key2 | (1 << sword_indexes[g]);
                    }

                    if(O[s][key2] == -1 || O[s][key2] > O[w][key] + 1)
                    {
                        O[s][key2] = O[w][key] + 1;
                        k1.push({s, key2});
                    }
                }
            }
        }
}
                
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int m;
    int d;
    int k;
    cin >> n; // wierzcholki
    cin >> m; // edges
    cin >> d; // czas
    cin >> k; // ilosc mieczy

    vector<vector<int>> G(n + 1);
    vector<vector<vector<int>>> swords(n + 1);
    vector<int> q(k);

    vector<vector<edge>> edges(k);
    vector<vector<int>> edge_index;

    int a;
    int b;
    for(int i = 0; i < m; i++)
    {
        cin >> a;
        cin >> b;
        for(int j = 0; j < k; j++)
        {
            cin >> q[j];
            edges[j].push_back({a, b, q[j], i});
        }
        edge_index.push_back(q);
        G[a].push_back(b);
        G[b].push_back(a);
        swords[a].push_back(q);
        swords[b].push_back(q);
    } // end of data loading

    // Sort edges for each sword to check them greedily
    for(int i = 0; i < k; i++)
    sort(edges[i].begin(), edges[i].end());

    int key = 0;
    vector<int> results(k, 0);
    vector<vector<int>> O(n + 1, vector<int>(1 << k)); //visited - time of visit
    vector<vector<int>> O2(n + 1, vector<int>(1 << k)); //visited - time of visit

    for(int z = 0; z < k; z++) // for each sword we want to grab the best one avaible
    {
        for(int i = 1; i <= n; i++)
        {
            // Clear distance tables for the current number of masks (2^(z+1))
            for(int j = 0; j < (1<<(z + 1)); j++)
            {
                O[i][j] = -1;
                O2[i][j] = -1;
            }          
        }
        // BFS from both ends (Meet-in-the-middle approach)
        BFS(1, O, d, z, G, swords, results);
        BFS(n, O2, d, z, G, swords, results);
    
        
        bool searching = true;
        for(int i = 0; i < m && searching; i++)
        {
            int cost = 0;
            int cost2 = 0;
            int key2;

            for(int j = 0; j < (1 << z); j++)
            {
                key = j;
                key2 = (j ^ ((1 << z) - 1));
                for(int g = 0; g < z; g++)
                {
                    if(edge_index[edges[z][i].i][g] == results[g])
                    {
                        if(key & (1 << g)) key -= (1 << g); 
                        if(key2 & (1 << g)) key2 -= (1 << g);
                    }
                }       

                cost = O[edges[z][i].a][key];
                cost2 = O2[edges[z][i].b][key2];
                if(cost == -1) cost = 2 * d + 1;
                if(cost2 == -1) cost2 = 2 * d + 1;

                if(cost + cost2 + 1 <= d)
                {        
                    results[z] = edges[z][i].w;
                    searching = false;
                    break;
                }

                cost = O[edges[z][i].b][key];
                cost2 = O2[edges[z][i].a][key2];
                if(cost == -1) cost = 2 * d + 1;
                if(cost2 == -1) cost2 = 2 * d + 1;


                if(cost + cost2 + 1 <= d)
                {
                    results[z] = edges[z][i].w;
                    searching = false;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < k; i++)
    {
        cout<<results[i]<<" ";
    }
    return 0;
}