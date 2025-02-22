#include "iostream"
#include "fstream"
#include "sstream"
#include "algorithm"
#include "string"
#include "vector"
#include "common.h"

u_int32_t calculate_total_distance(std::vector<int>& r_list, std::vector<int>& l_list, u_int32_t& dist) {
  int       rSize = r_list.size();
  int       lSize = l_list.size();

  std::sort(r_list.begin(), r_list.begin()+rSize);
  std::sort(l_list.begin(), l_list.begin()+lSize);

  for (int i = 0; i < rSize; i++) {    // rSize & lSize are theoretically the same values
    dist += std::abs(r_list[i] - l_list[i]);
  }

  return dist;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "\033[4;31mno input specified!\033[0m" << std::endl;

    return -1;
  }

  std::vector<int> r_list(1000, 0);
  std::vector<int> l_list(1000, 0);
  u_int32_t        dist = 0;
  std::string      file_name = argv[1];

  std::ifstream input_file(file_name.c_str());

  // TODO
  if (input_file.is_open()) {  // check if the file is already open...
    std::string line;
    int         loc_ID1 = 0;
    int         loc_ID2 = 0;
    int         i = 0;

    // read the file line-by-line
    while (std::getline(input_file, line)) {
      std::istringstream iss(line);  // parse the line

      if (iss >> loc_ID1 >> loc_ID2) {  // read the two integers in this case
        r_list[i] = loc_ID1;
        l_list[i] = loc_ID2;
        i++;
      } else {
        std::cerr << "failed to read the input file on line: " << line << std::endl;
      }
    }

    input_file.close();
  } else {
    std::cerr << "failed to open file!" << std::endl;
  }

  // std::cout << r_list[10] << " " << l_list[20] << std::endl;
  std::cout << calculate_total_distance(r_list, l_list, dist) << std::endl;

  return 0;
}
