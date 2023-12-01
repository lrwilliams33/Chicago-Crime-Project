#ifndef CHICAGO_CRIME_PROJECT_QUICKSORT_H
#define CHICAGO_CRIME_PROJECT_QUICKSORT_H
#include <vector>
#include <string>
#include "Crime.h"
using namespace std;

// function for swapping the crime objects at indices first and second
void swap(vector<Crime*>& crimesVect, int first, int second){
    Crime* f = crimesVect.at(first);
    Crime* s = crimesVect.at(second);
    crimesVect.at(first) = s;
    crimesVect.at(second) = f;
}

// partition function
int partition(vector<Crime*>& crimesVect, int low, int high) {
    // select pivot element (string because it is a block)
    string pivot = crimesVect.at(low)->Block;
    int up = low;
    int down = high;

    // repeat until up and down are at the same index
    while (up < down) {
        for (int j=up; j<high; j++) {
            // if Block string at up is greater than pivot Block
            if(crimesVect.at(up)->Block.compare(pivot) > 0)
                break;
            up++;
        }
        for (int j=high; j>low; j--) {
            // if Block string at down is less than pivot Block
            if(crimesVect.at(down)->Block.compare(pivot) < 0)
                break;
            down--;
        }
        // if up is less than down, use swap function to swap crime objects at index up and index down
        if (up < down)
            swap(crimesVect, up, down);
    }
    swap(crimesVect, low, down);
    return down;
}

// main insertion sort function - finds pivot index with partition function and recursively calls quickSort
void quickSort(vector<Crime*>& crimesVect, int low, int high) {
    if (low < high) {
        int pivot = partition(crimesVect, low, high);
        quickSort(crimesVect, low, pivot - 1);
        quickSort(crimesVect, pivot+1, high);
    }
}

#endif //CHICAGO_CRIME_PROJECT_QUICKSORT_H