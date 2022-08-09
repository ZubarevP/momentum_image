#include <filesystem>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <sstream>

namespace fs  = std::filesystem;

int main() {

  std::vector<std::string> container;

  for(auto& dir : fs::recursive_directory_iterator(fs::current_path())) {

    std::string absolut_path = dir.path().string();
    std::string file_name = absolut_path.substr(absolut_path.find_last_of("/") + 1);
    if(file_name.find(".jpg") != std::string::npos ) {
      container.push_back(file_name); 
    }
  }

  for(const auto& file : container) {
    std::string name_with_dot = file.substr(0, file.find(".") + 1);
    std::istringstream stream("cwebp -q 70 " + file + " -o " + name_with_dot + "webp");

    std::system(stream.str().c_str());
  }
  std::system("rm *.jpg");
  return 0;
}
