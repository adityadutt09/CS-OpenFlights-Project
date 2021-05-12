#include "graph.h"
#include <algorithm>

using namespace std;

void Graph::buildAdj( unordered_map< string, pair<double, double> > coords ){

    for(auto & e : edges){
        double weight = _calcWeight(coords[e.prev].first, coords[e.prev].second, coords[e.dest].first, coords[e.dest].second);
        adj[e.prev].push_back(make_pair(e.dest,weight));
        adj[e.prev].unique();
    
    }

    //cout<<"Adj List size : "<<adj.size()<<endl;
}

void Graph::_findCoords(vector<string> airports){
    
    unordered_map< string, pair<double, double> > coords;
    for (unsigned i = 0; i < airports.size(); i++){
        string location = airports[i].substr(4, string::npos);

        Node temp;
        temp.name = airports[i].substr(0, 3);
        string latitude = airports[i].substr(4, location.find(","));
        string longitude = location.substr(location.find(",") + 1, string::npos);

        temp.latitude = atof(latitude.c_str());
        temp.longitude = atof(longitude.c_str());

        coords[temp.name] = make_pair(temp.latitude, temp.longitude);
        insertVertex(temp);    
    }

    buildAdj(coords);
}

void Graph::insertEdges(vector<string> routes){
   
    for (unsigned i = 0; i < routes.size(); i++){
		string prev = routes[i].substr(0, 3);
		string dest = routes[i].substr(4, 3);
		edges.push_back(Edge{prev, dest});
	}
}

void Graph::insertVertex(Node & n){
    vertices.push_back(n);
}

double Graph::_calcWeight(double lat1, double lon1, double lat2, double lon2){
    
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
    
    //double R = 6371.0;
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    a = 2 * asin(sqrt(a));
    
    return 6371.0 * a;
}

void Graph::printGraph(Graph const& graph){

    for (auto & value : graph.adj) {
        string vertex = value.first;
        list< pair<string, double> > adjacentVertices = value.second;
        list< pair<string, double> >::iterator itr = adjacentVertices.begin();
         
        cout << "adjacencyList[" << vertex << "]";
          
        while (itr != adjacentVertices.end()) {
            cout << " -> " << (*itr).first << " (" << (*itr).second << ")";
            ++itr;
        }
         
        cout << endl;
    }
}

/** BFS Algorithm
 * Implements the Traversal and print function
 */

vector<string> Graph::BFS(std::string start, std::string end){
    
    unordered_map<string , bool> visited;
    
    for(auto node : vertices){
        visited[node.name] = false;
    }

    std::list<string> store;
    store.push_back(start);
    visited[start] = true;

    std::vector<string> route;

    //While the queue is not empty
    while(!store.empty()){
        string temp = store.front();
        
        //Process the node;
        route.push_back(temp);
        if(temp == end){
            break;
        }
        store.pop_front();

        for(auto it  = adj[temp].begin(); it != adj[temp].end(); it++){
            if(visited[it->first] != true){
                store.push_back(it->first);
                visited[it->first] = true;
            }
        }
    }

    return route;

}

void Graph::printBFS(string start, string end){

    std::vector<string> route = BFS(start,end);

    if(route.back() != end){
        cout<<"The traversal cannot be made from the given starting node to the given end node"<<endl;
        return;
    }

    cout<<"Applying a BFS traversal on the graph, starting from and ending at the airports listed above :"<<endl;
    for(auto path : route){
        if( path == route.back()){
            cout<<path;
            break;
        }

        cout<<path<<" -> ";
    }    
    cout<<endl;
}

/** Dijkstra's Algorithm
 * Implements Traversal and Print
 * Uses the helper function minDistance
 */ 

string Graph::minimum(unordered_map< string, double > dist, unordered_map< string, bool > shortest) 
{ 
  // Initialize min value 
  double min = DBL_MAX;
  string min_index; 
  
  for (auto & v : vertices){
    if (shortest[v.name] == false && dist[v.name] <= min){
      min = dist[v.name];
      min_index = v.name;
    }
  } 
  
  return min_index; 
}

vector<string> Graph::Dijkstra(string start, string end){ 
    //Each element will hold the shortest distance from start to the element index.
    unordered_map< string, double > dist;
  
    // shortest[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from start to i is finalized
    unordered_map< string, bool > shortest;
  
    unordered_map<string, string> prev;
  
    vector<string> path;
  
    // Initialize all distances as infinity and shortest path set as false 
    for (auto & v : vertices){
        shortest[v.name] = false;
        dist[v.name] = DBL_MAX;
        prev[v.name] = "";
    } 
  
    // Distance of starting node from itself is always 0 
    dist[start] = 0.0; 
  
    for (auto v : vertices) { 

        // Pick the vertex with the shortest distance from the set of vertices not 
        // yet processed. min is always equal to start in the first iteration. 
        string min = minimum(dist, shortest);
    
        // Make the picked vertex as visited
        shortest[min] = true; 
    
        bool flag = false;
    
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (auto it = adj[min].begin(); it != adj[min].end(); it++){
            string neighbor = it->first;
            double cost = it->second;
        
            if (!shortest[neighbor] && dist[min] + cost < dist[neighbor]){
                dist[neighbor] = dist[min] + cost;
                flag = true;
                prev[neighbor] = min;
            } 
        }
    }
  
    // create the path from the map of previous neighbors
    vector<string> rev_path;
    rev_path.push_back(end);
    string temp = end;
  
    unsigned count = 0;
  
    //While the string is not the start point
    while (temp.compare(start) != 0) {
        if (count == vertices.size()){
        break;
        }
    
        temp = prev[temp];
        rev_path.push_back(temp);
        count++;
    }
  
    reverse(rev_path.begin(), rev_path.end());
  
    //printDijkstra(rev_path);

    return rev_path; 

} 

void Graph::printDijkstra(string start, string end){
    
    vector<string> route = Dijkstra(start, end);  

    if(route.back() != end){
        cout<<"Your destination cannot be visited starting from the given point"<<endl;
        return;
    }

    cout << "From Dijkstra's Algorithm, the shortest path you can take from your starting airport to your destination is :" << endl;
    for (auto & airport: route) {
        if (airport == route.back()){
        cout << airport;
        break;
        }
        cout << airport << "->";
    }
    cout << endl;
}

/** Landmark Algorithm
 * Traversal and Print Function
 * Implements the Dijkstra function
 */ 

vector<string> Graph::Landmark(string start, string connection, string end){
    
    //Running Dijkstra's to get shortest path from start to end through connecting airport
    vector<string> connect1 = Dijkstra(start, connection);
    vector<string> connect2 = Dijkstra(connection,end);

    //Removing any redundancy
    connect2.erase(connect2.begin());

    //Joining to get total shortest path
    for(auto v : connect2){
        connect1.push_back(v);
    }

    return connect1;
}

void Graph::printLandmark(string start, string connection, string end){
    
    vector<string> route = Landmark(start, connection, end); 

    if(route.back() != end){
        cout<<"Your destination cannot be visited starting from the given point or through the given connection"<<endl;
        return;
    }

    cout << "From the Landmark Path Algorithm, the shortest path you can take from your starting airport to your destination is :" << endl;
    for (auto & airport: route) {
        if (airport == route.back()){
        cout << airport;
        break;
        }
        cout << airport << "->";
    }
    cout << endl;
}