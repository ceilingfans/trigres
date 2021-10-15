#include <iostream>
#include <string>
#include <vector>
#include "../lib/cli/cli.hpp"
#include "../lib/util/util.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  vector<Argument> args;
  for (int i = 1; i < argc; ++i) {
    string whole_arg = pchar_to_string(argv[i]).substr(1, string::npos);
    vector<string> split_arg = split_text(whole_arg, "=");
    Argument parsed_arg(split_arg[0], split_arg[1]);
    args.push_back(parsed_arg);
  }

  run_cli(args);
  return 0;
}