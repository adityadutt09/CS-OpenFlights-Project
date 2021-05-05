#include "graph.h"

Graph::Graph(){
    
    //Reads data from the csv file and creates the set of vertices
    readFromFile();

    /* Runs in O(n^2) */
    //Create a set of edges with their weights from the vertices
    for(unsigned i = 0; i < vertices.size(); i++){
        for(auto it = vertices.begin(); it != vertices.end(); it++){
            
            //Check if the nodes are the same
            if(vertices[i] == (*it)){
                continue;
            
            else{
                //Edge temp;
                //Store the airport names instead of city names
                //temp.prev = vertices[i].name;
                //temp.dest = (*it).name;

                double dist = calcWeight(vertices[i], (*it));
                
                //Create the adjacency list
                adj[vertices[i].name].push_back(make_pair((*it).name, dist));
            
                //adj[vertices[i].city].unique();
            }
        }
    }

}

Graph::readFromFile(){

    ifstream fin;
    fin.open("airports.dat", ios::in);

    std::vector<string> row;
    string line, data, temp;

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
Graph::BFS::BFS(string start, string end){
    
    unoredered_map<string , bool> visited;
    for(auto node : vertices){
        visited[node.name] = false;
    }

    std::queue<string> store;
    store.push(start);
    visited[start] = true;

    std::vector<string> route;

    while(!store.empty()){
        string temp = queue.front();
        store.pop_front();

        //Process the node;
        route.push_back(temp);
        if(temp == end)
            break;
        
        for(auto it  = adj[temp].begin(); it != adj[temp].end(); it++){
            if(visited[it->first] != true){
                queue.push(it->first);
                visited[it->first] = true;
            }
        }
    }

    printBFS(route, start, end);

}

void Graph::printBFS(std::vector<string> const & route, const string & start, const string & end){

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


/** Pseudo code
 * BFSTraversal(start_node):
 * visited := a set to store references to all visited nodes

  queue := a queue to store references to nodes we should visit later
  queue.enqueue(start_node)
  visited.add(start_node)

  while queue is not empty:
    current_node := queue.dequeue()

    process current_node
    # for example, print(current_node.value)

    for neighbor in current_node.neighbors:
      if neighbor is not in visited:
        queue.enqueue(neighbor)
        visited.add(neighbor)

*/

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