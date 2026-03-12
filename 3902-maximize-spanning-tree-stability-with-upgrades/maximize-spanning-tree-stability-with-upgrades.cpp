class Solution {
public:
    struct DSU {
        vector<int> parent, rank_;
        int components;

        DSU(int n) : parent(n), rank_(n, 0), components(n) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int x, int y) {
            x = find(x); y = find(y);
            if (x == y) return false;
            if (rank_[x] < rank_[y]) swap(x, y);
            parent[y] = x;
            if (rank_[x] == rank_[y]) rank_[x]++;
            components--;
            return true;
        }
    };

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU base(n);
        int mn = INT_MAX;

        for (auto& e : edges) {
            if (e[3] == 1) {
                if (!base.unite(e[0], e[1])) return -1;
                mn = min(mn, e[2]);
            }
        }

        DSU full(n);
        for (auto& e : edges) full.unite(e[0], e[1]);
        if (full.components > 1) return -1;

        if (mn == INT_MAX) {
            mn = 0;
            for (auto& e : edges) mn = max(mn, e[2] * 2);
        }

        auto check = [&](int lim) -> bool {
            DSU dsu(n);

            for (auto& e : edges) {
                if (e[3] == 1) {
                    if (e[2] < lim) return false;
                    dsu.unite(e[0], e[1]);
                }
            }

            for (auto& e : edges) {
                if (e[3] == 0 && e[2] >= lim) {
                    dsu.unite(e[0], e[1]);
                }
            }

            int upgrades = k;
            for (auto& e : edges) {
                if (upgrades == 0) break;
                if (e[3] == 0 && e[2] * 2 >= lim && e[2] < lim) {
                    if (dsu.unite(e[0], e[1])) {
                        upgrades--;
                    }
                }
            }

            return dsu.components == 1;
        };

        int lo = 1, hi = mn, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};