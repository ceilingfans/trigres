/*
 * awned 2021
 */

#ifndef TRIGRES_UTIL_H
#define TRIGRES_UTIL_H

#include <string>
#include <array>

using namespace std;

bool isNumber(const string& p_s);
array<double, 2> removeDoubleNegatives(double p_n, double p_d);
void printEquations(const double &p_hyp, const double &p_opp, const double &p_adj, const string &p_name);
void printUsage();
void printVersion();
void printHelp(const string &opt);
void parseArguments(int argc, char* argv[]);
#endif /* TRIGRES_UTIL_H */