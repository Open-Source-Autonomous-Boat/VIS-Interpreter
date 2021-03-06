#include <iostream>
#include <memory>
#include <string>

#include "../VISFile.h"
#include "../VISInfo.h"
#include "../VISParser.h"
#include "../VISTypes.h"

int main(int argc, char** argv) {
  VISFile* file = new VISFile(argv[1]);
  VISParser* parser = new VISParser();
  std::cout << file->GetFilePath() << std::endl;
  parser->OpenFile(file);
  return 0;
}
