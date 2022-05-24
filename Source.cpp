#include<string>
#include <iostream>
#include<fstream>
#include "Queue.h"
#include "EdmondsKarp.h"

using namespace std;

string fileName = "text.txt";

int main()
{
    string oneLine = "";

    char from, to;

    int capacity = 0;
    int cntEdge = 0;
    int cntVertexes = 0;
    string vertexes = "";
    bool first;
    bool second;

    ifstream file_input;
    file_input.open(fileName);

    //count the number of vertices and edges, 
    //and also assign their indexes to the symbols and create a new file
    while (!file_input.eof()) {
        getline(file_input, oneLine);
        cout << oneLine << endl;
        first = false;
        second = false;
        from = oneLine[0];
        to = oneLine[1];
        if (vertexes == "") {
            vertexes += oneLine.substr(0, 2);
        }
        else {
            for (int i = 0; i < vertexes.size(); i++) {
                if (vertexes[i] == from) first = true;
                if (vertexes[i] == to) second = true;
            }
            if (!first) vertexes += from;
            if (!second) vertexes += to;
        }
        cntEdge++;
    }
    cntVertexes = vertexes.size();
    file_input.close();


    int** capacities = new int* [cntEdge];
    for (int i = 0; i < cntEdge; i++) 
        capacities[i] = new int[cntEdge];

    for (int i = 0; i < cntEdge; i++)
        for (int j = 0; j < cntEdge; j++)
            capacities[i][j] = 0;

    for (int i = 0; i < cntEdge; i++) {
        for (int j = 0; j < cntEdge; j++)
            capacities[i][j] = 0;
    }

    file_input.open(fileName);

    int indexA = 0;
    int indexB = 0;
    int source, sink;
    int index = 0;

    while (!file_input.eof()) {
        getline(file_input, oneLine);
        from = oneLine[0];
        to = oneLine[1];

        for (int i = 0; i < vertexes.size(); i++) {
            if (vertexes[i] == from) indexA = i;
            if (vertexes[i] == to) indexB = i;
            if (vertexes[i] == 'S') source = i;
            if (vertexes[i] == 'T') sink = i;
        }

        capacity = oneLine[2] - '0';
        capacities[indexA][indexB] = capacity;
    }

    int maxFlow = EdmodsKarp(cntVertexes, cntEdge, source, sink, capacities);

    cout << endl << endl << "Max Flow is:" << maxFlow << endl;
}