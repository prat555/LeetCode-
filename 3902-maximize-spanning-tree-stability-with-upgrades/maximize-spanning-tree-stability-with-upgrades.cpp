class Solution {
public:
    // Union-Find (DSU) with path compression + union by rank
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
        // First, add all mandatory edges and check validity
        DSU base(n);
        int mn = INT_MAX; // min strength among mandatory edges

        for (auto& e : edges) {
            if (e[3] == 1) { // must include
                if (!base.unite(e[0], e[1])) return -1; // cycle among mandatory
                mn = min(mn, e[2]);
            }
        }

        // Check if even all edges together can connect the graph
        DSU full(n);
        for (auto& e : edges) full.unite(e[0], e[1]);
        if (full.components > 1) return -1;

        // If no mandatory edges, binary search upper bound is max edge strength * 2
        // But we binary search in [1, mn] where mn caps our answer
        // (mandatory edges can't be upgraded, so stability <= min mandatory strength)
        if (mn == INT_MAX) {
            // All edges optional - find max possible after upgrades
            // Stability bounded by max edge strength (possibly doubled)
            mn = 0;
            for (auto& e : edges) mn = max(mn, e[2] * 2);
        }

        // check(lim): can we form a spanning tree with stability >= lim?
        auto check = [&](int lim) -> bool {
            DSU dsu(n);

            // First, add all mandatory edges (strength >= lim required,
            // but they MUST be included — if any mandatory < lim, fail)
            for (auto& e : edges) {
                if (e[3] == 1) {
                    if (e[2] < lim) return false;
                    dsu.unite(e[0], e[1]);
                }
            }

            // Add optional edges with strength >= lim (no upgrade needed)
            for (auto& e : edges) {
                if (e[3] == 0 && e[2] >= lim) {
                    dsu.unite(e[0], e[1]);
                }
            }

            // Use upgrades for optional edges with strength in [lim/2, lim-1]
            // (doubling them would make them >= lim)
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

        // Binary search on stability value
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