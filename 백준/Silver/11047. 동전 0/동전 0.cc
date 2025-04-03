#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int price = 0;
    int result = 0;
    int count = 0;
    cin >> n >> price; 

    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for (int i = n-1; i >= 0; i--){
        count = price / arr[i];
        price = price - arr[i] * count;
        result += count;
    }
    
    cout << result;
    return 0;
}