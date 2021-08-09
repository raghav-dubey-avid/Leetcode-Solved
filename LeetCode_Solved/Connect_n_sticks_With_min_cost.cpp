/*
    
    Time Complexity: O(nLogn), assuming that we use a O(nLogn) sorting algorithm. 
    Note that heap operations like insert and extract take O(Logn) time.
    
    Auxiliary Complexity: O(n). 
    The space required to store the values in min heap

*/


#include<bits/stdc++.h>
using namespace std;


int minimum_cost(int arr[], int n){
    
    priority_queue<int, vector<int>, greater<int> > priority_Queue(arr, arr+n);
    
    int total_minimum_cost = 0;
    
    while(priority_Queue.size() > 1){
        
        int first_min_rope = priority_Queue.top();
        priority_Queue.pop();
        int second_min_rope = priority_Queue.top();
        priority_Queue.pop();
        
        total_minimum_cost += first_min_rope + second_min_rope;
        priority_Queue.push(first_min_rope + second_min_rope);
    }
    
    return total_minimum_cost;
}

int main(){
    
    int n;
    cin >> n;
    
    int rope_arr[n];
    for(int i = 0; i < n; i++)
        cin >> rope_arr[i];
    
    cout << minimum_cost(rope_arr, n);
    
    return 0;
}