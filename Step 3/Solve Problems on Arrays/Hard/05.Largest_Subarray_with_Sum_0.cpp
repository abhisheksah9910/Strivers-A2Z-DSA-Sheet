/*
============================================================
Problem: Largest Subarray with Sum 0
Platform: GeeksforGeeks
Topic: Arrays | Prefix Sum | Hash Map
============================================================

Problem Statement:
Given an integer array, find the length of the
longest subarray whose sum is equal to 0.

------------------------------------------------------------
Approaches:

1. Brute Force

- Generate every possible subarray.
- Calculate the sum of each subarray.
- If the sum becomes 0, update the maximum length.

Time Complexity : O(n²)
Space Complexity: O(1)

------------------------------------------------------------
2. Optimal Approach (Prefix Sum + Hash Map)

Idea:

Maintain a running prefix sum while traversing
the array.

Case 1:
If prefix sum becomes 0,
then the subarray from index 0 to i has sum 0.

Case 2:
If the same prefix sum is seen again,
then the elements between the previous occurrence
and the current index have sum 0.

Store only the first occurrence of each prefix sum
to maximize the subarray length.

------------------------------------------------------------
Algorithm:

1. Initialize:
   - prefixSum = 0
   - maxLength = 0
   - HashMap<sum, firstIndex>

2. Traverse the array:
   - Add current element to prefixSum.
   - If prefixSum == 0,
     update maxLength.
   - If prefixSum already exists,
     update maxLength using:
     currentIndex - firstOccurrence.
   - Otherwise store the prefixSum and its index.

------------------------------------------------------------
Example:

Input:
arr = [15, -2, 2, -8, 1, 7, 10, 23]

Output:
5

Explanation:
Longest subarray with sum 0:
[-2, 2, -8, 1, 7]

------------------------------------------------------------
Why Prefix Sum?

If two prefix sums are equal:

prefixSum(i) = prefixSum(j)

then

sum(i+1 ... j) = 0

This property allows us to find the answer in one
traversal using a Hash Map.

------------------------------------------------------------
Complexity:

Brute Force
Time  : O(n²)
Space : O(1)

Optimal Approach
Time  : O(n)
Space : O(n)

============================================================
*/

#include<bits/stdc++.h>
using namespace std;
            //brute force
// int main() {
//     vector<int> arr{15, -2, 2, -8, 1, 7, 10, 23};
//     int n = arr.size();
//     int maxi = 0;
//     for(int i = 0; i < n; i++) {
//         int sum = 0;
//         for(int j = i; j < n; j++) {
//             sum += arr[j];
//             if(sum == 0) {
//                 maxi = max(maxi, j - i + 1);
//             }
//         }
//     }
//     cout << maxi;
//     return 0;
// }

            //optimal
int main(){
    vector<int> arr{15, -2, 2, -8, 1, 7, 10, 23};
    map<int,int> mpp;
    int maxi=0;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==0){
            maxi = i+1;
        }else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi,i-mpp[sum]);
            }else{
                mpp[sum]=i;
            }
        }
    }
    cout<<maxi;
}