//
//  main.cpp
//  BucketSort
//
//  Created by Tian Tian on 10/25/14.
//  Copyright (c) 2014 Tian Tian. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to sort arr[] of size n using bucket sort
template <typename Comparable>
void bucketSort(vector<Comparable> & arr)
{
    int n = arr.size();
    
    // 1) Create n empty buckets
    vector<vector<Comparable>> b(n);
    
    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
        int bi = n*arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }
    
    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
        sort(b[i].begin(), b[i].end());
    
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main(int argc, const char * argv[]) {
    float input = 0;
    vector<float> arr;
    while(true) {
        cin >> input;
        if(input == 0) break;
        arr.push_back(input);
    }
    
    bucketSort(arr);
    
    cout << "Sorted array is \n";
    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
