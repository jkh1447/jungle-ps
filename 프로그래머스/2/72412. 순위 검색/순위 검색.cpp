#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string &s, string delimiter){
    vector<string> tokens;
    int pos = 0;
    while(pos < s.size()){
        int nxt_pos = s.find(delimiter, pos);
        if (nxt_pos == -1) nxt_pos = s.size();
        if (nxt_pos - pos > 0) 
            tokens.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + delimiter.size();
    }
    return tokens;
}


struct Node {
    string s;
    map<string, Node *> m;
    vector<int> v;
    Node(string name): s(name){}
};

int travell(vector<string>& s, Node* cur, int i){
    if(i == 4){
        int idx = lower_bound(cur->v.begin(), cur->v.end(), stoi(s[s.size()-1])) - cur->v.begin();
        // cout << "idx: " << idx << "\n";
        return cur->v.size() - idx;
    }
    int answer = 0;
    // cout << "i: " << i << ", " << s[i]  << ", " << cur->s << "\n";
    if(s[i] == "-"){
        for(auto nxt: cur->m){
            answer += travell(s, nxt.second, i+1);
        }
    }
     else {
        
        if(cur->m.find(s[i]) != cur->m.end()) {
        
            answer += travell(s, cur->m[s[i]], i+1);
        }
            
    }
    
    return answer;
}

void preprocess(Node* cur) {
    sort(cur->v.begin(), cur->v.end());
    for (auto &p : cur->m) {
        preprocess(p.second);
    }
}


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    Node* root = new Node("root");
    

    
    for(int i=0; i<info.size(); i++){
        vector<string> inf = split(info[i], " ");
        
        Node *cur = root;
        for(int j=0; j<inf.size() - 1; j++){
            if(cur->m.find(inf[j]) == cur->m.end()) cur->m[inf[j]] = new Node(inf[j]);
            cur = cur->m[inf[j]];
        }
        cur->v.push_back(stoi(inf[inf.size()-1]));
    }
    
    preprocess(root);

    for(int q=0; q < query.size(); q++){
        vector<string> q1 = split(query[q], " and ");
        vector<string> q2 = split(q1[3], " ");
        q1.pop_back(); q1.push_back(q2[0]); q1.push_back(q2[1]);
        Node *cur = root;
        int ans = travell(q1, cur, 0);

        answer.push_back(ans);
    }
    
    
    return answer;
}