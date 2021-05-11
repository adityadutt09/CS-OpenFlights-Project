#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cerrno>
#include <cstdlib>
#include <stdlib.h>
#include "Read_file.hpp"
#include "Write_file.hpp"
#include "graph.h"
using namespace std;


int main(){

    Graph g;
    
    string originalRoute = file_to_string("routes.csv");
	vector<string> routes_vector = string_to_vector(originalRoute, 6);
	writeToRoutes(routes_vector);

    string originalAirport = file_to_string("airports.csv");
    vector<string> airport_vector = string_to_vector(originalAirport, 8);
    writeToAirports(airport_vector);
    
    string finalroutes = file_to_string("final_routes.csv");
	vector<string> routes;

    int begin = 0;
    int end = 0;
    
    for (unsigned i = 0; i < finalroutes.length(); ++i) {     
        if (finalroutes[(int)i] == '\n') {
            end = (int)i;
            routes.push_back(finalroutes.substr(begin, end - begin));
            begin = ((int)i + 1);
        }
    }

    //Finds all edges that have a route and stores it in the graph
    g.insertEdges(routes);
    
    string finalairports = file_to_string("final_airports.csv");
	vector<string> airports;

    begin = 0;
    end = 0;

    for (unsigned i = 0; i < finalairports.length(); ++i) {     
        if (finalairports[(int)i] == '\n') {
            end = (int)i;
            airports.push_back(finalairports.substr(begin, end - begin));
            begin = ((int)i + 1);
        }
    }
    
    //Finds the coordinates for each airport and builds the adjacency list
    g._findCoords(airports);
    
    string start;
    string finish;
    
    cout<<"Enter starting airport (Use 3-Letter Airport code): ";
    cin>>start;

    cout<<"Enter final airport you wish to go to (Use 3-Letter Airport code): ";
    cin>>finish;

    g.BFS(start, finish);
    
    //g.printDijkstra(start,finish);
    
}