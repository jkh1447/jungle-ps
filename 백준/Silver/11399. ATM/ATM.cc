
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    int sum = 0;
    cin >> n; 
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 0; i < n; i++){
        sum += (n-i) * arr[i];
    }
    cout << sum;
    
    return 0;
}