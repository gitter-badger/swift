#include <vector>

#include "Process.hpp"

/**
 * @file   ProcessGroup.hpp
 * @author Sean Allred <tex@seanallred.com>
 * @date   Thu Oct  2 00:51:06 2014
 *
 * @brief  Multi-threaded \class Process collection
 *
 *
 */
class ProcessGroup
{
private:
  std::vector<Process> processes(3, Process.NO_OP);
public:
  ProcessGroup();
  virtual ~ProcessGroup();
  void AddProcess(string command);
  void AddProcess(Process p);
  std::vector<int> Run();
};
