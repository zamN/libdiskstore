#include <iostream>
#include <fstream>
#include "store.h"
#include "yaml-cpp/yaml.h"

int main(void) {
  // Sets up parser object for config file
  std::ifstream fin("config.yml");
  YAML::Parser parser(fin);
  YAML::Node doc;
  parser.GetNextDocument(doc);

  // Reads the path to write the blocks to in the filesystem
  std::string write_path;
  int file_count;
  doc["write-path"] >> write_path;
  doc["file-count"] >> file_count;

  // Checks if we can write to that path
  if (access(write_path.c_str(), W_OK) == -1) {
    std::cout << "No write access for directory: " << write_path << std::endl;
    return -1;
  }
  
  // Creates store object and tests functions
  Store s(write_path, file_count);
  int new_count = s.open();

  YAML::Emitter emitter;
  emitter << YAML::BeginMap;
  for(YAML::Iterator it = doc.begin(); it != doc.end(); ++it) {
    emitter << YAML::Key << it.first();
    emitter << YAML::Value;
    if(it.first().to<std::string>() == "file-count")
     emitter << new_count;
    else
        emitter << it.second();
  }
  emitter << YAML::EndMap;

  std::fstream config("config.yml", std::ios::out | std::ios::trunc);
  config << emitter.c_str();

  return 0;
}
