#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
#include "algorithm"
#include "vector"
#include "map"

int calculate_similarity(std::vector<int> &r_list, std::vector<int> &l_list, int64_t &score) {
    int lSize = l_list.size();
    // std::sort(l_list.begin(), l_list.begin()+lSize);

    std::map<int, int> location_count;

    for (int i = 0; i < lSize; i++) {
        bool found = false;
        if (location_count.find(r_list[i]) != location_count.end()) continue;
        else {
            for (int j = 0; j < lSize; j++) {
                if ( r_list[i] == l_list[j] ) {
                    location_count[r_list[i]]++;
                    found = true;
                }
            }
            if (false == found) location_count.insert(std::make_pair(r_list[i],0));
        }
    }

    for (int i : r_list)
        score += (i * location_count[i]);

    return score;
}

int main (int argc, char **argv) {
    if (argc < 2){
        std::cout << "\033[4;31mno input file specified!\033[0m" << std::endl;
        
        return -1;
    }
    
    std::vector<int> r_list(1000, 0);
    std::vector<int> l_list(1000, 0);
    int64_t          score = 0;
    std::string      filename = argv[1];
    std::ifstream    input_file(filename);

    if (input_file.is_open()) {    // check if the file is already open...
        std::string line;
        int         locID1;
        int         locID2;
        int         i = 0;

        while (std::getline(input_file, line)) {
            std::istringstream iss(line);    // parse the line

            if (iss >> locID1 >> locID2) {    // get the two integers in the line & store them in a vector
                r_list[i] = locID1;
                l_list[i] = locID2;
                i++;
            } else {
                std::cerr << "\033[4;31mfailed to read the input on line: " << line << "\033[0m\n";
            }
        }
        
        input_file.close();
    } else {
        std::cerr << "\033[4;31mfailed to open the file\033[0m\n";
    }

    std::cout << "similarity score- " << calculate_similarity(r_list, l_list, score) << std::endl;
    
    return 0;
}
