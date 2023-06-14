
#include <iostream>
#include <memory>

#include "cxxopts.hpp"

int parse(int argc, const char* argv[]) {
  try {
    cxxopts::Options options(argv[0], " - example command line options");
    options.positional_help("[optional args]").show_positional_help();

    options.add_options()("i,input", "Input", cxxopts::value<std::string>(),
                          "INPUT CESHI")("help", "Print help");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
      std::cout << options.help({""}) << std::endl;
      return true;
    }

    if (result.count("input")) {
      std::cout << "Input = " << result["input"].as<std::string>() << std::endl;
    }

  } catch (const cxxopts::exceptions::exception& e) {
    std::cout << "error parsing options: " << e.what() << std::endl;
    return false;
  }

  return true;
}

int main(int argc, const char* argv[]) {
  if (!parse(argc, argv)) {
    return 1;
  }

  return 0;
}
