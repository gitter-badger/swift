/**
 * @file   Rule.hpp
 * @author Sean Allred <code@seanallred.com>
 * @date   Tue Sep 30 23:57:26 2014
 *
 * @brief  Data model for a SWIFT rule
 */
#include <vector>
using namespace std;
class Rule
{
public:
  Rule();
  virtual ~Rule();

  ///
  string
  identifier;

  string
  name;

  list<string>
  authors;

  string
  script;

  map<string, string>
  arguments;

};
