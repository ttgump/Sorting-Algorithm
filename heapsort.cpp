//
//  main.cpp
//  Heapsort
//
//  Created by Tian Tian on 10/25/14.
//  Copyright (c) 2014 Tian Tian. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
void heapsort(vector<Comparable> & a);

template <typename Comparable>
void percDown(vector<Comparable> & a, int i, int n);

/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline int leftChild(int i)
{
    return 2 * i + 1;
}

/**
 * Standard heapsort.
 */
template <typename Comparable>
void heapsort(vector<Comparable> & a)
{
    for(int i = a.size()/2; i >= 0; i--)
        percDown(a, i, a.size());
    for(int j = a.size() - 1; j > 0; j--)
    {
        swap(a[0], a[j]);
        percDown(a, 0, j);
    }
}

/**
 * Internal method for heapsort that is used in deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void percDown(vector<Comparable> & a, int i, int n)
{
    int child;
    Comparable tmp;
    
    for(tmp = a[i]; leftChild(i) < n; i = child)
    {
        child = leftChild(i);
        if(child != n - 1 && a[child] < a[child + 1])
            child++;
        if(tmp < a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = tmp;
}

/**
 * Test main function
 * randomly generate numbers and use the sorting function to sort
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a;
    int size = 0;
    cin >> size;
    for(int i = 0; i < size; i++) {
        a.push_back(rand() % 1000);
    }
    for(vector<int>::iterator itr = a.begin(); itr != a.end(); ++itr)
        cout << *itr << ", ";
    cout << endl;
    heapsort(a);
    for(vector<int>::iterator itr = a.begin(); itr != a.end(); ++itr)
        cout << *itr << ", ";
    cout << endl;
    return 0;}
