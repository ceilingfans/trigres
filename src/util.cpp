#define TRIGRES_VERSION "0.1"

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#include "util.hpp"
#include "trigo.hpp"

using namespace std;

bool isNumber(const string& p_s)
{
  char* end = nullptr;
  double val = strtod(p_s.c_str(), &end);
  return end != p_s.c_str() && *end == '\0' && val != HUGE_VAL;
}

array<double, 2> removeDoubleNegatives(double p_n, double p_d)
{
  if (p_n < 0 && p_d < 0)
  {
    array<double, 2> result = { -p_n, -p_d };
    return result;
  }

  array<double, 2> result = { p_n, p_d };
  return result;
}

void printEquations(const double &p_hyp, const double &p_opp, const double &p_adj, const string &p_name)
{
  array<double, 2> finalSin = removeDoubleNegatives(p_opp, p_hyp);
  array<double, 2> finalCos = removeDoubleNegatives(p_adj, p_hyp);
  array<double, 2> finalTan = removeDoubleNegatives(p_opp, p_adj);

  cout << setprecision(0) << fixed;
  cout << "opp: " << p_opp << endl;
  cout << "adj: " << p_adj << endl;
  cout << "hyp: " << p_hyp << endl;

  cout << setprecision(5) << fixed;
  cout << "sin(" << p_name << ") = " << finalSin[0] << "/" << finalSin[1] << endl;
  cout << "cos(" << p_name << ") = " << finalCos[0] << "/" << finalCos[1] << endl;
  cout << "tan(" << p_name << ") = " << finalTan[0] << "/" << finalTan[1] << endl;
}

void printUsage()
{
  cout << "trigres - dogwater trigonometry helper tool\n"
          "\nUsage:\ttrigres [-v | --version] [--help] [<command> <args>]" << endl;

  cout << "\nFlags for trigres\n"
          "\thelp\t\t\t\tDisplays this message\n"
          "\tversion\t\t\t\tDisplays the version number" << endl;

  cout << "\nOptions for trigres\n"
          "\tmethod\t\t\t\tSets the method to be resolved\n"
          "\topp\t\t\t\t\tSets the opposite\n"
          "\tadj\t\t\t\t\tSets the adjacent\n"
          "\thyp\t\t\t\t\tSets the hypotenuse\n"
          "\tquad\t\t\t\tSets the quadrant\n"
          "\tname\t\t\t\tSets the variable name for the trigonometric function\t" << endl;

  cout << "\n'trigres help <option>' to get a better usage guide on the option" << endl;
}

void printVersion()
{
  cout << "trigres version " << TRIGRES_VERSION << endl;
}

void printHelp(const string &opt)
{
  if (opt == "help")
  {
    cout << "NAME\n"
            "\t--help - Displays the full help message" << endl;
    return;
  }
  else if (opt == "version" || opt == "v")
  {
    cout << "NAME\n"
            "\t{-v | --version} - Displays the version number" << endl;
    return;
  }
  else if (opt == "method" || opt == "m")
  {
    cout << "NAME\n"
            "\t{-m | -method} methodname | {-m=methodname | -method-methodname} - Sets the method to be resolved" << endl;
    return;
  }
  else if (opt == "name" || opt == "n")
  {
    cout << "NAME\n"
            "\t{-n | -name} name | {-n=name | -name=name} - Sets the name of the trigonometric function's variable" << endl;
    return;
  }
  else if (opt == "opp" || opt == "o")
  {
    cout << "NAME\n"
            "\t{-o | -opp} opposite | {-o=opposite | -opp=opposite} - Sets the opposite value" << endl;
    return;
  }
  else if (opt == "adj" || opt == "a")
  {
    cout << "NAME\n"
            "\t{-a | -adj} adjacent | {-a=adjacent | -adj=adjacent} - Sets the adjacent value" << endl;
    return;
  }
  else if (opt == "hyp" || opt == "h")
  {
    cout << "NAME\n"
            "\t{-h | -hyp} hypotenuse | {-h=hypotenuse | -hyp=hypotenuse} - Sets the hypotenuse value" << endl;
    return;
  }
  else if (opt == "quad" || opt == "q")
  {
    cout << "NAME\n"
            "\t{-q | -quad} quadrant | {-q=quadrant | -quad=quadrant} - Sets the quadrant value" << endl;
    return;
  }
  else
  {
    clog << "invalid value error: ";
    cout << "option provided is not a valid method" << endl;
    return;
  }
}

