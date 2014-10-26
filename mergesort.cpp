//
//  main.cpp
//  MergeSort
//
//  Created by Tian Tian on 10/25/14.
//  Copyright (c) 2014 Tian Tian. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
void mergeSort(vector<Comparable> & a);

template <typename Comparable>
void mergeSort(vector<Comparable> & a,
               vector<Comparable> & tmpArray, int left, int right);
template <typename Comparable>
void merge(vector<Comparable> & a,
           vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd);


/**
 * Mergesort algorithm (driver)
 */
template <typename Comparable>
void mergeSort(vector<Comparable> & a)
{
    vector<Comparable> tmpArray(a.size());
    
    mergeSort(a, tmpArray, 0, a.size()-1);
}

/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most indes of the subarray.
 */
template <typename Comparable>
void mergeSort(vector<Comparable> & a,
               vector<Comparable> & tmpArray, int left, int right)
{
    if(left < right)
    {
        int center = (left + right)/2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center+1, right);
        merge(a, tmpArray, left, center+1, right);
    }
}

/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable>
void merge(vector<Comparable> & a, vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    
    // Main loop
    while(leftPos <= leftEnd && rightPos <= rightEnd)
        if(a[leftPos] <= a[rightPos])
            tmpArray[tmpPos++] = a[leftPos++];
        else
            tmpArray[tmpPos++] = a[rightPos++];
    
    while(leftPos <= leftEnd)       // Copy rest of first half
        tmpArray[tmpPos++] = a[leftPos++];
    
    while(rightPos <= rightEnd)     // Copy rest of second half
        tmpArray[tmpPos++] = a[rightPos++];
    
    // Copy tmpArray back
    for(int i = 0; i < numElements; i++, rightEnd--)
        a[rightEnd] = tmpArray[rightEnd];
}

int main(int argc, const char * argv[]) {
    vector<int> a;
    int size = 0;
    cin >> size;
    for(int i = 0; i < size; i++) {
        a.push_back(rand() % 1000);
    }
    for(vector<int>::iterator itr = a.begin(); itr != a.end(); ++itr)
        cout << *itr << ", ";
    cout << endl;
    mergeSort(a);
    for(vector<int>::iterator itr = a.begin(); itr != a.end(); ++itr)
        cout << *itr << ", ";
    cout << endl;
    return 0;
}
