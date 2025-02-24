#include "string"
#include "fstream"
#include "sstream"

// file i/o can also be made part of this "common" header

namespace decorators{
    const std::string reset_all("\033[0m");

    const std::string bold("\033[1m");
    const std::string bold_off("\033[21m");

    const std::string dim("\033[2m");
    const std::string dim_off("\033[22m");

    const std::string italics("\033[3m");
    const std::string italics_off("\033[23m");

    const std::string underline("\033[4m");
    const std::string underline_off("\033[24m");

    const std::string blink("\033[5m");    // apparently 5 & 6 have the same effects
    const std::string blink_off("\033[25m");

    const std::string reverse("\033[7m");
    const std::string reverse_off("\033[27m");

    const std::string hidden("\033[8m");
    const std::string hidden_off("\033[28m");

    const std::string strike("\033[9m");
    const std::string strike_off("\033[29m");

    namespace colors{
        const std::string default_color("\033[39m");

        const std::string black("\033[30m");

        const std::string red("\033[31m");
        const std::string green("\033[32m");
        const std::string yellow("\033[33m");
        const std::string blue("\033[34m");
        const std::string magenta("\033[35m");
        const std::string cyan("\033[36m");
        const std::string light_gray("\033[37m");

        const std::string dark_gray("\033[90m");
        const std::string light_red("\033[91m");
        const std::string light_green("\033[92m");
        const std::string light_yellow("\033[93m");
        const std::string light_blue("\033[94m");
        const std::string light_magenta("\033[95m");
        const std::string light_cyan("\033[96m");

        const std::string white("\033[97m");
    }
}
// color codes to be able to log various things - basic idea inspired from various tools

// https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
