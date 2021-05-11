#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);

	std::stringstream stream;
	if (text.is_open()) {
		stream << text.rdbuf();
	}

	return stream.str();
}

std::vector<std::string> string_to_vector(std::string data, int num) {
	std::vector<std::string> result;
    std::string temp;
    int begin = 0;
    int end = 0;

	// split the string of data by endline characters
    for (unsigned i = 0; i < data.length(); ++i) {     
        if (data[(int)i] == '\n') {
            end = (int)i;
            result.push_back(data.substr(begin, end - begin));
            begin = ((int)i + 1);
        }
    }

	// used to parse each line of data, removes un-needed data after a certain comma
	string word = "";
	vector<string> newData;
	for (unsigned long j = 0; j < result.size(); j++) {
		string temp = result[(int)j];
		int ctr = 0;
		for (unsigned long k = 0; k < temp.length(); k++){
			if (temp[(int)k] == ','){
				ctr++;
			}
			if (ctr == num){
				word = temp.substr(0, (int)k);
			}
		}
		newData.push_back(word);
	}	
	return newData;
}