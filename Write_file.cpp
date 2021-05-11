#include <iostream>
#include <fstream>
#include<vector>
#include<sstream>
using namespace std;

vector<string> _routes(string data){
   
   vector<string> row;
   vector<string> route;

   stringstream stream(data); //create string stream from the string
   while(stream.good()) {
      string sub;
      getline(stream, sub, ','); //get first string delimited by comma
      
      row.push_back(sub);
   }

   route.push_back(row[2]);
   route.push_back(row[4]);
   row.clear();

   return route;
}

void writeToRoutes(vector<string> original_data){
    
    ofstream outfile("final_routes.csv");
    vector<string> result;
    
    for (unsigned long i = 0; i < original_data.size(); i++) {
        
        result = _routes(original_data[i]);

        for (unsigned long j = 0; j < result.size(); j++) {
            if (j != result.size() - 1){
                outfile << result[j] + ",";
            }
            else{
                outfile << result[j];
            }
        }
        outfile << endl;
        result.clear();
    }

    outfile.close();
}

vector<string> _airports(string data){
   vector<string> row;
   vector<string> route;

   stringstream stream(data); //create string stream from the string
   while(stream.good()) {
      string sub;
      getline(stream, sub, ','); //get first string delimited by comma
      
      row.push_back(sub);
   }

   route.push_back(row[4].substr(1, 3));
   route.push_back(row[6]);
   route.push_back(row[7]);
   row.clear();

   return route;
}

void writeToAirports(vector<string> original_data){
    
    ofstream outfile("final_airports.csv");
    vector<string> result;

    for (unsigned long i = 0; i < original_data.size(); i++) {
        
        result = _airports(original_data[i]);
        if (result[0] != "N"){
            for (unsigned long j = 0; j < result.size(); j++) {
                if (j != result.size() - 1){
                    outfile << result[j] + ",";
                }
                else{
                    outfile << result[j];
                }
            }
            outfile << endl;
        }

        result.clear();
    }

    outfile.close();
}