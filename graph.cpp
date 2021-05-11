#include "graph.h"
#include <queue>

using namespace std;

void Graph::buildAdj( unordered_map< string, pair<double, double> > coords ){

    for(auto & e : edges){
        double weight = _calcWeight(coords[e.prev].first, coords[e.prev].second, coords[e.dest].first, coords[e.dest].second);
        adj[e.prev].push_back(make_pair(e.dest,weight));
        adj[e.prev].unique();
    
    }

    cout<<"Adj List size : "<<adj.size()<<endl;

    /* Runs in O(n^2) 
    //Create a set of edges with their weights from the vertices
    for(unsigned i = 0; i < vertices.size(); i++){
        for(auto it = vertices.begin(); it != vertices.end(); it++){
            
            //Check if the nodes are the same
            if(vertices[i].name == (*it).name)
                continue;
            
            else{
                
                double dist = calcWeights(vertices[i], (*it));
                
                //Create the adjacency list
                adj[vertices[i].name].push_back(make_pair((*it).name, dist));
                adj[vertices[i].name].unique();
            }
        }
    }
    */
}

/*void Graph::readCoordsfromFile(){

    ifstream fin;
    fin.open("airports.dat", ios::in);

    std::vector<string> row;
    string line, word, temp;

    while(fin>>temp){
        //Read the 3rd, 4th, 7th, 8th values from each line. 
        row.clear();

        getline(fin, line);

        std::stringstream s(line);

        while(getline(s, word, ',')){
            row.push_back(word);
        }

        Node temp;
        temp.city = row[3];
        temp.name = row[4];
        temp.latitude = stoi(row[6]);
        temp.longitude = stoi(row[7]);
        
        //Call insertvertex
        insertVertex(temp);

    }

    //cout<<vertices.size();

    fin.close();

}
*/

/*void Graph::readEdgesfromFile(){
    
    ifstream fin;
    fin.open("routes.dat", ios::in);

    std::vector<string> row;
    string line, word, temp;

    while(fin>>temp){
        //Read the 3rd, 5th values from each line
        row.clear();

        getline(fin, line);

        std::stringstream s(line);

        while(getline(s, word, ',')){
            row.push_back(word);
        }

        Edge temp;
        temp.prev = row[2];
        temp.dest = row[4];

        //Call insertEdge
        edges.push_back(temp);

    }

    fin.close();

}
*/

void Graph::_findCoords(vector<string> airports){
    
    unordered_map< string, pair<double, double> > coords;
    for (unsigned i = 0; i < airports.size(); i++){
        string after_airport = airports[i].substr(4, string::npos);

        string key = airports[i].substr(0, 3);
        string lat = airports[i].substr(4, after_airport.find(","));
        string lon = after_airport.substr(after_airport.find(",") + 1, string::npos);

        double latitude = atof(lat.c_str());
        double longitude = atof(lon.c_str());

        coords[key] = make_pair(latitude, longitude);
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
    //Check if similar
    for(unsigned i = 0; i < vertices.size(); i++){
        if( vertices[i].name == n.name ){
            return;
        }
    }
    vertices.push_back(n);
}

/*void Graph::calcWeights(){

    //unordered_map< string, pair<double, double> > coords;
    //for(auto & v : vertices){
      //  coords[v.name] = make_pair(v.latitude,v.longitude);
    //}

    

    //cout<<"Weight size :"<<weights.size()<<endl;
}*/

double Graph::_calcWeight(double lat1, double lon1, double lat2, double lon2){
    
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
    
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    //double R = 6371.0;
    a = 2 * asin(sqrt(a));
    return 6371.0 * a;
}


//Constructor for the BFS Traversal
void Graph::BFS(std::string start, std::string end){
    
    unordered_map<string , bool> visited;
    //visited.reserve(vertices.size());
    
    for(auto node : vertices){
        visited[node.name] = false;
    }

    //std::queue<string> store;
    std::list<string> store;
    store.push_back(start);
    visited[start] = true;

    std::vector<string> route;

    while(!store.empty()){
        string temp = store.front();
        
        //Process the node;
        route.push_back(temp);
        if(temp == end){
            break;
        }
        store.pop_front();

        cout<<adj[temp].size()<<endl;

        for(auto it  = adj[temp].begin(); it != adj[temp].end(); it++){
            if(visited[it->first] != true){
                store.push_back(it->first);
                visited[it->first] = true;
            }
        }
    }

    cout<<route.size()<<endl;

    printBFS(route);

}

void Graph::printBFS(std::vector<std::string> const & route){

    //if( route.back() != end )

    for(auto path : route){
        if( path == route.back()){
            cout<<path;
            break;
        }

        cout<<path<<" - > ";
    }    
    cout<<endl;

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


/*string Graph::minDistance(unordered_map< string, double > dist, unordered_map< string, bool > sptSet) 
{ 
  // Initialize min value 
  double min = DBL_MAX;
  string min_index; 
  
  for (auto node : nodes){
    if (sptSet[node] == false && dist[node] <= min){
      min = dist[node];
      min_index = node;
    }
  } 
  
  return min_index; 
}

vector<string> dijkstra(string src, string dest);
{ 
  // The output array.  dist[i] will hold the shortest 
  // distance from src to i 
  unordered_map< string, double > dist;
  
  // sptSet[i] will be true if vertex i is included in shortest 
  // path tree or shortest distance from src to i is finalized
  unordered_map< string, bool > sptSet;
  
  unordered_map<string, string> prev;
  
  vector<string> path;
  
  // Initialize all distances as INFINITE and stpSet[] as false 
  for (auto node : nodes){
    sptSet[node] = false;
    dist[node] = DBL_MAX;
    prev[node] = "";
  } 
  
  // Distance of source vertex from itself is always 0 
  dist[src] = 0.0; 
  
  for (auto node : nodes) { 
    // Pick the minimum distance vertex from the set of vertices not 
    // yet processed. u is always equal to src in the first iteration. 
    string u = minDistance(dist, sptSet);
    
    // Make the picked vertex as visited
    sptSet[u] = true; 
    
    bool dist_updated = false;
    // Update dist value of the adjacent vertices of the picked vertex. 
    for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it)
    { 
      string neighbor = it->first;
      double cost = it->second;
      if (!sptSet[neighbor] && dist[u] + cost < dist[neighbor]) 
      { 
        dist[neighbor] = dist[u] + cost;
        dist_updated = true;
        prev[neighbor] = u;
      } 
    }
    
  }
  
  // create the path from the map of previous neighbors
  vector<string> p;
  p.push_back(dest);
  string curr = dest;
  unsigned count = 0;
  while (curr.compare(src) != 0) {
    if (count == nodes.size()){
      break;
    }
    
    curr = prev[curr];
    p.push_back(curr);
    count++;
  }
  
  reverse(p.begin(), p.end());
  return p;
} 

void Graph::printDijkstra(string src, string dest){
  vector<string> runDijkstra = dijkstra(src, dest);
  
  if (runDijkstra.back() != dest){
    cout << "Cannot reach your destination from here." << endl;
    return;
  }
  
  cout << "According to Dijkstra's Algorithm, this is the shortest path you can take from your source to your destination." << endl;
  for (auto airport: runDijkstra) {
    if (airport == runDijkstra.back()){
      cout << airport;
      break;
    }
    cout << airport << "->";
  }
  cout << endl;
}
*/
