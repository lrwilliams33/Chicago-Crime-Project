#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
// old project
int main() {
    string csvFilePath = "example.csv";

    ifstream csvFile(csvFilePath);
    if (!csvFile.is_open()) {
        cout << "Error opening CSV file." << endl;
        return 1;
    }

    vector<vector<string>> csvData;

    // Read the CSV file line by line
    string line;
    /*
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
    */

    getline(csvFile, line);
    stringstream lineStream(line);
    string cell;
    getline(lineStream, cell, ',');
    cout << cell << endl;

    // Close the CSV file
    csvFile.close();

    return 0;
}
