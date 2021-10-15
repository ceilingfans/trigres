#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include "util.hpp"

using namespace std;

void resolve_sine(const int& opp, const int& hyp, const int& quad, const string& name) {
  if (hyp < 0) {
    cout << "The hypotenuse is expected to have a positive value" << endl;
    exit(132);
  }
  if (opp > hyp) {
    cout << "The opposite can never be larger than the hypotenuse" << endl;
    exit(132);
  }

  double adj;
  if (quad == 1) {
    adj = sqrt(pow(hyp, 2) - pow(opp, 2));
  }
  else if (quad == 2) {
    adj = -1 * sqrt(pow(hyp, 2) - pow(opp, 2));
  }
  else if (quad == 3) {
    adj = -1 * sqrt(pow(hyp, 2) - pow(opp, 2));
  }
  else if (quad == 4) {
    adj = sqrt(pow(hyp, 2) - pow(opp, 2));
  }
  else {
    cout << "Invalid quadrant provided, expected an integer from 1 to 4" << endl;
    exit(132);
  }

  print_equations(
          hyp,
          (opp > 0) && (quad == 3 || quad == 4) ? -opp : opp,
          adj,
          name
  );
}

void resolve_cosine(const int& adj, const int& hyp, const int& quad, const string& name) {
  if (hyp < 0) {
    cout << "The hypotenuse is expected to have a positive value" << endl;
    exit(132);
  }
  if (adj > hyp) {
    cout << "The adjacent can never be larger than the hypotenuse" << endl;
    exit(132);
  }

  double opp;
  if (quad == 1) {
    opp = sqrt(pow(hyp, 2) - pow(adj, 2));
  }
  else if (quad == 2) {
    opp = sqrt(pow(hyp, 2) - pow(adj, 2));
  }
  else if (quad == 3) {
    opp = -1 * sqrt(pow(hyp, 2) - pow(adj, 2));
  }
  else if (quad == 4) {
    opp = -1 * sqrt(pow(hyp, 2) - pow(adj, 2));
  }
  else {
    cout << "Invalid quadrant provided, expected an integer from 1 to 4" << endl;
    exit(132);
  }

  print_equations(
          hyp,
          opp,
          (adj > 0) && (quad == 2 || quad == 3) ? -adj : adj,
          name
  );
}

void resolve_tangent(const int& opp, const int& adj, const int& quad, const string& name) {
  double hyp;
  if (quad == 1) {
    hyp = sqrt(pow(opp, 2) + pow(adj, 2));
  }
  else if (quad == 2) {
    hyp = sqrt(pow(opp, 2) + pow(adj, 2));
  }
  else if (quad == 3) {
    hyp = sqrt(pow(opp, 2) + pow(adj, 2));
  }
  else if (quad == 4) {
    hyp = sqrt(pow(opp, 2) + pow(adj, 2));
  }
  else {
    cout << "Invalid quadrant provided, expected an integer from 1 to 4" << endl;
    exit(132);
  }

  print_equations(
          hyp,
          (opp > 0) && (quad == 3 || quad == 4) ? -opp : opp,
          (adj > 0) && (quad == 2 || quad == 3) ? -adj : adj,
          name
  );
}