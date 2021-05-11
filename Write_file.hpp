#include <string>
#include<vector>

using namespace std;

// adapted from CS 225 Final Project AMA

/** 
 * Writes a file from a vector
 * @param original_data The file to write from
 */
void writeToRoutes(vector<string> original_data);

void writeToAirports(vector<string> original_data);

//Helper functions
vector<string> _routes(string data);

vector<string> _airports(string data);