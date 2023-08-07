#include<iostream>
using namespace std;

bool L_search(int* arr, int size, int n){
    
    // base case
    if(size == 0){
        return false;
    }
    if(arr[0] == n)
    return true;

    bool ans = L_search(arr+1, size-1, n);
    return ans;

}

int main() {
    int arr[5] = {1, 2, 4, 5, 8};
    int n;

    cout << "Enter the element to search for : ";
    cin >> n;

    bool ans = L_search(arr, 5, n);

    if(ans){
        cout << "Element found !!";
    }
    else
    cout << "element not found !!";

    return 0;
}