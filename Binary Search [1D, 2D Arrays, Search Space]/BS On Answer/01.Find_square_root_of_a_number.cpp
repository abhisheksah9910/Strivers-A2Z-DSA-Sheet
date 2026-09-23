#include<bits/stdc++.h>
using namespace std;
// int main(){
//     int num=25;
//     int ans=1;
//     for(int i=1;i<=25;i++){
//         if(i*i<=num){
//             ans=i;
//         }else{
//             break;
//         }
//     }
//     cout<<"Square root of given number is "<<ans;
// }

//using Binary search

int main() {

    int num = 25;
    int low = 1;
    int high = num;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (mid * mid > num) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << "Square root: " << high;

    return 0;
}