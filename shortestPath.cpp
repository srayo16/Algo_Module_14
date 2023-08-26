#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 10;
vector<int> arr[N];
bool visited[N];
int level[N];
int path[N];
int dist[N];

void bfsPath(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    path[s] = -1;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : arr[parent])
        {
            if (!visited[child])
            {
                path[child] = parent;
                dist[child] = dist[parent] + 1;
                visited[child] = true;
                q.push(child);
            }
        }
    }
}

void recursionPrint(int s)
{
    if (s == -1)
        return;

    recursionPrint(path[s]);
    cout << s << endl;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    bfsPath(1);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Shortest path of node " << i << ": " << path[i] << endl;
    // }
    int x;
    cin >> x;
    if (visited[x])
    {
        // while (x != -1)
        // {
        //     cout << x << " -> ";
        //     x = path[x];
        // }

        recursionPrint(x);
    }
    return 0;
}