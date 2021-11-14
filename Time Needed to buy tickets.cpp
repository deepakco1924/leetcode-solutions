class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        vector<int>ans(n, 0);
        deque<pair<int, int>>q;
        for (int i = 0; i < n; i++) {
            q.push_back({tickets[i], i});
        }
        while (!q.empty()) {
            pair<int, int>node = q.front();
            q.pop_front();
            node.first--;
            ans[node.second]++;
            if (node.first > 0) {
                q.push_back(node);
            }
            else if (node.second == k) {
                break;
            }
        }
        int s = 0;
        for (auto x : ans) {
            s += x;
        }
        return s;

    }
};