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

    // get csvFile
    string csvFilePath = "../Crimes_-_2020_20231016.csv";
    ifstream csvFile(csvFilePath);
    if (!csvFile.is_open()) {
        cout << "Error opening CSV file." << endl;
        return;
    }

    string line;
    // get the header line
    getline(csvFile, line);
    // iterates over each line in the csv file
    while (getline(csvFile, line)) {
        string ComArea;
        string Block;
        string CaseNum;
        bool Arrest = false;
        bool Domestic = false;

        // convert line into stringstream to read from
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

// main driver
int main() {
    // create and load data set in the form of a map
    // key is integer representation of community area, value is a list of data points (crimes) in that community area
    unordered_map<int, vector<Crime*>> data;
    loadData(data);

    cout << "Welcome! Follow the instructions below to find out more information about the crime in different community areas of Chicago." << endl;
    cout << "This information is based on data from 2020." << endl << endl;
    cout << "Enter 1 to use Quick Sort. Enter 2 to use Tim Sort" << endl;
    string sortMethod;
    getline(cin, sortMethod);
    if(sortMethod == "1"){
        cout << "You chose Quick Sort." << endl;
        // use chrono library to time the quickSort algorithm and display time in milliseconds
        auto start = chrono::high_resolution_clock::now();
        // call quickSort on each community area of the data to sort the crimes in that community area by Block
        for(int i = 1; i < 78; i++){
            quickSort(data[i], 0, data[i].size()-1);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
    else if(sortMethod == "2"){
        cout << "You chose Tim Sort." << endl;
        // use chrono library to time the quickSort algorithm and display time in milliseconds
        auto start = chrono::high_resolution_clock::now();
        // call timSort on each community area of the data to sort the crimes in that community area by Block
        for(int i = 1; i < 78; i++){
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

    cout << "Enter 1 to list community areas with the most or least crimes." << endl;
    cout << "Enter 2 to search for a specific community area." << endl;
    string input;
    getline(cin, input);
    // user wants to list community areas with the most or least crimes
    if(input == "1"){
        cout << "Enter 1 for the 3 community areas with the most crimes. Enter 2 for the 3 community areas with the least crimes." << endl;
        getline(cin, input);
        if(input == "1"){
            // get the 3 community areas with the largest vectors = most number of crimes
            vector<Crime*> max1 = data[1];
            vector<Crime*> max2 = data[1];
            vector<Crime*> max3 = data[1];
            for(int i = 2; i <= 77; i++){
                vector<Crime*> curr = data[i];
                if(curr.size() > max1.size()){
                    max3 = max2;
                    max2 = max1;
                    max1 = curr;
                } else if(curr.size() > max2.size()){
                    max3 = max2;
                    max2 = curr;
                } else if(curr.size() > max3.size()){
                    max3 = curr;
                }
            }
            cout << "1. #" << max1[0]->ComArea << " - Number of Crimes: " << max1.size() << endl;
            cout << "2. #" << max2[0]->ComArea << " - Number of Crimes: " << max2.size() << endl;
            cout << "3. #" << max3[0]->ComArea << " - Number of Crimes: " << max3.size() << endl;

        } else if(input == "2"){
            // get the 3 community areas with the smallest vectors = least number of crimes
            vector<Crime*> min1 = data[1];
            vector<Crime*> min2 = data[1];
            vector<Crime*> min3 = data[1];
            for(int i = 2; i <= 77; i++){
                vector<Crime*> curr = data[i];
                if(curr.size() < min1.size()){
                    min3 = min2;
                    min2 = min1;
                    min1 = curr;
                } else if(curr.size() < min2.size()){
                    min3 = min2;
                    min2 = curr;
                } else if(curr.size() < min3.size()){
                    min3 = curr;
                }
            }
            cout << "1. #" << min1[0]->ComArea << " - Number of Crimes: " << min1.size() << endl;
            cout << "2. #" << min2[0]->ComArea << " - Number of Crimes: " << min2.size() << endl;
            cout << "3. #" << min3[0]->ComArea << " - Number of Crimes: " << min3.size() << endl;

        } else {
            cout << "You did not enter a valid number." << endl;
            return 2;
        }
        cout << "Find more information on community areas here:" << endl;
        cout << "https://www.chicago.gov/content/dam/city/depts/doit/general/GIS/Chicago_Maps/Citywide_Maps/Community_Areas_W_Numbers.pdf" << endl;

    }
    // user wants to search for a specific community areas
    else if(input == "2"){
        string idStr;
        cout << "Enter the community area number:";
        getline(cin, idStr);
        int id = stoi(idStr);
        // data validation to make sure is valid community area number [1, 77]
        if(id >= 0 && id <= 77){
            vector<Crime*> ComAreaCrimes = data[id];
            for(Crime* c : ComAreaCrimes){
                // display the Block, Case Number, and whether it was Domestic and resulted in Arrest
                // printing sorted by Block alphabetically from previous sorting method
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
            // print the total number of crimes in that community area at the end
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