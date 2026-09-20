/*
============================================================
Problem: Count Subarrays with Given XOR K
Topic: Arrays | Prefix XOR | Hash Map
============================================================

Problem Statement:
Given an array of integers and an integer K,
find the total number of subarrays whose XOR
is equal to K.

------------------------------------------------------------
Approaches:

1. Brute Force

- Generate every possible subarray.
- Compute the XOR of each subarray.
- Increment the count whenever XOR == K.

Time Complexity : O(n²)
Space Complexity: O(1)

------------------------------------------------------------
2. Optimal Approach (Prefix XOR + Hash Map)

Idea:

Maintain the prefix XOR while traversing the array.

Let:

prefixXOR = XOR of elements from index 0 to i

For a subarray to have XOR = K,

prefixXOR ^ previousPrefixXOR = K

Therefore,

previousPrefixXOR = prefixXOR ^ K

If (prefixXOR ^ K) has already appeared,
then every occurrence represents one valid subarray.

Use a Hash Map to store the frequency of each
prefix XOR.

------------------------------------------------------------
Algorithm:

1. Initialize:
   prefixXOR = 0
   count = 0
   HashMap<xorValue, frequency>

2. Store:
   mp[0] = 1
   (Represents an empty prefix before the array.)

3. Traverse the array:
   - Update prefix XOR.
   - Compute required XOR:
       required = prefixXOR ^ K
   - Add frequency of required to answer.
   - Store/update current prefix XOR.

------------------------------------------------------------
Example:

Input:
arr = [4,2,2,6,4]
K = 6

Output:
4

Subarrays:
[4,2]
[2,2,6]
[6]
[4,2,2,6,4]

------------------------------------------------------------
Why Prefix XOR?

If

prefixXOR(i) ^ prefixXOR(j) = K

then

XOR(i+1 ... j) = K

This property allows us to solve the problem
in a single traversal using a Hash Map.

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

// int main(){
//     vector<int> arr{4,2,2,6,4};
//     int k=6;
//     int count=0;
//     for(int i=0;i<arr.size();i++){
//         int xorr=0;
//         for(int j=i;j<arr.size();j++){
//             xorr ^= arr[j];
//             if(xorr==k){
//                 count++;
//             }
//         }
//     }
//     cout<<count;
// }


            //optimal 
int main() {
    vector<int> arr = {4,2,2,6,4};
    int k = 6;

    unordered_map<int,int> mp;
    mp[0] = 1;      // Prefix XOR = 0 before array starts

    int xr = 0;
    int count = 0;

    for(int i = 0; i < arr.size(); i++) {
        xr ^= arr[i];
        int x = xr ^ k;
       if(mp.find(x) != mp.end()) {
            count += mp[x];
        }
        mp[xr]++;
    }
    cout << count;
}