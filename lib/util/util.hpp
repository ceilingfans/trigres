#include <string>
#include <vector>

std::vector<std::string> split_text(std::string s, const std::string& delimiter);
std::string pchar_to_string(char* s);
std::string normalize_fraction(float numerator, float denominator);

void print_equations(const float& hyp, const float& opp, const float& adj, const std::string& name = "x");