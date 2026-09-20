#include <iostream>
#include <vector>
using namespace std;
//This is for Floor value
int floorValue(vector<int> arr, int n, int x) {

    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]<=x){
            ans=arr[mid];
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}

//This is for Ceil value
int CeilValue(vector<int> arr, int n, int x) {

    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid = low+ (high-low)/2;
        if(arr[mid]>=x){
            ans=arr[mid];
            high = mid-1;
        }else{
            low= mid+1;
        }
    }
    return ans;
}


int main() {

    vector<int> arr = {1, 2, 4, 6, 8};

    int n = arr.size();
    int x = 5;

    int result = floorValue(arr, n, x);
    int result2 = CeilValue(arr,n,x);
    cout << "Floor: " << result << endl;
    cout << "Ceil: " << result2 << endl;

    return 0;
}