/** File for creating and storing the routes and connections.
 * Graph storing nodes as the places
 * Edges are the routes between them
 * Weights of each edge is the time difference between two places
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <cmath>
#include <fstream>
#include <sstream>


struct Node{
    std::string city;
    std::string name;
    double latitude;
    double longitude;

};

class Graph{
    public:
        //Constructor
        Graph(int x);

        void buildAdj();

        void readFromFile();

        void insertVertex(Node  & n);

        //void insertEdge(Node a, Node b, double weight);

        void removeVertex(Node n);

        //void removeEdge(Node a, Node b);

        void incidentEdges(Node n);

        void areAdjacent(Node a, Node b);

        Node getVertex();

        Node getEdge();

        double calcWeights(Node & prev, Node & next);
        
        void BFS(std::string start, std::string  end);

        void printBFS(std::vector<std::string> const &  route);
       
        std::string minDistance(std::unordered_map< std::string, double > dist, std::unordered_map< std::string, bool > sptSet);
        
        std::vector<std::string> dijkstra(std::string src, std::string dest);
        
        void printDijkstra(std::string src, std::string dest);

    private:

        struct Edge{
            std::string prev;
            std::string dest;
        };

        //Storing the vertices
        std::vector<Node> vertices;

        /** Storing edges and their weights using an adjacency list
         * Key - Current city location
         * Mapped to - Destination city and distance from current city
        */
        std::unordered_map< std::string, std::list< std::pair<std::string, double> >> adj;

        //Helper function to calculate weights as distance of separation
        double _calcWeights(double lat1, double lon1, double lat2, double lon2);
};
