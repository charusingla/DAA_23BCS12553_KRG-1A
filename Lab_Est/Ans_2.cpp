#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<pair<int,int>>> cols;
    queue<pair<TreeNode*, pair<int,int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        TreeNode* node = p.first;
        int col = p.second.first;
        int row = p.second.second;

        cols[col].push_back({row, node->val});

        if (node->left) q.push({node->left, {col - 1, row + 1}});
        if (node->right) q.push({node->right, {col + 1, row + 1}});
    }

    vector<vector<int>> ans;
    for (auto &entry : cols) {
        auto &v = entry.second;
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        vector<int> temp;
        for (auto &p : v) temp.push_back(p.second);
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);

    auto res = verticalTraversal(r);
    for (auto &col : res) {
        for (int x : col) cout << x << " ";
        cout << "\n";
    }
}