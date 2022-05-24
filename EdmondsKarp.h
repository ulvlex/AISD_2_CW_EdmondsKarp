#pragma once
#include "Queue.h"

using namespace std;

int EdmodsKarp(int cntVertexes, int cntEdge, int source, int sink, int** capacities) {
    int maxFlow = 0;

    while (true) {

        //BFS
        int* parentsList = new int[cntVertexes];
        bool* used = new bool[cntVertexes];

        for (int i = 0; i < cntVertexes; i++) {
            parentsList[i] = -1;
            used[i] = false;
        }

        queue<int> q;

        used[source] = true;
        q.push(source);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int i = 0; i < cntVertexes; i++) {
                if (!used[i] && capacities[v][i] > 0) {
                    parentsList[i] = v;
                    used[i] = true;
                    q.push(i);
                }
            }
        }

        if (!used[sink]) break;

        //main algorithm
        int augFlow = INT_MAX;

        int ptr = sink;

        while (ptr != source) {
            if (augFlow < capacities[parentsList[ptr]][ptr])
                augFlow = augFlow;
            else augFlow = capacities[parentsList[ptr]][ptr];
            ptr = parentsList[ptr];
        }

        ptr = sink;
        while (ptr != source) {
            capacities[parentsList[ptr]][ptr] -= augFlow;//По пути вычитаем
            capacities[ptr][parentsList[ptr]] += augFlow;//Против пути добавляем
            ptr = parentsList[ptr];
        }

        maxFlow += augFlow;
    }

    return maxFlow;
}