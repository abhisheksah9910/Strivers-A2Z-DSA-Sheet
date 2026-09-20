/*
============================================================
Problem: Merge Intervals
Topic: Arrays | Sorting | Intervals
============================================================

Problem Statement:
Given an array of intervals where intervals[i] = [start, end],
merge all overlapping intervals and return a new array of
non-overlapping intervals that cover all the intervals.

------------------------------------------------------------
Approaches:

1. Brute Force

- Sort the intervals based on their starting time.
- Pick one interval and compare it with the following intervals.
- Merge all overlapping intervals.
- Skip intervals that are already merged.

Time Complexity : O(n²)
Space Complexity: O(n)

------------------------------------------------------------
2. Optimal Approach (Sorting)

Idea:

After sorting the intervals by their starting time,
the current interval can only overlap with the last
merged interval.

Algorithm:

1. Sort all intervals.
2. Traverse each interval.
3. If the answer is empty or there is no overlap,
   add the current interval.
4. Otherwise, merge by updating the ending time:
      end = max(previousEnd, currentEnd)

------------------------------------------------------------
Example:

Input:
intervals = [[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]

Explanation:

[1,3] and [2,6] overlap,
so they are merged into [1,6].

------------------------------------------------------------
Why Sorting?

Sorting ensures that overlapping intervals appear
next to each other, allowing us to merge them in
a single traversal.

------------------------------------------------------------
Complexity:

Brute Force
Time  : O(n²)
Space : O(n)

Optimal Approach
Time  : O(n log n)
Space : O(n)

============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach

// int main() {
//     vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
//     int n = arr.size();
//     sort(arr.begin(), arr.end());

//     vector<vector<int>> ans;

//     for(int i = 0; i < n; i++) {
//         int start = arr[i][0];
//         int end = arr[i][1];
//         if(!ans.empty() && end <= ans.back()[1]) {
//             continue;
//         }
//         for(int j = i + 1; j < n; j++) {
//             if(arr[j][0] <= end) {
//                 end = max(end, arr[j][1]);
//             } else {
//                 break;
//             }
//         }
//         ans.push_back({start, end});
//     }
//     cout << "Merged Intervals:\n";
//     for(auto &interval : ans) {
//         cout << "[" << interval[0] << ", " << interval[1] << "] ";
//     }
//     return 0;
// }


            //optimal
int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for(auto &interval : intervals) {

        if(ans.empty() || ans.back()[1] < interval[0]) {
            ans.push_back(interval);
        }
        else {
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }

    cout << "Merged Intervals:\n";
    for(auto &interval : ans) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}