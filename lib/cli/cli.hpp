#include <string>
#include <vector>

class Argument {
public:
    std::string flag;
    std::string arg;

    Argument(std::string c_flag, std::string c_arg);
};

void run_cli(const std::vector<Argument>& argv);