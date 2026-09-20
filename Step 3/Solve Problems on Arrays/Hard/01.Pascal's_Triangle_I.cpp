// 1. Find a Single Element
//    - Using nCr formula
//    - Formula: C(n-1, r-1)

// 2. Print a Particular Row
//    - Generate row using previous element
//    - Formula:
//      next = previous * (row - col) / col

// 3. Print Complete Pascal's Triangle
//    - Generate each row without factorials
//    - Uses nCr relation for O(1) computation of next element

// ------------------------------------------------------------
// Approach:
// Instead of calculating factorials repeatedly,
// use the relation:

// C(n, r) = C(n, r-1) * (n-r+1) / r

// This avoids overflow (to some extent) and reduces
// time complexity.

// Time Complexity:
// 1. Single Element      : O(r)
// 2. Particular Row      : O(n)
// 3. Complete Triangle   : O(n²)




#include<bits/stdc++.h>
using namespace std;
            //a single element of Pascal's Triangle using the factorial formula

// int main(){
//     int row,col;
//     cin>>row>>col;
//     int n=1;
//     int r=1;
//     int diff=1;

//     for(int i=1;i<row;i++){
//         n=n*i;
//     }
//     for(int i=1;i<col;i++){
//         r=r*i;
//     }
//     for(int i=1;i<=(row-col);i++){
//         diff= diff*i;
//     }
//     cout<<n/(r*diff);

// }

            // Find a Single Element

// int main(){
//     int row,col;
//     cin>>row>>col;
//     int n=row-1;
//     int r=col-1;
//     long long res=1;
//     for(int i=0;i<r;i++){
//         res= res*(n-i);
//         res = res / (i+1);
//     }
//     cout<<res;
// }


            // Print a Particular Row

// int main(){
//     int row;
//     cin>>row;
//     row--;

//     int ans=1;
//     cout<<ans<<" ";
//     for(int i=1;i<=row;i++){
//         ans = ans*(row-i+1);
//         ans= ans/i;
//         cout<<ans<<" ";
//     }
// }

            // Print Complete Pascal Triangle

int main(){
    int n;
    cin>>n;
    for(int row=1;row<n;row++){
        long long ans=1;
        cout<<ans<<" ";
        for(int col =1;col<row;col++){
            ans = ans*(row-col);
            ans =  ans/col;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}