void parseArguments(int argc, char* argv[])
{
  if (argc == 1)
  {
    clog << "insufficient values error: ";
    cout << "no arguments were provided" << endl;
    exit(132);
  }

  double opp = 0,
         adj = 0,
         hyp = 0;
  int quad = 0;
  string name, method, command;

  for (int i = 1; i < argc; ++i)
  {
    char* arg = argv[i];
    char* next = argv[i+1];

    if (strcmp(arg, "-m") == 0 || strcmp(arg, "-method") == 0)
    {
      method = next;
    }
    else if (strcmp(arg, "-o") == 0 || strcmp(arg, "-opp") == 0)
    {
      if (!isNumber(next))
      {
        clog << "type error: ";
        cout << next << " is not a number" << endl;
        exit(132);
      }

      opp = stod(next);
    }
    else if (strcmp(arg, "-a") == 0 || strcmp(arg, "-adj") == 0)
    {
      if (!isNumber(next))
      {
        clog << "type error: ";
        cout << next << " is not a number" << endl;
        exit(132);
      }

      adj = stod(next);
    }
    else if (strcmp(arg, "-h") == 0 || strcmp(arg, "-hyp") == 0)
    {
      if (!isNumber(next))
      {
        clog << "type error: ";
        cout << next << " is not a number" << endl;
        exit(132);
      }

      hyp = stod(next);
    }
    else if (strcmp(arg, "-q") == 0 || strcmp(arg, "-quad") == 0)
    {
      if (!isNumber(next))
      {
        clog << "type error: ";
        cout << next << " is not a number" << endl;
        exit(132);
      }

      quad = stoi(next);
    }
    else if (strcmp(arg, "-n") == 0 || strcmp(arg, "-name") == 0)
    {
      name = next;
    }
    else if (strcmp(arg, "--help") == 0)
    {
      printUsage();
      exit(0);
    }
    else if (strcmp(arg, "-v") == 0 || strcmp(arg, "--version") == 0)
    {
      printVersion();
      exit(0);
    }
    else if (strcmp(arg, "help") == 0)
    {
      printHelp(next);
      exit(0);
    }
  }

  if (method == "sin")
  {
    if (opp == 0)
    {
      clog << "unprovided value error: ";
      cout << "the opposite value needs to be provided for the sine method, provide it with the -o option" << endl;
      exit(132);
    }
    if (hyp == 0)
    {
      clog << "unprovided value error: ";
      cout << "the hypotenuse value needs to be provided for the sine method, provide it with the -h option" << endl;
      exit(132);
    }
    if (quad == 0)
    {
      clog << "unprovided value error: ";
      cout << "the quadrant was not provided, provide it with the -q option" << endl;
      exit(132);
    }

    resolveSine(opp, hyp, quad, name);
  }
  else if (method == "cos")
  {
    if (adj == 0)
    {
      clog << "unprovided value error: ";
      cout << "the adjacent value needs to be provided for the cosine method, provide it with the -a option" << endl;
      exit(132);
    }
    if (hyp == 0)
    {
      clog << "unprovided value error: ";
      cout << "the hypotenuse value needs to be provided for the cosine method, provide it with the -h option" << endl;
      exit(132);
    }
    if (quad == 0)
    {
      clog << "unprovided value error: ";
      cout << "the quadrant was not provided, provide it with the -q option" << endl;
      exit(132);
    }

    resolveCosine(adj, hyp, quad, name);
  }
  else if (method == "tan")
  {
    if (opp == 0)
    {
      clog << "unprovided value error: ";
      cout << "the opposite value needs to be provided for the tangent method, provide it with the -o option" << endl;
      exit(132);
    }
    if (adj == 0)
    {
      clog << "unprovided value error: ";
      cout << "the adjacent value needs to be provided for the tangent method, provide it with the -a option" << endl;
      exit(132);
    }
    if (quad == 0)
    {
      clog << "unprovided value error: ";
      cout << "the quadrant was not provided, provide it with the -q option" << endl;
      exit(132);
    }

    resolveTangent(opp, adj, quad, name);
  }
  else if (method.empty())
  {
    clog << "unprovided value error: ";
    cout << "the method was not provided, provide it with the -m option" << endl;
    exit(132);
  }
  else
  {
    clog << "invalid value error: ";
    cout << method << " is not a valid method, use 'sin' or 'cos' or 'tan'" << endl;
    exit(132);
  }
}
