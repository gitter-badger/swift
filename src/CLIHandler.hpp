#include <boost/program_options.hpp>

class CLIHandler
{
private:
  /**
   * Declare a pair of mutually exclusive options.
   *
   * @param vm variable map
   * @param opt1 first option
   * @param opt2 second option
   */
  void conflicting_options(const boost::program_options::variables_map &vm,
                           const std::string &opt1,
                           const std::string &opt2);

public:
  enum Exception {
    CONFLICTING
  };
  struct arguments_t {
    bool verbose;
    bool quiet;
    bool version;
    bool log;
    bool debug;
    unsigned long timeout;
    std::string language;
  };

  /**
   * Retrieve command line arguments
   *
   * @param argc parameters from main invocation
   * @param argv parameters from main invocation
   * @param config configuration buffer
   *
   * @return true if successful, false otherwise
   */
  static bool retrieve(int argc, char* argv, struct arguments_t &config);
};
