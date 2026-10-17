class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize!=0) return false;
        map<int,int>cnt;
        for(int c: hand) cnt[c]++;
        while(!cnt.empty()){
            int start = cnt.begin()->first;
            for(int i=0;i<groupSize;i++){
                int card=start+i;
                auto it=cnt.find(card);
                if(it==cnt.end()) return false;
                if(--(it->second)==0) cnt.erase(it);
            }
        }
        return true;
        
    }
};