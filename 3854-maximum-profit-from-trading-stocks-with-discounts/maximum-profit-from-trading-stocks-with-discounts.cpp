class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> adj(n);
        const auto& iter_dfs = [&]() {
            using RET = vector<unordered_map<int, int>>;
            RET ret(2);
            vector<tuple<int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, nullptr, &ret}};
            while (!empty(stk)) {
                const auto [step, u, i, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    (*ret)[0][0] = (*ret)[1][0] = 0;
                    stk.emplace_back(4, u, -1, nullptr, ret);
                    stk.emplace_back(2, u, 0, nullptr, ret);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    const auto& v = adj[u][i];
                    stk.emplace_back(2, u, i + 1, nullptr, ret);
                    const auto& new_ret = make_shared<RET>(2);
                    stk.emplace_back(3, -1, -1, new_ret, ret);
                    stk.emplace_back(1, v, -1, nullptr, new_ret.get());
                } else if (step == 3) {
                    for (int i = 0; i < 2; ++i) {
                        unordered_map<int, int> copy_dp((*ret)[i]);
                        for (const auto& [j1, v1] : copy_dp) {
                            for (const auto& [j2, v2] : (*new_ret)[i]) {
                                if (j1 + j2 <= budget) {
                                    (*ret)[i][j1 + j2] = max((*ret)[i][j1 + j2], v1 + v2);
                                }
                            }
                        }
                    }
                } else if (step == 4) {
                    RET new_ret(2);
                    for (int i = 0; i < 2; ++i) {
                        for (const auto& [j, v] : (*ret)[0]) {
                            new_ret[i][j] = max(new_ret[i][j], v);
                        }
                        const int cost = present[u] >> i;
                        if (cost > budget) {
                            continue;
                        }
                        const int profit = future[u] - cost;
                        for (const auto& [j, v] : (*ret)[1]) {
                            if (j + cost <= budget) {
                                new_ret[i][j + cost] = max(new_ret[i][j + cost], v + profit);
                            }
                        }
                    }
                    *ret = move(new_ret);
                }
            }
            int result = 0;
            for (const auto& [_, v] : ret[0]) {
                result = max(result, v);
            }
            return result;
        };

        for (const auto& h: hierarchy) {
            adj[h[0] - 1].emplace_back(h[1] - 1);
        }
        return iter_dfs();
    }
};