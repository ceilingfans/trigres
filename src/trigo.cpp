#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>

#include "util.hpp"

using namespace std;

void resolveSine(const double &opp, const double &hyp, const int &quad, const string &name)
{
  if (hyp <= 0)
  {
    clog << "range error: ";
    cout << "the hypotenuse must be positive" << endl;
    exit(132);
  }
  if (opp > hyp)
  {
    clog << "range error: ";
    cout << "the hypotenuse should be larger than the opposite" << endl;
    exit(132);
  }

  double adj;
  if (quad == 1 || quad == 4)
  {
    adj = sqrt((hyp*hyp) - (opp*opp));
  }
  else if (quad == 2 || quad == 3)
  {
    adj = -sqrt((hyp*hyp) - (opp*opp));
  }
  else
  {
    clog << "range error: ";
    cout << "expected quadrant value to be an integer from 1 to 4, received " << quad << endl;
    exit(132);
  }

  printEquations(
          hyp,
          (opp > 0) && (quad == 3 || quad == 4) ? -opp : opp,
          adj,
          name
          );
}
void resolveCosine(const double &adj, const double &hyp, const int &quad, const string &name)
{
  if (hyp <= 0)
  {
    clog << "range error: ";
    cout << "the hypotenuse must be positive" << endl;
    exit(132);
  }
  if (adj > hyp)
  {
    clog << "range error: ";
    cout << "the hypotenuse should be larger than the opposite" << endl;
    exit(132);
  }

  double opp;
  if (quad == 1 || quad == 2)
  {
    opp = sqrt((hyp*hyp) - (adj*adj));
  }
  else if (quad == 3 || quad == 4)
  {
    opp = -sqrt((hyp*hyp) - (adj*adj));
  }
  else
  {
    clog << "range error: ";
    cout << "expected quadrant value to be an integer from 1 to 4, received " << quad << endl;
    exit(132);
  }

  printEquations(
          hyp,
          opp,
          (adj > 0) && (quad == 2 || quad == 3) ? -adj : adj,
          name
          );
}
void resolveTangent(const double &opp, const double &adj, const int &quad, const string &name)
{
  double hyp;
  if (quad < 1 || quad > 4)
  {
    clog << "range error: ";
    cout << "expected quadrant value to be an integer from 1 to 4, received " << quad << endl;
    exit(132);
  }

  hyp = sqrt((opp*opp) + (adj*adj));
  printEquations(
          hyp,
          (opp > 0) && (quad == 3 || quad == 4) ? -opp : opp,
          (adj > 0) && (quad == 2 || quad == 3) ? -adj : adj,
          name
          );
}
