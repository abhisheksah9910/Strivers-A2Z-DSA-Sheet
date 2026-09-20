#include <iostream>
#include <vector>
using namespace std;

//same as lower Bound but only it search element greater than target not eqaul to 

int upperBound(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n-1;
    int ans=n;
    while(low<=high){
        int mid = (low+high)/2;
        // Maybe an answer
        if(arr[mid]> x){
            ans=mid;
            // Look for a smaller index on the left
            high=mid-1;
        }else{
            // Look for the answer on the right
            low=mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 6, 8};
    int n = arr.size();
    int x = 4;

    int result = upperBound(arr, n, x);

    cout << "Upper Bound Index: " << result << endl;

    return 0;
}