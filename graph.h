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

class Graph{
    public:
        //Constructor
        Graph();

        void readFromFile();

        void insertVertex(Node  & n);

        //void insertEdge(Node a, Node b, double weight);

        //void removeVertex(Node n);

        //void removeEdge(Node a, Node b);

        //void incidentEdges(Node n);

        bool areAdjacent(Node a, Node b);

        Node getVertex();

        Node getEdge();

        void calcWeights();

        void BFS(string start, string end);
    
    /*class BFS{
        public:
  
            BFS(const Node & n);
  
            BFS::Iterator begin();
            BFS::Iterator end();
            BFS::Iterator operator++();
  
            void add();
            Node pop();
            void peek() const;
            bool empty() const;
  
        private:
            std::queue<Node> queue;
    
    };
    */

    private:

        struct Node{
            string city;
            string name;
            double latitude;
            double longitude;

        };

        struct Edge{
            string prev;
            string dest;
        };

        //Storing the vertices
        std::vector<Node> vertices;

        //Storing the edges
        //std::vector<Edge> edges;

        /** Storing edges and their weights using an adjacency list
         * Key - Current city location
         * Mapped to - Destination city and distance from current city
        */
        unordered_map< string, list< pair<string, double> > > adj;

        //Helper function to calculate weights as distance of separation
        double _calcWeights(double lat1, double lon1, double lat2, double lon2)
        
};