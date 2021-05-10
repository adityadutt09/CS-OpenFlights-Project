#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cerrno>
#include <cstdlib>
#include <stdlib.h>
#include "graph.h"
using namespace std;


int main(){
    
    Graph g(1);
    g.buildAdj();

    string start;
    string end;
    
    cout<<"Enter starting airport (Use 3-Letter Airport code): ";
    cin>>start;

    cout<<"Enter final airport you wish to go to (Use 3-Letter Airport code): ";
    cin>>end;

    g.BFS(start,end);



    
}