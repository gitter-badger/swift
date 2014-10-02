#include <vector>

/**
 * @file   Process.hpp
 * @author Sean Allred <tex@seanallred.com>
 * @date   Thu Oct  2 00:45:31 2014
 *
 * @brief  A single-threaded process controller
 *
 *
 */
class Process
{
private:
  std::string command;

public:
  static const Process NO_OP("");
  Process(std::string command);
  virtual ~Process();

  std::string ToString() const;
  const std::string GetCommand() const;

  void Run(int *exit_code) const;

  friend std::ostream& operator<<(std::ostream&, const Process&);
};
