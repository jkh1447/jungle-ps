#include <string>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
        unordered_set<string> hash;
    for (auto& num : phone_book)
        hash.insert(num);
    
    for (auto& num : phone_book) {
        string prefix = "";
        for (int i = 0; i < num.size() - 1; i++) {
            prefix += num[i];
            if (hash.find(prefix) != hash.end())
                return false;  // 접두어 발견
        }
    }
    return true;

} 