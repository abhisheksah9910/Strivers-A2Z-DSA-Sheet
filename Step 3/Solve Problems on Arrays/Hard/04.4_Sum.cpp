/*
============================================================
Problem: 4Sum
Platform: LeetCode 18
Topic: Arrays | Sorting | Two Pointers | Hashing
============================================================

Problem Statement:
Given an integer array nums and an integer target,
return all unique quadruplets

[nums[a], nums[b], nums[c], nums[d]]

such that:

nums[a] + nums[b] + nums[c] + nums[d] = target

The solution set must not contain duplicate quadruplets.

------------------------------------------------------------
Approaches:

1. Brute Force
   - Generate every possible quadruplet using four loops.
   - Store valid quadruplets in a set to remove duplicates.

   Time Complexity : O(n⁴)
   Space Complexity: O(M)

------------------------------------------------------------
2. Better Approach (Hashing)

Step 1:
Fix the first two elements using two loops.

Step 2:
Use a HashSet to find the fourth element.

Required value:
fourth = target - (a + b + c)

If 'fourth' already exists in the HashSet,
a valid quadruplet is found.

Store quadruplets in a set to avoid duplicates.

Time Complexity : O(n³)
Space Complexity: O(n) + O(M)

------------------------------------------------------------
3. Optimal Approach (Sorting + Two Pointers)

Step 1:
Sort the array.

Step 2:
Fix the first element (i).

Step 3:
Fix the second element (j).

Step 4:
Use two pointers:
left = j + 1
right = n - 1

Calculate:
sum = nums[i] + nums[j] + nums[left] + nums[right]

If sum == target:
    Store the quadruplet.
    Move both pointers.
    Skip duplicate values.

If sum < target:
    Move left pointer.

If sum > target:
    Move right pointer.

Duplicate Handling:
✔ Skip duplicate values for i.
✔ Skip duplicate values for j.
✔ Skip duplicate values for left and right
  after finding a valid quadruplet.

------------------------------------------------------------
Example:

Input:
nums = [1,0,-1,0,-2,2]
target = 0

Sorted:
[-2,-1,0,0,1,2]

Output:
[-2,-1,1,2]
[-2,0,0,2]
[-1,0,0,1]

------------------------------------------------------------
Why Sorting?

Sorting helps to:
✔ Apply the two-pointer technique.
✔ Skip duplicate elements efficiently.
✔ Reduce the complexity from O(n⁴) to O(n³).

------------------------------------------------------------
Complexity Summary

Brute Force
Time  : O(n⁴)
Space : O(M)

Better Approach
Time  : O(n³)
Space : O(n) + O(M)

Optimal Approach
Time  : O(n³)
Space : O(1)      // Ignoring the output array

============================================================
*/


#include<bits/stdc++.h>
using namespace std;

            //Brute force
// int main() {
//     vector<int> arr{1,0,-1,0,-2,2};
//     int target;
//     cin >> target;
//     int n = arr.size();
//     sort(arr.begin(), arr.end());

//     set<vector<int>> ans;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 for(int l=k+1;l<n;l++){
//                     long long sum=(long long)arr[i]+arr[j]+arr[k]+arr[l];

//                     if(sum==target){
//                         ans.insert({arr[i],arr[j],arr[k],arr[l});
//                     }
//                 }
//             }
//         }
//     }
//     if(ans.empty()){
//         cout<<"No quadruplets found";
//     }
//     else{
//         for(auto x:ans){
//             cout<<"{ ";
//             for(auto y:x){
//                 cout<<y<<" ";
//             }
//             cout<<"}"<<endl;
//         }
//     }
//     return 0;
// }


            //better solution



// int main() {
//     vector<int> arr{1,0,-1,0,-2,2};
//     int target;
//     cin >> target;
//     int n = arr.size();
//     sort(arr.begin(), arr.end());

//     set<vector<int>> ans;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             unordered_set<int> st;
//             for(int k=j+1;k<n;k++){
//                 long long fourth=(long long)target-arr[i]-arr[j]-arr[k];
//                 if(st.find(fourth)!=st.end()){
//                     vector<int> temp={arr[i],arr[j],(int)fourth,arr[k]};
//                     sort(temp.begin(),temp.end());
//                     ans.insert(temp);

//                 }
//                 st.insert(arr[k]);
//             }
//         }
//     }
//     if(ans.empty()){
//         cout<<"No quadruplets found";
//     }
//     else{
//         for(auto x:ans){
//             cout<<"{ ";
//             for(auto y:x){
//                 cout<<y<<" ";
//             }
//             cout<<"}"<<endl;
//         }
//     }
//     return 0;
// }



            // optimal solution



int main() {
    vector<int> arr{1,0,-1,0,-2,2};
    int target;
    cin >> target;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])
            continue;
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && arr[j]==arr[j-1])
                continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=(long long)arr[i]+arr[j]+arr[k]+arr[l];
                if(sum==target){
                    ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])
                        k++;
                    while(k<l && arr[l]==arr[l+1])
                        l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }
    if(ans.empty()){
        cout<<"No quadruplets found";
    }
    else{
        for(auto x:ans){
            cout<<"{ ";
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"}"<<endl;
        }
    }
    return 0;
}