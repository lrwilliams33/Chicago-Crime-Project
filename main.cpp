#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
// old project
int main() {
    /*
    string csvFilePath = "../Crimes_-_2020_20231016.csv";

    ifstream csvFile(csvFilePath);
    if (!csvFile.is_open()) {
        cout << "Error opening CSV file." << endl;
        return 1;
    }

    vector<vector<string>> csvData;

    // Read the CSV file line by line
    string line;

    while (getline(csvFile, line)) {
        vector<string> row;
        stringstream lineStream(line);
        string cell;

        // Read each cell in the current row
        while (getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }

        // Add the row to the vector of data
        csvData.push_back(row);
    }

    getline(csvFile, line);
    stringstream lineStream(line);
    string cell;
    getline(lineStream, cell, ',');
    cout << cell << endl;


    // Close the CSV file
    csvFile.close();
     */

    cout << "Welcome!" << endl;
    cout << "Enter 1 to use a B+ tree. Enter 2 to use a Hash Map." << endl;
    string num;
    getline(cin, num);
    if(num == "1"){
        cout << "You chose a B+ tree." << endl;
        //initialize B+ tree here
    }
    else if(num == "2"){
        cout << "You chose a Hash Map." << endl;
        //initialize Hash Map here
    }
    else {
        cout << "You did not enter a valid number." << endl;
        return 2;
    }
    cout << "Enter 1 to list community areas in sorted order by number of crimes." << endl;
    cout << "Enter 2 to search for a specific community area." << endl;
    getline(cin, num);
    if(num == "1"){
        cout << "Enter 1 for ascending order. Enter 2 for descending order." << endl;
        getline(cin, num);
        if(num == "1"){
            //print number of crimes in ascending order (see flow chart for what to print)
        } else if(num == "2"){
            //print number of crimes in descending order (see flow chart for what to print)
        } else {
            cout << "You did not enter a valid number." << endl;
            return 2;
        }
    }
    else if(num == "2"){
        cout << "Enter 1 to search by community area ID. Enter 2 to search by community area name." << endl;
        getline(cin, num);
        if(num == "1"){
            string id;
            cout << "Enter the community area ID." << endl;
            getline(cin, id);
            //print info about community area (see flow chart for what to print)
        } else if(num == "2"){
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
