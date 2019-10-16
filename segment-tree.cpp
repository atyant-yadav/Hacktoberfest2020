#include<bits/stdc++.h>
using namespace std;
int Tree[262150], A[100010];

void construct(int node, int start, int end){
    if(start == end){
        Tree[node] = A[start];
    }
    else{
        int mid = (start + end)/2;
        construct(node*2, start, mid);
        construct(node*2 +1, mid+1, end);
        Tree[node] = min(Tree[node*2], Tree[node*2 +1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(l > end or r < start){
        return INT_MAX;
    }
    if(l <= start and r >= end){
        return Tree[node];
    }
    int mid = (start + end)/2;
    int p = query(node*2, start, mid, l, r);
    int q = query(node*2 +1, mid+1, end, l, r);
    return min(p,q);
}

void update(int node, int start, int end, int i, int val){
    if(start == end){
        A[i] = val;
        Tree[node] = val;
    }
    
    else{
        int mid = (start+end)/2;
        if(start <= i and i <= mid){
            update(node*2, start, mid, i, val);
        }
        else{
            update(node*2 +1, mid+1, end, i, val);
        }
        Tree[node] = min(Tree[node*2], Tree[node*2 +1]);
    }
}

int main(){
    int N, Q, l, r;
    char O;
    cin >> N >> Q;
    for(int i = 0; i<N; i++){
        cin >> A[i];
    }
    construct(1, 0, N-1);
    while(Q--){
        cin >> O >> l >> r;
        if(O == 'q'){
            cout << query(1, 0, N-1, l-1, r-1);
        }
        else{
            update(1, 0, N-1, l-1, r);
        }
    }
}
