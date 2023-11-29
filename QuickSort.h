#ifndef CHICAGO_CRIME_PROJECT_QUICKSORT_H
#define CHICAGO_CRIME_PROJECT_QUICKSORT_H
#include <vector>
#include <string>
#include "Crime.h"
using namespace std;

void swap(vector<Crime*>& crimesVect, int first, int second){
    Crime* f = crimesVect.at(first);
    Crime* s = crimesVect.at(second);
    crimesVect.at(first) = s;
    crimesVect.at(second) = f;
}

int partition(vector<Crime*>& crimesVect, int low, int high) {
    string pivot = crimesVect.at(low)->Block;
    int up = low;
    int down = high;

    while (up < down) {
        for (int j=up; j<high; j++) {
            if(crimesVect.at(up)->Block.compare(pivot) > 0)
                break;
            up++;
        }
        for (int j=high; j>low; j--) {
            if(crimesVect.at(down)->Block.compare(pivot) < 0)
                break;
            down--;
        }
        if (up < down) swap(crimesVect, up, down);
    }
    swap(crimesVect, low, down);
    return down;
}

void quickSort(vector<Crime*>& crimesVect, int low, int high) {
    if (low < high) {
        int pivot = partition(crimesVect, low, high);
        quickSort(crimesVect, low, pivot - 1);
        quickSort(crimesVect, pivot+1, high);
    }
}

#endif //CHICAGO_CRIME_PROJECT_QUICKSORT_H