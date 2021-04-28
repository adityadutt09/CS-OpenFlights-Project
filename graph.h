/** File for creating and storing the routes and connections.
 * Graph storing nodes as the places
 * Edges are the routes between them
 * Weights of each edge is the time difference between two places
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>

class Graph{
    public:
        void readFromFile();

        void insertVertex(Node  & n);

        //void insertEdge(Node a, Node b, double weight);

        void removeVertex(Node n);

        //void removeEdge(Node a, Node b);

        void incidentEdges(Node n);

        void areAdjacent(Node a, Node b);

        Node getVertex();

        Node getEdge();
    
    private:

        struct Node{
            string city;
            string name;
            double latitude;
            double longitude;

        };

        //Number of vertices
        std::vector<Node> vertices;

        //Set of weights for each edge
        std::vector<vector<double>> weights;

        //Helper function to calculate weights as distance of separation
        void calcWeights();

}