#include <bits/stdc++.h>
using namespace std;

#define max 1000
vector <int> A(max), tree(4*max);


void build(int node, int start, int end)
{
    if(start == end)
    tree[node] = A[start];
    else
    {
    int mid = (start + end)/2;
    build(2*node + 1, start, mid);
    build(2*node + 2, mid + 1, end);
    tree[node] =  tree[2*node + 1] > tree[2*node + 2] ? tree[2*node + 1] : tree[2*node + 2];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end)/2;
        if(start <= idx && idx <= mid)
        update(2*node + 1, start, mid, idx, val);
        else
        update(2*node + 2, mid + 1, end, idx, val);
        tree[node] = tree[2*node + 1] > tree[2*node + 2] ? tree[2*node + 1] : tree[2*node + 2];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(start > r || end < l)
    return 0;
    else
    if(start >= l && end <= r)
        return tree[node];
    int mid = (start + end)/2;
    int p1 = query(2*node + 1, start, mid, l , r);
    int p2 = query(2*node + 2, mid + 1,end, l, r);
    return p1 > p2 ? p1 : p2;
}

int main() 
{
    int n, q, x, y, type;
    cin >> n;
    for(int i=0; i < n; i++)
    cin >> A[i];
    cin >> q;
    build(0, 0, n-1);
    while(q--)
    {
        cin >> type >> x >> y;
        if(type == 1)  // read query
        {
            cout<<query(0, 0, n-1, x, y)<<endl;
        }
        else
        if(type == 2)
        update(0, 0, n-1, 3, 15);
    }
    for(int i=0;i<9;i++)
    cout<<tree[i]<<" ";
	return 0;
}
