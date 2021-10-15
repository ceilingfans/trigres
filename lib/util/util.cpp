#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "util.hpp"

using namespace std;

/*
 * Splits text using a delimiter
 * -----------------------------
 * Example:
 * std::string s = "hello world!";
 * std::string d = " ";
 * std::vector<std::string> split = split_text(s, d);
 *
 * // split will become a vector of strings that
 * // contains { "hello", "world!" }
 */
vector<string> split_text(string s, const string& delimiter) {
  vector<string>  finished_split;
  string          token;
  size_t          pos = 0;

  while ((pos = s.find(delimiter)) != string::npos) {
    token = s.substr(0, pos);
    finished_split.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  finished_split.push_back(s);

  return finished_split;
}

/*
 * Converts pointer char to string
 * -------------------------------
 * Example:
 * char* test = "hello";
 * std::string string_test = pchar_to_string(test);
 *
 * // Now string_test will become a string
 */
string pchar_to_string(char* c) {
  string str(c);
  return str;
}

void print_equations(const float& hyp, const float& opp, const float& adj, const string& name) {
  string normalized_sine    = normalize_fraction(opp, hyp);
  string normalized_cosine  = normalize_fraction(adj, hyp);
  string normalized_tangent = normalize_fraction(opp, adj);

  cout << "opp: " << opp << endl;
  cout << "adj: " << adj << endl;
  cout << "hyp: " << hyp << endl;
  cout << "sin(" << name << ") = " << normalized_sine     << endl;
  cout << "cos(" << name << ") = " << normalized_cosine   << endl;
  cout << "tan(" << name << ") = " << normalized_tangent  << endl;
}

string normalize_fraction(float numerator, float denominator) {
  string parsed_fraction;

  if (denominator < 0 && numerator < 0) {
    parsed_fraction = to_string(-1 * numerator) + "/" + to_string(-1 * denominator);
  } else {
    parsed_fraction = to_string(numerator) + "/" + to_string(denominator);
  }

  return parsed_fraction;
}