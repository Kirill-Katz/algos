#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }

    return parent[x];
}

void unite(vector<int>& parent, vector<int>& size, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);

    parent[b] = a;
    size[a] += size[b];
}

int main() {
    int n; cin >> n;
    vector<int> parent(n);
    vector<int> size(n);
}

