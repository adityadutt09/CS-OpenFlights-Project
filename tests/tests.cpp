#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cerrno>
#include <cstdlib>
#include <stdlib.h>
#include "../graph.h"
#include "../catch/catch.hpp"
#include "../Read_file.hpp"
#include "../Write_file.hpp"
using namespace std;


Graph testBuildGraph(){

  Graph testg;
  
  string originalRoute = file_to_string("routes.csv");
	vector<string> routes_vector = string_to_vector(originalRoute, 6);
	writeToRoutes(routes_vector);

  string finalroutes = file_to_string("final_routes.csv");
	vector<string> routes;

  int begin = 0;
  int end = 0;
    
  for (unsigned i = 0; i < finalroutes.length(); ++i) {     
    if (finalroutes[(int)i] == '\n') {
      end = (int)i;
      routes.push_back(finalroutes.substr(begin, end - begin));
      begin = ((int)i + 1);
    }
  }

  testg.insertEdges(routes);

  unordered_map< string, pair< double, double > > coords;
  coords["YBR"] = make_pair(49.91,-99.951897);
  coords["IAM"] = make_pair(28.0515,9.64291);  
  coords["OUA"] = make_pair(12.3532,-1.51242);

  vector<Node> nodes;
  nodes.push_back(Node{"YBR",49.91,-99.951897});
  nodes.push_back(Node{"IAM",28.0515,9.64291});
  nodes.push_back(Node{"OUA",12.3532,-1.51242});

  for( auto & node : nodes){ testg.insertVertex(node); }

  testg.buildAdj(coords);

  return testg;

}

TEST_CASE("BFS size", "[weight=2][part=1]") {
  Graph g = testBuildGraph(); 
  
  vector<string> bfs_size;
 
  bfs_size = g.BFS("DXB", "BOM");
  
  REQUIRE(bfs_size.size() == 5);

}

TEST_CASE("BFS elements", "[weight=2][part=1]") {
  Graph g = testBuildGraph(); 
  
  vector<string> bfs;
 
  bfs = g.BFS("DXB", "SIN");
  
  REQUIRE(bfs[0].compare("DXB") == 0);

  REQUIRE(bfs.back().compare("SIN") == 0);

}

TEST_CASE("Dijkstra elements and size", "[weight=2][part=1]") {
  Graph g = testBuildGraph(); 
  
  vector<string> dijkstra;
 
  dijkstra = g.Dijkstra("KHS", "SIN");

  REQUIRE(dijkstra[0].compare("KHS") == -1);

  REQUIRE(dijkstra.back().compare("SIN") == 0);

  REQUIRE(dijkstra.size() == 4);

  //REQUIRE(dijkstra[2].compare("KUL" == 0));

}

TEST_CASE("Landmark Size", "[weight=2]"){
  Graph g = testBuildGraph();

  vector<string> landmark;
  landmark = g.Landmark("KHS", "DOH", "SIN");

  REQUIRE(landmark.size() == 7);

  REQUIRE(landmark[0].compare("KHS") == -1);

  string test;
  for(auto l : landmark){
    if(l.compare("DOH") == 0)
      test = "DOH";
    else
      test = "";
  }
  
  REQUIRE(test.compare("DOH") == -1);

  REQUIRE(landmark.back().compare("SIN") == 0);

}
