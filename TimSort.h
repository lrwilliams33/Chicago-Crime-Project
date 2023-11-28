#ifndef CHICAGO_CRIME_PROJECT_TIMSORT_H
#define CHICAGO_CRIME_PROJECT_TIMSORT_H
#include "Crime.h"
#include <vector>
using namespace std;

//determine RUN Variable before first iteration of timSort
//vect_size is initial size of vector passed in and is different from the size variable in the second for loop of timeSort

int run = 1; //figure out run variable number afterwards, 1 is just a random number

void insertionSort(parameters)
void merge(parameters)

void timSort(vector<Crime> &crimesVect, int vect_size){
    for (int i = 0; i < crimesVect.size(); i+=run){
        //insertionSort(arr, i, min((i + run - 1), (vect_size - 1)));
    }
    for (int size = run; size < vect_size; size = 2 * size){
        for (int left = 0; left < vect_size; left += 2 * size){
            int right = min((left + 2 * size - 1), (vect_size - 1));
            int mid = left + size - 1;
            if (mid < right){
                //merge(arr, left, mid, right);
            }
        }
    }
}

#endif //CHICAGO_CRIME_PROJECT_TIMSORT_H
