
/*Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N elements.

Output:
Print the inversion count of array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ C ≤ 1018

Example:
Input:
1
5
2 4 1 3 5

Output:
3

Explanation:
Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;


ll a[10000000];
ll counter = 0;
void merge(ll a[], ll p, ll q, ll r){
    ll l = q-p+1;
    ll a1[l];

    ll l2 = r-q;
    // cout << p << " " << r << " " << r << endl;
    // return;
    ll a2[l2];
    
    for(ll i = 0;i<l;i++){
        a1[i] = a[i+p];
    }
    
    for(ll i = 0;i<l2;i++){
        a2[i] = a[q+i+1];
    }
    
    ll left = 0, right = 0, k = p;
    
    while(left < l && right < l2)
    {
        if(a1[left] <= a2[right]){
            a[k] = a1[left];
            left++;
        }
        else{
            a[k] = a2[right];
            right++;
            
            counter += (l-left); // Increementing counter
        }
        k++;
    }
    
    while(left < l){
        a[k++] = a1[left++];
      //  counter++;
    }
    
    while(right < l2){
        // counter++;
        a[k++] = a2[right++];
    }
}

void mergeSort(ll a[], ll p, ll r){
    
    if(p < r)
    {
        ll q = (p+r)/2;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a, p, q, r);
    }
}

int main() {
    
    ll t;
    cin >> t;
    while(t--){
        counter = 0;
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        
        mergeSort(a, 0, n-1);
        cout << counter << endl;
    }
    
    return 0;
}