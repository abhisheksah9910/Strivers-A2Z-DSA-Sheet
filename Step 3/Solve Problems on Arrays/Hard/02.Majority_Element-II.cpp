/*
============================================================
Problem: Majority Element II
Platform: LeetCode 229
Topic: Arrays | Boyer-Moore Voting Algorithm | Hashing
============================================================

Problem Statement:
Given an integer array of size n, return all elements
that appear more than ⌊n/3⌋ times.

Note:
There can be at most two majority elements.

------------------------------------------------------------
Approaches:

1. Better Approach (Hash Map)
   - Count the frequency of every element using a map.
   - Return elements whose frequency is greater than n/3.

   Time Complexity : O(n log n)   // map
   Space Complexity: O(n)

2. Optimal Approach (Boyer-Moore Voting Algorithm)

Step 1:
Find two potential candidates using the voting algorithm.

Step 2:
Verify whether those candidates actually occur
more than ⌊n/3⌋ times.

Why only two candidates?
Because an array can have at most two elements whose
frequency is greater than n/3.

------------------------------------------------------------
Algorithm:

1. Maintain two candidates (el1, el2) and their counts.
2. Traverse the array:
   - Increase count if current element matches a candidate.
   - If a count becomes zero, replace that candidate.
   - Otherwise decrease both counts.
3. Traverse again to verify both candidates.
4. Return the valid majority elements.

------------------------------------------------------------
Example:

Input:
nums = [3,2,3,2,2,3]

Output:
2 3

Frequency:
2 -> 3 times
3 -> 3 times
n = 6
⌊n/3⌋ = 2

Both occur more than 2 times.

------------------------------------------------------------
Complexity:

Better Approach
Time  : O(n log n)
Space : O(n)

Optimal Approach
Time  : O(n)
Space : O(1)

============================================================
*/

#include<bits/stdc++.h>
using namespace std;

            // Better Approach (Using Map)

// int main() {
//     vector<int> nums = {3, 2, 3};
//     int n = nums.size();
//     map<int, int> mpp;
//     for (auto it : nums) {
//         mpp[it]++;
//     }
    
//     vector<int> ans;
//         for (auto it : mpp) {
//         if (it.second > n / 3) {
//             ans.push_back(it.first);
//         }
//     }

//     for (int x : ans) {
//         cout << x << " ";
//     }

// }

//Optimal Approach (Boyer-Moore Voting Algorithm)

int main(){
    vector<int> nums{3,2,3,2,2,3};
    int n = nums.size();
    int cnt1 = 0;
    int cnt2 = 0;

    int el1 = INT_MIN;
    int el2 = INT_MIN;

    for(int i = 0; i < n; i++){
        if(cnt1 == 0 && nums[i] != el2){
            cnt1++;
            el1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i] != el1){
            cnt2++;
            el2 = nums[i];
        }
        else if(nums[i] == el1){
            cnt1++;
        }
        else if(nums[i] == el2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;

    for(int i = 0; i < n; i++){
        if(nums[i] == el1){
            cnt1++;
        }
        else if(nums[i] == el2){
            cnt2++;
        }
    }

    vector<int> ans;
    int mini = (n/3) + 1;
    if(cnt1 >= mini){
        ans.push_back(el1);
    }
    if(cnt2 >= mini){
        ans.push_back(el2);
    }
    for(int x : ans){
        cout << x << " ";
    }
}