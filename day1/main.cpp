#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
// The actual password is the number of times the dial is left pointing at 0
// after any rotation in the sequence.
// dial starts at 50
// dial goes 0-99 and wraps.
class dial {
public:
  int num = 50;

  void rotate(int rotations) {
    // input will be - or + when i read input in "adventDay1"
    // wrap if below 0 or above 99
    std::cout << num << " -> ";
    num = (num + rotations) % 100;
    std::cout << num << std::endl;
  }

  int getNum() { return num; }
};

int adventDay1(const std::vector<std::string> &input) {
  int res = 0;
  dial d;
  for (std::string s : input) {
    char tmp = s.front();
    int val = std::stoi(s.substr(1));
    // std::cout << val << std::endl;
    if (tmp == 'L') {
      d.rotate(-1 * val);
    } else {
      d.rotate(val);
    }
    if (d.num == 0) {
      res++;
    }
  }
  return res;
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