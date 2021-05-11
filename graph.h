#pragma once

/** File for creating and storing the routes and connections.
 * Graph storing nodes as the places - airports/locations.
 * Edges are the routes between them.
 * Weights of each edge is the distance between two places.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <cmath>
#include <fstream>
#include <sstream>
#include <float.h>
#include <queue>

//Public Data Structure to store the data of each node
struct Node{
    std::string name;
    double latitude;
    double longitude;

};

class Graph{
    
    public:

        /** Function to build the adjacency list
         * @param an unordered map that stores the latitude and longitude of each airport/location
         */ 
        void buildAdj(std::unordered_map< std::string, std::pair<double, double> > coords);

        /** Function to find the coordinates (latitude, longitude) of each airport.
         * @param airports - entries of each airport - Key, Latitude, Longitude - stored as a vector.
         */
        void _findCoords(std::vector<std::string> airports);

        /** Function to insert a vertex into the graph
         */ 
        void insertVertex(Node & n);

        /** Function to insert all edges into the graph.
         * @param routes - entries of the routes connecting two airports/locations.
         */ 
        void insertEdges(std::vector<std::string> routes);
        
        /** Function to implement a Breadth-First-Search Traversal on the Graph
         * @param start - Key to the starting node
         * @param end - Key to the last node to be traversed
         * @return Vector of nodes traversed through BFS
         */ 
        std::vector<std::string> BFS(std::string start, std::string end);

        /** Function to print the BFS Traversal implemented
         * @param start - Key to starting node
         * @param end - Key to last node
         */ 
        void printBFS(std::string start, std::string end);

        /** Function to print the Graph including its nodes and edges
         * @param graph - Takes in the graph to be printed
         */ 
        void printGraph(Graph const & graph);
       
        /** Function to implement Dijkstra's algorithm on the Graph
         * @param start - Key to starting node
         * @param end - Key to last node
         * @return a vector containing the path of traversal
         */ 
        std::vector<std::string> Dijkstra(std::string start, std::string end);
        
        /** Function to print Dijkstra's algorithm
         * @param start - Key to starting node
         * @param end - Key to last node
         */ 
        void printDijkstra(std::string start, std::string end);
        
        /** Function to implement the Landmark Path algorithm on the graph
         * @param start - Key to starting node
         * @param connection - Key to connecting node in the path
         * @param end - Key to last node
         * @return a vector containing the path of traversal
         */ 
        std::vector<std::string> Landmark(std::string start, std::string connection, std::string end);

        /** Function to print the Landmark Path algorithm
         * @param start - Key to starting node
         * @param end - Key to last node
         */  
        void printLandmark(std::string start, std::string connection, std::string end);

    private:

        //Private Data Structure to store the data contained in the edges
        struct Edge{
            std::string prev;
            std::string dest;
        };

        //Storing the vertices
        std::vector<Node> vertices;

        //Storing the edges
        std::vector<Edge> edges;

        /** Storing edges and their weights using an adjacency list
         * Key - Current city location
         * Mapped to - Destination city and distance from current city
        */
        std::unordered_map< std::string, std::list< std::pair<std::string, double> >> adj;

        //Helper function to calculate weights as distance of separation
        double _calcWeight(double lat1, double lon1, double lat2, double lon2);

        //Helper function to calculate the minimum distance between two airports/locations
        std::string minimum(std::unordered_map< std::string, double > dist, std::unordered_map< std::string, bool > shortest);

};
