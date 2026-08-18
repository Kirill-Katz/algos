
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> src(n);
    iota(src.begin(), src.end(), 1);

    vector<int> seg(4 * n + 5);

    auto fill = [&](auto&& self, int u, int l, int r) {
        if (l == r) {
            seg[u] = src[l];
            return;
        }

        int m = l + (r - l) / 2;
        int left = 2 * u + 1;
        int right = 2 * u + 2;

        self(self, left, l, m);
        self(self, right, m + 1, r);

        seg[u] = max(seg[left], seg[right]);
    };

    auto change = [&](auto&& self, int u, int l, int r, int p, int v) {
        if (l > p || p > r) {
            return;
        }

        if (l == r && l == p) {
            seg[u] = v;
            return;
        }

        int left = 2 * u + 1;
        int right = 2 * u + 2;

        int m = l + (r - l) / 2;

        self(self, left, l, m, p, v);
        self(self, right, m + 1, r, p, v);

        seg[u] = max(seg[left], seg[right]);
    };
}

int compact() {
    int n
    cin >> n;

    vector<int> src(n);
    iota(src.begin(), src.end(), 1);

    vector<int> seg(n * 2);

    auto fill = [&](const auto& src, auto& seg) {
        for (int i = 0; i < n; ++i) {
            seg[n + i] = src[i];
        }
        for (int i = n - 1; i > 0; --i) {
            seg[i] = max(seg[2 * i], seg[2 * i + 1]);
        }
    };

    auto change = [&](auto& seg, int p, auto v) {
        p += seg.size() / 2;
        seg[p] = v;

        while (p > 1) {
            p /= 2;
            seg[p] = max(seg[2 * p], seg[2 * p + 1]);
        }
    };

    auto get = [&](auto& seg, int l, int r) {
        int res = 0;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        }

        return res;
    };
}

void lazy() {
    auto fill = [&](auto&& self, auto& seg, const auto& src, int u, int l, int r) -> void {
        if (l == r) {
            seg[u] = src[l];
            return;
        }

        int left_u = 2 * u + 1;
        int right_u = 2 * u + 2;

        int m = l + (r - l) / 2;

        self(self, seg, src, left_u, l, m);
        self(self, seg, src, right_u, m + 1, r);

        seg[u] = max(seg[left_u], seg[right_u]);
    };

    auto apply = [&](auto& seg, auto& lazy, int u, long long v) {
        seg[u] += v;
        lazy[u] += v;
    };

    auto push = [&](auto& seg, auto& lazy, int u) {
        if (lazy[u] == 0) {
            return;
        }

        int left_u = 2 * u + 1;
        int right_u = 2 * u + 2;

        apply(seg, lazy, left_u, lazy[u]);
        apply(seg, lazy, right_u, lazy[u]);

        lazy[u] = 0;
    };

    auto add = [&](auto&& self, auto& seg, auto& lazy, int u, int l, int r, int ql, int qr, long long v) -> void {
        if (r < ql || qr < l) {
            return;
        }

        if (ql <= l && r <= qr) { // node range inside the range we want
            seg[u] += v;
            lazy[u] += v;
            return;
        }

        push(seg, lazy, u); // if not apply lazy propagation to chidren

        int left_u = 2 * u + 1;
        int right_u = 2 * u + 2;
        int m = l + (r - l) / 2;

        // so that this has the correct values.
        self(self, seg, lazy, left_u, l, m, ql, qr, v);
        self(self, seg, lazy, right_u, m + 1, r, ql, qr, v);

        seg[u] = max(seg[left_u], seg[right_u]);
    };

    auto get = [&](auto&& self, auto& seg, auto& lazy, int u, int l, int r, int ql, int qr) {
        if (r < ql || qr < l) {
            return LLONG_MIN;
        }

        if (ql <= l && r <= qr) {
            return seg[u];
        }

        push(seg, lazy, u);

        int left = 2 * u + 1;
        int right = 2 * u + 2;
        int m = l + (r - l) / 2;

        return max(
            self(self, seg, lazy, left, l, m, ql, qr),
            self(self, seg, lazy, right, m + 1, r, ql, qr)
        );
    };
};


