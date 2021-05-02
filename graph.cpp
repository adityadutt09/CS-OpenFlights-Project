#include "graph.h"
#include <fstream>
#include <sstream>
#include <cmath>

void Graph::readFromFile(){

    ifstream fin;
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

void Graph::insertVertex(Node & n){
    //Check if similar
    for(unsigned i = 0; i < vertices.size(); i++){
        if( vertices[i].city == n.city ){
            std::cout<<"Vertex already exists";
            return;
        }
    }
    vertices.push_back(n);
}

/*void Graph::removeVertex(Node n){
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
*/

void Graph::calcWeights(){

    for(unsigned i = 1; i < vertices.size(); i++){
        
        double weight = _calcWeights(vertices[i-1].latitude, vertices[i-1].longitude, vertices[i].latitude, vertices[i].longitude);
        //weights.insert(weight,i);

    }
}

double Graph::_calcWeights(double lat1, double lon1, double lat2, double lon2){
    
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
    
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double R = 6371;
    double c = 2 * asin(sqrt(a));
    return R * c;
}