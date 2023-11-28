#ifndef CHICAGO_CRIME_NODE_H
#define CHICAGO_CRIME_NODE_H
#ifndef P3_NODE_H
#define P3_NODE_H

#include <string>
using namespace std;

struct Crime {
    int ComArea = 0;
    string Block = "";
    int ID = 0;
    bool Arrest = false;
    bool Domestic = false;

    Crime(int communityArea, string& block, int id, bool arrest, bool domestic) {
        ComArea = communityArea;
        Block = block;
        ID = id;
        Arrest = arrest;
        Domestic = domestic;
    }
};

#endif //P3_NODE_H
#endif //CHICAGO_CRIME_NODE_H
