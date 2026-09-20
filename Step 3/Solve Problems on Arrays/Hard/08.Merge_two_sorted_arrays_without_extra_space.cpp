/*
============================================================
Problem: Merge Sorted Array
Topic: Arrays | Two Pointers
============================================================

Problem Statement:
You are given two sorted integer arrays nums1 and nums2,
and two integers m and n.

Merge nums2 into nums1 as one sorted array.

The first m elements of nums1 are valid.
The last n elements are 0's only to provide extra space.

------------------------------------------------------------
Approaches:

1. Brute Force

- Create a new vector.
- Store the first m elements of nums1.
- Store all elements of nums2.
- Sort the new vector.
- Copy the sorted elements back into nums1.

Time Complexity : O((m+n) log(m+n))
Space Complexity: O(m+n)

------------------------------------------------------------
2. Optimal Approach (Three Pointers)

Idea:

Since nums1 already has enough space,
start filling from the last index.

Algorithm:

1. Initialize:
      i = m-1
      j = n-1
      k = m+n-1

2. Compare nums1[i] and nums2[j].

3. Place the larger element at nums1[k].

4. Move the corresponding pointer.

5. If nums2 still has elements left,
   copy them into nums1.

------------------------------------------------------------
Example:

Input:

nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]

Output:

[1,2,2,3,5,6]

Explanation:

Both arrays are already sorted.
Merge them into nums1 in sorted order.

------------------------------------------------------------
Why Three Pointers?

Starting from the last index avoids
overwriting elements of nums1 that
have not been processed yet.

------------------------------------------------------------
Complexity:

Brute Force
Time  : O((m+n) log(m+n))
Space : O(m+n)

Optimal Approach
Time  : O(m+n)
Space : O(1)

============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach

// int main() {
//     vector<int> nums1 = {1,2,3,0,0,0};
//     vector<int> nums2 = {2,5,6};

//     int m = 3;
//     int n = 3;

//     vector<int> merged;

//     for(int i = 0; i < m; i++) {
//         merged.push_back(nums1[i]);
//     }

//     for(int i = 0; i < n; i++) {
//         merged.push_back(nums2[i]);
//     }

//     sort(merged.begin(), merged.end());

//     for(int i = 0; i < m+n; i++) {
//         nums1[i] = merged[i];
//     }

//     cout << "Merged Array:\n";
//     for(auto x : nums1) {
//         cout << x << " ";
//     }

// }

// Optimal Approach

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    int m = 3;
    int n = 3;

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    cout << "Merged Array:\n";
    for (auto x : nums1)
    {
        cout << x << " ";
    }
}