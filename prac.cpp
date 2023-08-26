#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 10;
vector<pair<int, int>> arr[N];
bool visited[N];
int level[N];
vector<int> dist(N, INF);

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();

        int parentNode = parent.second;
        if (visited[parentNode])
        {
            continue;
        };
        int parentCost = parent.first;
        visited[parentNode] = true;
        for (pair<int, int> i : arr[parentNode])
        {
            int childNode = i.first;
            int childCost = i.second;

            if ((parentCost + childCost) < dist[childNode])
            {
                dist[childNode] = parentCost + childCost;
                pq.push({dist[childNode], childNode});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        arr[u].push_back({v, w});
        arr[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of node " << i << ": " << dist[i] << endl;
    }

    return 0;
}