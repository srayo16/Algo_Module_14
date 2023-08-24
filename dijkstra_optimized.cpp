#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
const int INF = 1e9 + 10;
vector<pair<int, int>> arr[N];
bool visited[N];
int level[N];
vector<int> dist(N, INF);
// int dist[N];

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[s] = 0;
    q.push({dist[s], s});

    while (!q.empty())
    {
        pair<int, int> pq = q.top();
        q.pop();

        int parentNode = pq.second;
        if (visited[parentNode])
        {
            continue;
        }
        visited[parentNode] = true;
        int parentCost = pq.first;

        for (pair<int, int> i : arr[parentNode])
        {
            int childNode = i.first;
            int childCost = i.second;

            if ((parentCost + childCost) < dist[childNode])
            {
                dist[childNode] = parentCost + childCost;
                q.push({dist[childNode], childNode});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back({v, w});
        arr[v].push_back({u, w});
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     dist[i] = INT_MAX;
    // }
    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of node: " << i << ": ";
        cout << dist[i] << endl;
    }

    return 0;
}