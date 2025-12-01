#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

int adventDay1(const std::vector<std::string> &input) {
  // Helper method to solve the puzzle
  (void)input; // Suppress unused parameter warning

  return 0; // boilerplate for each day
}

int main() {
  std::vector<std::string> input;
  std::ifstream file("day1/input.txt");
  std::string line;

  while (std::getline(file, line)) {
    if (!line.empty()) {
      input.push_back(line);
    }
  }

  file.close();

  // Pass input vector to helper method
  std::cout << adventDay1(input) << std::endl;
  return 0;
}