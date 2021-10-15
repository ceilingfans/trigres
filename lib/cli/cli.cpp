#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "cli.hpp"
#include "../util/trigo.hpp"

using namespace std;

Argument::Argument(string c_flag, string c_arg) {
  flag = move(c_flag);
  arg  = move(c_arg);
}

void run_cli(const vector<Argument>& argv) {
  int hyp,
      opp,
      adj,
      quad;

  string method,
         name = "x";

  for (auto & element : argv) {
    string flag = element.flag;
    string arg  = element.arg;

    if (flag == "method" || flag == "m") {
      method = arg;
    }
    else if (flag == "hyp" || flag == "h") {
      hyp = stoi(arg);
    }
    else if (flag == "opp" || flag == "o") {
      opp = stoi(arg);
    }
    else if (flag == "adj" || flag == "a") {
      adj = stoi(arg);
    }
    else if (flag == "quad" || flag == "q") {
      quad = stoi(arg);
    }
    else if (flag == "name" || flag == "n") {
      name = arg;
    }
    else {
      cout << flag << endl;
      cout << "Invalid Flag" << endl;
      exit(132);
    }
  }

  if (method == "sin") {
    resolve_sine(opp, hyp, quad, name);
  }
  else if (method == "cos") {
    resolve_cosine(adj, hyp, quad, name);
  }
  else if (method == "tan") {
    resolve_tangent(opp, adj, quad, name);
  }
  else {
    cout << "Invalid or Unprovided method" << endl;
    exit(132);
  }
}