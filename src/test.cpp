#include <iostream>
#include <thread>


#include "Process.hpp"

int main()
{
  std::cout << "Program started." << std::endl;
  Process p("tex --version");
  Process p2("latex --version");
  std::cout << p << std::endl << p2 << std::endl;

  int code1, code2;
  std::thread a(&Process::Run, &p, &code1);
  std::thread b(&Process::Run, &p2, &code2);

  a.join();
  b.join();
  return 0;
}
