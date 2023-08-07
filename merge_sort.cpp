#include<iostream>
using namespace std;

void merge(int* arr, int s, int e){
    
    int mid = s+(e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values

    int mainindexarray = s;
    for(int i = 0; i<len1; i++) {
        first[i] = arr[mainindexarray++];
    }

    mainindexarray = mid+1;

    for(int i = 0; i<len2; i++) {
        second[i] = arr[mainindexarray++];
    }

    //merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    mainindexarray = s;

    while(index1 < len1 && index2 < len2){

        if(first[index1] < second[index2]){
            arr[mainindexarray++] = first[index1++];
        }
        else {
            arr[mainindexarray++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainindexarray++] = first[index1++];
    }

    while(index2 < len2){
        arr[mainindexarray++] = second[index2++];
    }

    delete []first;
    delete []second;
}
void merge_sort(int* arr, int s, int e){
    // Base case
    if(s >= e){
        return ;
    }

    int mid = s+(e-s)/2;

    //left part ko sort karo
    merge_sort(arr, 0, mid);

    //right part ko karo
    merge_sort(arr, mid+1, e);

    //merge kar do
    merge(arr, s, e);

}

int main() {

    int arr[5] = {2, 4, 1, 3, 5};
    int n = 5;

    merge_sort(arr, 0, n-1);
    for(int i = 0; i<n; i++) {
        cout << arr[i] << "  ";
    }
    
    return 0;
}