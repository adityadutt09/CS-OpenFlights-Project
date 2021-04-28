#include "graph.h"
#include <fstream>
#include <sstream>

void Graph::readFromFile(){

    fstream fin;
    fin.open("airports.dat", ios::in);

    std::vector<string> row;
    string line, data, temp;
        
    while(fin>>temp){
        //Read the 3rd, 4th, 7th, 8th values from each line. 
        row.clear();

        getline(fin, line);

        std::stringstream s(line);

        while(getline(s, word, ',')){
            row.push_back(word);
        }

        Node temp;
        temp.city = row[2];
        temp.name = row[3];
        temp.latitude = stoi(row[6]);
        temp.longitude = stoi(row[7]);

        //Call insertvertex
        insertVertex(temp);
        
    }

    fin.close();

    //Call calculate weights for each edge;
    calcWeights();

}

void Graph::insertVertex(Node  & n){
    //Check if similar
    for(unsigned i = 0; i < vertices.size(); i++){
        if( vertices[i].city == n.city ){
            std::cout<<"Vertex already exists";
            return;
        }
    }
    vertices.push_back(n);
}

void Graph::removeVertex(Node n){
    for(unsigned i = 0; i < vertices.size(); i++){
        if(vertices[i].city == n.city){
            Node temp;
            temp.city = vertices[i].city;
            temp.name = vertices[i].name;
            temp.latitude = vertices[i].latitude;
            temp.longitude = vertices[i].longitude;
            vertices
            removeWeights(temp);

        }
    }
}