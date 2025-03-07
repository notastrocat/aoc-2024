#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "common.h"
#include "vector"

enum sort_type
{
    INCREASING = 1,
    DECREASING = 2
};

bool chk_sorted(std::vector<int> &levels, sort_type st)
{
    if (sort_type::INCREASING == st) {
        for (int level = 1; level < levels.size(); level++) {
            if (levels[level] < levels[level - 1]) return false;
        }
        return true;
    }
    else if (sort_type::DECREASING == st) {
        for (int level = 1; level < levels.size(); level++) {
            if (levels[level] > levels[level - 1]) return false;
        }
        return true;
    }

    return false;
}

int analyze_reports(std::vector<std::vector<int>> &reports) {
    int num_safe = 0;

    for (auto levels : reports) {
        bool bDec = false;
        bool bInc = false;

        bInc = chk_sorted(levels, sort_type::INCREASING);
        bDec = chk_sorted(levels, sort_type::DECREASING);

        bool randomFlag = true;

        if (bInc) {
            for (int level = 1; level < levels.size(); level++) {
                if (((levels[level] - levels[level - 1]) < 1) || ((levels[level] - levels[level - 1]) > 3)) {
                    randomFlag = false;
                    break;
                }
            }

            if (randomFlag) num_safe++;
        } else if (bDec) {
            for (int level = 1; level < levels.size(); level++) {
                if ((abs(levels[level] - levels[level - 1]) < 1) || (abs(levels[level] - levels[level - 1]) > 3)) {
                    randomFlag = false;
                    break;
                }
            }

            if (randomFlag) num_safe++;
        }
    }

    return num_safe;
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        std::cout << decorators::underline << decorators::colors::red << "no input file specified!" << decorators::reset_all << std::endl;

        return -1;
    }

    std::string filename = argv[1];
    std::ifstream input_file(filename.c_str());
    std::vector<std::vector<int>> reports;
    reports.reserve(1000);
    std::vector<int> levels;

    // I need to parse every line - but every line may have a different number of integers.

    if (input_file.is_open())
    { // check if the input file is already open
        int level;
        std::string line;

        while (std::getline(input_file, line))
        {
            std::istringstream iss(line);
            int count = 0;

            while (iss >> level)
            {
                count++;
            }

            iss.clear();
            iss.seekg(0);
            levels.clear();
            levels.reserve(count);

            while (iss >> level)
            {
                levels.push_back(level);
            }
            reports.push_back(levels);
        }

        input_file.close();
    }
    else
    {
        std::cout << decorators::underline << decorators::colors::red << "file " << filename << " is not open" << decorators::reset_all << std::endl;
    }

    // as for the problem itself, start off with comparing the first & the last integers, this should determine the nature of line - ie, increasing or decreasing.
    // then, it should be ez from that point onwards...

    // path 1 - there will be a persistent storage of these reports...if we do not want to process the files on the fly.
    // path 2 - if we process the files on the fly, well that's a good strat; doable.

    std::cout << analyze_reports(reports) << "\n";

    return 0;
}