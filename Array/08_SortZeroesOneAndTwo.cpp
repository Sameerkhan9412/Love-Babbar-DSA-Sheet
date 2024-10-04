//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// ques link->https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int start=0,mid=0,end=arr.size()-1;
        while(mid<=end){
            if(arr[mid]==1){
                mid++;
            }
            else if(arr[mid]==2){
                swap(arr[mid],arr[end]);
                end--;
            }
            else {
                swap(arr[mid],arr[start]);
                start++;
                mid++;
            }
        }
    }
};


// Approach 2:
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int start=0,mid=0,end=arr.size()-1;
        while(mid<=end){
            if(arr[mid]==1){
                mid++;
            }
            else if(arr[end]==2){
                end--;
            }
            else if(arr[mid]==2){
                swap(arr[mid],arr[end]);
                end--;
            }
            else{
                swap(arr[start],arr[mid]);
                start++;
                mid++;
            }
        }
    }
};