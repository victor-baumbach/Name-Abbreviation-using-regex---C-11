#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

std::string abbrevName(std::string name);

int main() {
  std::cout << "Hello World!\n";
  std::cout << abbrevName("Sam Harris");
}

std::string abbrevName(std::string name)
{
  std::regex search("\\b(\\w)\\w*\\b");
  std::smatch match;
  std::string abbreviated_name;

  auto matches = std::sregex_iterator(name.begin(), name.end(), search);

  // match = *matches++;
  // output << match.str(1);
  // match = *matches;
  // output << "." << match.str(1);

  // std::string abbreviated_name = output.str();
  match = *matches++;
  abbreviated_name = match.str(1);
  match = *matches;
  abbreviated_name = abbreviated_name + "." + match.str(1);
  std::to_string(*matches);

  std::transform(abbreviated_name.begin(), abbreviated_name.end(), abbreviated_name.begin(), ::toupper);
  return abbreviated_name;
}