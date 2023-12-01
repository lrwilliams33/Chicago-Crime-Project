#ifndef CHICAGO_CRIME_NODE_H
#define CHICAGO_CRIME_NODE_H
#ifndef P3_NODE_H
#define P3_NODE_H

#include <string>
using namespace std;

// Crime Object consists of a community area number (ComArea), a street (Block), a crime case number (CaseNumber),
// an Arrest boolean for if the crime resulted in arrest, and a Domestic boolean for if the crime was domestic
struct Crime {
    int ComArea = 0;
    string Block = "";
    string CaseNumber = "";
    bool Arrest = false;
    bool Domestic = false;

    // constructor
    Crime(int communityArea, string block, string caseNumber, bool arrest, bool domestic) {
        ComArea = communityArea;
        Block = block;
        // this makes sure the Block string is all uppercase for consistency and sorting
        for (int i = 0; i < Block.length(); i++) {
            Block[i] = std::toupper(Block[i]);
        }
        CaseNumber = caseNumber;
        Arrest = arrest;
        Domestic = domestic;
    }

    // copy constructor
    Crime(Crime &c){
        ComArea = c.ComArea;
        Block = c.Block;
        CaseNumber = c.CaseNumber;
        Arrest = c.Arrest;
        Domestic = c.Domestic;
    }

    // copy assignment operator
    void operator=(const Crime& c){
        ComArea = c.ComArea;
        Block = c.Block;
        CaseNumber = c.CaseNumber;
        Arrest = c.Arrest;
        Domestic = c.Domestic;
    }
};

#endif //P3_NODE_H
#endif //CHICAGO_CRIME_NODE_H
