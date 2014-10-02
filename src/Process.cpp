#include <iostream>
#include <sstream>

#include "Process.hpp"

Process::Process(std::string command)
  : command(command)
{
  std::cout << ToString() << " created" << std::endl;
}

Process::~Process() {}

std::string
Process::ToString() const
{
  std::stringstream r;
  r << "Process object ["
    << "command=\"" << GetCommand() << "\""
    << "] at " << this;
  return r.str();
}

std::ostream&
operator<<(std::ostream& s, const Process& p)
{
  return s << p.ToString();
}

const std::string
Process::GetCommand() const
{
  return command;
}

// FIXME: Should *not* be using system(); this was just a standup to
// test multithreading
void
Process::Run(int *exit_code) const
{
  *exit_code = system(command.c_str());
}
