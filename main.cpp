#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Crime.h"
#include "QuickSort.h"
#include "TimSort.h"
#include <chrono>

using namespace std;

// load the data set into the map object
void loadData(unordered_map<int, vector<Crime*>>& data){

    string csvFilePath = "../Crimes_-_2020_20231016.csv";
    ifstream csvFile(csvFilePath);
    if (!csvFile.is_open()) {
        cout << "Error opening CSV file." << endl;
        return;
    }

    string line;
    //get the header line
    getline(csvFile, line);
    while (getline(csvFile, line)) {
        string ComArea;
        string Block;
        string CaseNum;
        bool Arrest = false;
        bool Domestic = false;

        stringstream lineStream(line);
        string cell;

        getline(lineStream, cell, ','); //get the ID
        getline(lineStream, CaseNum, ','); //get the case number
        getline(lineStream, cell, ','); //get the date
        getline(lineStream, cell, ','); //get the block
        Block = cell.substr(8);
        getline(lineStream, cell, ','); //get the IUCR
        getline(lineStream, cell, ','); //get the Primary Type
        getline(lineStream, cell, ','); //get the Description
        getline(lineStream, cell, ','); //get the Location
        getline(lineStream, cell, ','); //get the Arrest
        if(cell == "TRUE"){
            Arrest = true;
        }
        getline(lineStream, cell, ','); //get the Domestic
        if(cell == "TRUE"){
            Domestic = true;
        }
        getline(lineStream, cell, ','); //get the Beat
        getline(lineStream, cell, ','); //get the District
        getline(lineStream, cell, ','); //get the Ward
        getline(lineStream, ComArea, ','); //get the Community Area
        Crime* c = new Crime(std::stoi(ComArea), Block, CaseNum, Arrest, Domestic);
        data[std::stoi(ComArea)].push_back(c);
    }
    // Close the CSV file
    csvFile.close();
}

int main() {

    // create and load data set in the form of a map
    // key is integer representation of community area; value is a list of data points (crimes) in that community area
    unordered_map<int, vector<Crime*>> data;
    loadData(data);

    cout << "Welcome!" << endl;
    cout << "Enter 1 to use Quick Sort. Enter 2 to use Tim Sort" << endl;
    string sortMethod;
    getline(cin, sortMethod);
    if(sortMethod == "1"){
        cout << "You chose Quick Sort." << endl;
        auto start = chrono::high_resolution_clock::now();
        for(int i = 0; i < 78; i++){
            quickSort(data[i], 0, data[i].size()-1);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
    else if(sortMethod == "2"){
        cout << "You chose Tim Sort." << endl;
        auto start = chrono::high_resolution_clock::now();
        for(int i = 0; i < 78; i++){
            timSort(data[i], data[i].size());
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
    else {
        cout << "You did not enter a valid number." << endl;
        return 2;
    }

    cout << "Enter 1 to list community areas in sorted order by number of crimes." << endl;
    cout << "Enter 2 to search for a specific community area." << endl;
    string input;
    getline(cin, input);
    if(input == "1"){
        cout << "Enter 1 for ascending order. Enter 2 for descending order." << endl;
        getline(cin, input);
        if(input == "1"){
            //print number of crimes in ascending order (see flow chart for what to print)
        } else if(input == "2"){
            //print number of crimes in descending order (see flow chart for what to print)
        } else {
            cout << "You did not enter a valid number." << endl;
            return 2;
        }
    }
    else if(input == "2"){
        string idStr;
        cout << "Enter the community area number:";
        getline(cin, idStr);
        int id = stoi(idStr);
        if(id >= 0 && id <= 77){
            vector<Crime*> ComAreaCrimes = data[id];
            for(Crime* c : ComAreaCrimes){
                cout << c->Block << " - Case Number: " << c->CaseNumber << ", Arrest: ";
                if(c->Arrest)
                    cout << "Yes";
                else
                    cout << "No";
                cout << ", Domestic: ";
                if(c->Domestic)
                    cout << "Yes";
                else
                    cout << "No";
                cout << endl;
            }
            cout << "-----" << endl << "Total crimes in community area " << id << ": " << ComAreaCrimes.size() << endl;
        } else {
            cout
                    << "You didn't enter a valid community area number. See this link for more information about the community areas of Chicago: "
                    << endl
                    << "https://www.chicago.gov/content/dam/city/depts/doit/general/GIS/Chicago_Maps/Citywide_Maps/Community_Areas_W_Numbers.pdf"
                    << endl;
            return 2;
        }
    }
    else {
        cout << "You did not enter a valid number." << endl;
        return 2;
    }

    return 0;
}