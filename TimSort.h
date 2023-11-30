#ifndef CHICAGO_CRIME_PROJECT_TIMSORT_H
#define CHICAGO_CRIME_PROJECT_TIMSORT_H
#include "Crime.h"
#include <vector>
using namespace std;

//determine RUN Variable before first iteration of timSort
//vect_size is initial size of vector passed in and is different from the size variable in the second for loop of timeSort

int run = 1; //figure out run variable number afterwards, 1 is just a random number

void insertionSort(vector<Crime*>& crimesVect, int left, int right){
    for (int i = left + 1; i <= right; i++) {
        Crime* temp = crimesVect.at(i);
        int j = i - 1;
        while (j >= left && crimesVect.at(j)->Block.compare(temp->Block) > 0) {
            crimesVect.at(j + 1) = crimesVect.at(j);
            j--;
        }
        crimesVect.at(j + 1) = temp;
    }
}

//mergesort and timsort function are basically done, just have to do insertion sort

void merge(vector<Crime*> &crimesVect, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Crime*> crimes1(crimesVect.size());
    vector<Crime*> crimes2(crimesVect.size());
    for(int i = 0; i < n1; i++){
        crimes1.at(i) = crimesVect.at(left + i);
    }
    for(int j = 0; j < n2; j++){
        crimes2.at(j) = crimesVect.at(mid + 1 + j);
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = left;
    while( i < n1 && j < n2){
        if (crimesVect.at(i)->Block.compare(crimesVect.at(j)->Block) <= 0){  // figure out what we are comparing for Crime Objects, not sure if it is just block
            crimesVect.at(k) = crimes1.at(i);
            i++;
        }
        else{
            crimesVect.at(k) = crimes2.at(j);
            j++;
        }
        k++;
    }
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

void mergeSort(vector<Crime*> &crimesVect, int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(crimesVect, left, mid);
        mergeSort(crimesVect, mid + 1, right);
        merge(crimesVect, left, mid, right);
    }
}

void timSort(vector<Crime*> &crimesVect, int vect_size){
    for (int i = 0; i < crimesVect.size(); i+=run){
        insertionSort(crimesVect, i, min((i + run - 1), (vect_size - 1)));
    }
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
