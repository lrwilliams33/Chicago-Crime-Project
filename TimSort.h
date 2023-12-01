#ifndef CHICAGO_CRIME_PROJECT_TIMSORT_H
#define CHICAGO_CRIME_PROJECT_TIMSORT_H
#include "Crime.h"
#include <vector>
using namespace std;

// insertion sort helper function
void insertionSort(vector<Crime*>& crimesVect, int left, int right){
    for (int i = left + 1; i <= right; i++) {
        Crime* temp = crimesVect.at(i);
        int j = i - 1;
        // continually move elements greater than temp up 1 space
        while (j >= left && crimesVect.at(j)->Block.compare(temp->Block) > 0) {
            crimesVect.at(j + 1) = crimesVect.at(j);
            j--;
        }
        crimesVect.at(j + 1) = temp;
    }
}

// merge helper function (like merge sort merge function)
void merge(vector<Crime*> &crimesVect, int left, int mid, int right){
    // defining and populate both sub arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Crime*> crimes1(n1);
    vector<Crime*> crimes2(n2);
    for(int i = 0; i < n1; i++){
        crimes1.at(i) = crimesVect.at(left + i);
    }
    for(int j = 0; j < n2; j++){
        crimes2.at(j) = crimesVect.at(mid + 1 + j);
    }
    // merging the two sub arrays back together in the appropriate order
    int i, j, k;
    i = 0;
    j = 0;
    k = left;
    while( i < n1 && j < n2){
        if (crimes1.at(i)->Block.compare(crimes2.at(j)->Block) <= 0){
            crimesVect.at(k) = crimes1.at(i);
            i++;
        }
        else{
            crimesVect.at(k) = crimes2.at(j);
            j++;
        }
        k++;
    }
    // get any remaining elements in either sub array
    while(i < n1){
        crimesVect.at(k) = crimes1.at(i);
        i++;
        k++;
    }
    while(j < n2){
        crimesVect.at(k) = crimes2.at(j);
        j++;
        k++;
    }
}

// main timSort function
void timSort(vector<Crime*> &crimesVect, int vect_size){
    // run variable changes influences speed of the sorting algorithm - was chose based on testing
    int run = 32;
    // call insertion sort on sub arrays of size run
    for (int i = 0; i < vect_size; i+=run){
        insertionSort(crimesVect, i, min((i + run - 1), (vect_size - 1)));
    }
    // merge all those sorted sub arrays of size run together using the merge function
    for (int size = run; size < vect_size; size = 2 * size){
        for (int left = 0; left < vect_size; left += 2 * size){
            int right = min((left + 2 * size - 1), (vect_size - 1));
            int mid = left + size - 1;
            if (mid < right){
                merge(crimesVect, left, mid, right);
            }
        }
    }
}

#endif //CHICAGO_CRIME_PROJECT_TIMSORT_H
