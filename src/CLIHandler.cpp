#include <boost/program_options.hpp>

#include "CLIHandler.hpp"

void
CLI::Handlerconflicting_options(const boost::program_options::variables_map &vm,
                                const std::string &opt1,
                                const std::string &opt2)
{
  if (vm.count(opt1) && !vm[opt1].defaulted() &&
      vm.count(opt2) && !vm[opt2].defaulted())
    {
      throw std::logic_error(std::string("Conflicting options '") +
                             opt1 + "' and '" + opt2 + "'.");
    }
}

bool
CLIHandler::retrieve(int argc, char* argv[], struct arguments_t &config)
{
  try
    {
      namespace po = boost::program_options;
      po::options_description desc("Options");
      desc.add_options()
        ("help,h", "Show this message")
        ("verbose,v", "Verbose output")
        ("quiet,q", "No output")
        ("version,V", "Application version")
        ("timeout,t", "Execution timeout")
        ("language,L", "Localized language")
        ("log,l", "Create a log file")
        ("debug,d", "Debug mode");
    
      po::variables_map vm;
      try
        {
          po::store(po::parse_command_line(argc, argv, desc), vm);
          if (vm.count("help"))
            {
              std::cout << desc << std::endl;
              return SUCCESS
            }
          po::notify(vm);
        }
      catch(po::error& e)
        {
          std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
          std::cerr << desc << std::endl;
          return ERROR_IN_COMMAND_LINE;
        }
    }
  catch(std::exception& e)
    {
      std::cerr << "Unhandled Exception reached the top of main: "
                << e.what() << ", application will now exit" << std::endl;
      return ERROR_UNHANDLED_EXCEPTION;
    }
  return SUCCESS;
}
