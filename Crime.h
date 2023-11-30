#ifndef CHICAGO_CRIME_NODE_H
#define CHICAGO_CRIME_NODE_H
#ifndef P3_NODE_H
#define P3_NODE_H

#include <string>
using namespace std;

struct Crime {
    int ComArea = 0;
    string Block = "";
    string CaseNumber = "";
    bool Arrest = false;
    bool Domestic = false;

    Crime(int communityArea, string block, string caseNumber, bool arrest, bool domestic) {
        ComArea = communityArea;
        Block = block;
        for (int i = 0; i < Block.length(); i++) {
            Block[i] = std::toupper(Block[i]);
        }
        CaseNumber = caseNumber;
        Arrest = arrest;
        Domestic = domestic;
    }

    Crime(Crime &c){
        ComArea = c.ComArea;
        Block = c.Block;
        CaseNumber = c.CaseNumber;
        Arrest = c.Arrest;
        Domestic = c.Domestic;
    }

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
