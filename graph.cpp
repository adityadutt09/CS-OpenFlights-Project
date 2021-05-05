#include "graph.h"
#include <queue>

using namespace std;


Graph::Graph(int x){
    
    if(x == 1){
        //Reads data from the csv file and creates the set of vertices
        readFromFile();
    }
}

void Graph::buildAdj(){
    
    /* Runs in O(n^2) */
    //Create a set of edges with their weights from the vertices
    for(unsigned i = 0; i < vertices.size(); i++){
        for(auto it = vertices.begin(); it != vertices.end(); it++){
            
            //Check if the nodes are the same
            if(vertices[i].city == (*it).city)
                continue;
            
            else{
                
                double dist = calcWeights(vertices[i], (*it));
                
                //Create the adjacency list
                adj[vertices[i].name].push_back(make_pair((*it).name, dist));
            
                //adj[vertices[i].city].unique();
            }
        }
    }
}

void Graph::readFromFile(){

    ifstream fin;
    fin.open("airports.dat", ios::in);

    std::vector<string> row;
    string line, word, temp;

    //std::vector<Nodes> nodes;
        
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

        //nodes.push_back(temp);

        //Call insertvertex
        insertVertex(temp);
        
    }

    fin.close();

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

double Graph::calcWeights(Node & prev, Node & next){

        double weight = _calcWeights(prev.latitude, prev.longitude, next.latitude, next.longitude);
        return weight;

}

double Graph::_calcWeights(double lat1, double lon1, double lat2, double lon2){
    
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
    
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double R = 6371.0;
    double c = 2 * asin(sqrt(a));
    return R * c;
}


//Constructor for the BFS Traversal
void Graph::BFS(const std::string & start, const std::string & end){
    
    unordered_map<string , bool> visited;
    for(auto node : vertices){
        visited[node.name] = false;
    }

    std::queue<string> store;
    store.push(start);
    visited[start] = true;

    std::vector<string> route;

    while(!store.empty()){
        string temp = store.front();
        store.pop();

        //Process the node;
        route.push_back(temp);
        if(temp == end)
            break;
        
        for(auto it  = adj[temp].begin(); it != adj[temp].end(); it++){
            if(visited[it->first] != true){
                store.push(it->first);
                visited[it->first] = true;
            }
        }
    }

    printBFS(route);

}

void Graph::printBFS(std::vector<std::string> const & route){

    //if( route.back() != end )
    for(auto path : route){
        if( path == route.back()){
            std::cout<<path;
            break;
        }

        std::cout<<path<<" - > ";
    }    
    std::cout<<std::endl;

}
