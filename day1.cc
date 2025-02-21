#include "iostream"
#include "fstream"
#include "algorithm"
#include "string"
#include "vector"

u_int64_t calculate_total_distance(std::vector<int> r_list, std::vector<int> l_list) {
    int rSize = r_list.size();
    int lSize = l_list.size();
    u_int64_t dist;

    std::sort(r_list.begin(), r_list.begin()+rSize);
    std::sort(l_list.begin(), l_list.begin()+lSize);

    for (int i = 0; i < rSize; i++) {    // rSize & lSize are theoretically the same values
        dist += std::abs(r_list[i] - l_list[i]);
    }
}

int main(int argv, char** argc) {
    std::vector<int> right_list(1000,0);
    std::vector<int> left_list(1000,0);
    u_int64_t dist;

    std::ifstream input_file("day1_input.txt");

    // [TODO)
    // while(!input_file.eof()) {

    // }
    
    return 0;
}