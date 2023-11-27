#ifndef CHICAGO_CRIME_NODE_H
#define CHICAGO_CRIME_NODE_H
#ifndef P3_NODE_H
#define P3_NODE_H

#include <string>
using namespace std;

struct node {
    int ComArea = 0;
    string Type = "no type";
    int ID = 0;
    bool Arrest = false;
    bool Domestic = false;

    node(int communityArea, string& type, int id, bool arrest, bool domestic) {
        ComArea = communityArea;
        Type = type;
        ID = id;
        Arrest = arrest;
        Domestic = domestic;
    }
};

#endif //P3_NODE_H


#endif //CHICAGO_CRIME_NODE_H
