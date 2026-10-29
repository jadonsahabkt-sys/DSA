class Solution {
    unordered_map<string,int> dist;
    vector<vector<string>> res;
    vector<string> path;
    string begin;

    void dfs(const string& word) {
        if (word == begin) {
            res.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        int d = dist[word];
        string w = word;
        for (int i = 0; i < (int)w.size(); i++) {
            char orig = w[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == orig) continue;
                w[i] = c;
                auto it = dist.find(w);
                if (it != dist.end() && it->second == d - 1) {
                    path.push_back(w);
                    dfs(w);
                    path.pop_back();
                }
            }
            w[i] = orig;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        dist.clear();
        res.clear();
        path.clear();

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        begin = beginWord;

        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            string w = q.front(); q.pop();
            if (w == endWord) break;
            int d = dist[w];
            string t = w;
            for (int i = 0; i < (int)t.size(); i++) {
                char orig = t[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == orig) continue;
                    t[i] = c;
                    if (dict.count(t) && !dist.count(t)) {
                        dist[t] = d + 1;
                        q.push(t);
                    }
                }
                t[i] = orig;
            }
        }

        if (!dist.count(endWord)) return {};
        path.push_back(endWord);
        dfs(endWord);
        return res;
    }
};


        

