#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define pb push_back
typedef vector<int> vi;
#define mod 1000000007
vi v[10005], p(10005);
int n, m;
int find(int x)
{
    if (x == p[x])
        return x;
    return find(p[x]);
}
void union1(int x, int y)
{
    int p1 = find(x), p2 = find(y);
    if (p1 == p2)
        return;
    p[p2] = p1;
}
void init()
{
    for (int i = 1; i <= n; i++)
        p[i] = i;
}
int kruskal(vector<pair<int, pair<int, int>>> edges)
{
    int cost, x, y, t_cost = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        x = edges[i].s.f;
        y = edges[i].s.s;
        cost = edges[i].f;
        if (find(x) != find(y))
        {
            union1(x, y);
            t_cost += cost;
        }
    }
    return t_cost;
}
int32_t main()
{
    int a, b, w;
    vector<pair<int, pair<int, int>>> edges;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        edges.pb({w, {a, b}});
    }
    init();
    sort(edges.begin(), edges.end());
    cout << kruskal(edges);
    return 0;
}
