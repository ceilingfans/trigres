/*
 * awned 2021
 */

#ifndef TRIGRES_TRIGO_H
#define TRIGRES_TRIGO_H

#include <string>

using namespace std;

void resolveSine(const double &opp, const double &hyp, const int &quad, const string &name = "x");
void resolveCosine(const double &adj, const double &hyp, const int &quad, const string &name = "x");
void resolveTangent(const double &opp, const double &adj, const int &quad, const string &name = "x");

#endif /* TRIGRES_TRIGO_H */