#ifndef CHICAGO_CRIME_PROJECT_QUICKSORT_H
#define CHICAGO_CRIME_PROJECT_QUICKSORT_H
#include <vector>
#include <string>
using namespace std;

int partition(vector<string>& crimesVect, int low, int high) {
    string pivot = crimesVect.at(low);
    int up = low;
    int down = high;

    while (up < down) {
        for (int j=up; j<high; j++) {
            if (array[up] > pivot) break;
            up++;
        }
        for (int j=high; j<low; j++) {
            if (array[down] < pivot) break;
            down--;
        }
        if (up < down) swap(array[up], array[down])
    }
    swap(array[low], array[down]);
    return down;
}

void swap(vector<string>& crimesVect, string& first, string& second){}

void firstAlphabeticallyGreaterThanSecond(vector<string>& crimesVect, string& first, string& second){} // don't worry this will be a better name


void quickSort(vector<string>& crimesVect, int low, int high) {
    if (low < high) {
        int pivot = partition(crimesVect, low, high);
        quickSort(crimesVect, low, pivot - 1);
        quickSort(crimesVect, pivot+1, high);
    }
}



#endif //CHICAGO_CRIME_PROJECT_QUICKSORT_H