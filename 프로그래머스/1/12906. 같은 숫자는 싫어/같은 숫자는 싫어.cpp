#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    stack<int> st;
    for(int i=0; i<arr.size(); i++){
        if(st.empty()) {
            st.push(arr[i]);   
            answer.push_back(arr[i]);
        }
        else if(st.top() != arr[i]){
            st.push(arr[i]);
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}