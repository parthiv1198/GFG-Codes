/*
Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 108

Example:
Input:
2
1
1
5
1 3 5 2 2

Output:
1
3

Explanation:
Testcase 1: Since its the only element hence its the only equilibrium point.
Testcase 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements after it (2+2).

*/


#include <bits/stdc++.h>
using namespace std;

long long a[1000000];
long long pre[1000000];
int main() {

    long long t;
    cin >> t;
    
    while(t--){
        long long n;
        cin >> n;
        
       
        long long sum = 0;
        for(long long i = 0;i<n;i++){
            cin >> a[i];
            sum+=a[i];
            pre[i] = sum;
        }
        
        long long sum2 = 0, ans = -1;
        
        for(long long i = n-1;i>=0;i--){
            sum2 += a[i];
            if(sum2 == pre[i]){
                ans = i+1;
            }
        }
       
        
        if(ans == 0){
            cout << "-1"<< endl;
        }
        else cout << ans << endl;
    }
    return 0;
}