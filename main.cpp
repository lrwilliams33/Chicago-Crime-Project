#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Crime.h"
#include "QuickSort.h"
#include "TimSort.h"

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
        string ID;
        bool Arrest = false;
        bool Domestic = false;

        stringstream lineStream(line);
        string cell;

        getline(lineStream, ID, ','); //get the ID
        getline(lineStream, cell, ','); //get the case number
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
        Crime* c = new Crime(std::stoi(ComArea), Block, std::stoi(ID), Arrest, Domestic);
        data[std::stoi(ComArea)].push_back(c);
    }
    // Close the CSV file
    csvFile.close();
}

/*
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
        //perform sort and dispense time
    }
    else if(sortMethod == "2"){
        cout << "You chose Tim Sort." << endl;
        //perform sort and dispense time
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
        cout << "Enter 1 to search by community area ID. Enter 2 to search by community area name." << endl;
        getline(cin, input);
        if(input == "1"){
            string id;
            cout << "Enter the community area ID." << endl;
            getline(cin, id);
            //print info about community area (see flow chart for what to print)
        } else if(input == "2"){
            string name;
            cout << "Enter the community area name." << endl;
            getline(cin, name);
            //convert to ID for access in data structure
            //print info about community area (see flow chart for what to print)
        } else {
            cout << "You did not enter a valid number." << endl;
            return 2;
        }
    }
    else {
        cout << "You did not enter a valid number." << endl;
        return 2;
    }

    return 0;
}
 */

int main(){
//testing crimes
//    Crime* a = new Crime(45, "123XX Arange ST", 1, true, false);
//    Crime* b = new Crime(45, "056XX Arange ST", 1, true, false);
//    Crime* c = new Crime(45, "456XX AZpple ST", 1, true, false);

    unordered_map<int, vector<Crime*>> data;
    loadData(data);

    vector<Crime*> comArea45 = data[45];
    //vector<Crime*> comArea45 = {a, b, c};

    timSort(comArea45, comArea45.size());

    for(int i = 0; i < comArea45.size(); i++){
        cout << comArea45[i]->Block << endl;

    }

}