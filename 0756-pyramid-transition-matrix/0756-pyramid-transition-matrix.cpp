#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // ===== 1. 建立 allowed 的查表結構 =====
        // key: 下面兩個字母 (e.g. "AB")
        // val: 所有可以放在上面的字母 (e.g. "CDE")
        unordered_map<string, string> mp;
        for (const string& p : allowed) {
            mp[p.substr(0, 2)].push_back(p[2]);
        }

        // ===== 2. DFS stack（搜索空間）=====
        vector<string> stack;
        stack.push_back(bottom);

        // ===== 3. visited：避免重複狀態 =====
        unordered_set<string> visited;

        // ===== 4. DFS 主迴圈 =====
        while (!stack.empty()) {
            string cur = stack.back();
            stack.pop_back();

            // 若這個狀態已經處理過，直接跳過
            if (visited.count(cur)) continue;
            visited.insert(cur);

            // 成功條件：只剩一個字母
            if (cur.size() == 1) return true;

            // ===== 5. 建立 candidates =====
            // candidates[i] = 第 i 個位置上方可選的字母集合
            vector<string> candidates;
            bool dead = false;

            for (int i = 0; i < cur.size() - 1; i++) {
                string key = cur.substr(i, 2);

                // 查不到規則，這條路死掉
                if (!mp.count(key)) {
                    dead = true;
                    break;
                }

                candidates.push_back(mp[key]);
            }

            if (dead) continue;

            // ===== 6. 笛卡爾積：生成所有下一層字串 =====
            vector<string> res;
            res.push_back("");  // 起始空前綴

            for (const string& s : candidates) {
                vector<string> next;
                for (const string& prefix : res) {
                    for (char c : s) {
                        next.push_back(prefix + c);
                    }
                }
                res.swap(next);
            }

            // ===== 7. 將下一層全部丟回 DFS stack =====
            for (const string& nb : res) {
                stack.push_back(nb);
            }
        }

        // 所有可能都試完，無法堆到頂
        return false;
    }
};