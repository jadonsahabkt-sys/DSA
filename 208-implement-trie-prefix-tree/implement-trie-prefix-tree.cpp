class Trie {
    struct Node{
        Node* next[26] ={};
        bool isEnd=false;
    };
    Node* root;
    Node* walk(const string& s){
        Node* cur=root;
        for(char c: s){
            int i=c-'a';
            if(!cur->next[i]) return nullptr;
            cur=cur->next[i];
        }
        return cur;
    }
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* cur=root;
        for(char c : word){
            int i=c-'a';
            if(!cur->next[i])
            cur->next[i]=new Node();
            cur=cur->next[i];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        Node* n =walk(word);
        return n && n->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        return walk(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */