#ifndef VISPARSER_H
#define VISPARSER_H

#ifdef __cplusplus
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "VISFile.h"
#include "VISInfo.h"
#include "VISTypes.h"
#include "VISUtils.h"


constexpr char VISL_DELIMITER = ',';
constexpr char VISL_LINE_END = ';';

class VISParser {
 public:
  VISParser(VISLTokens* a_tokens_base=new VISLTokens());
  ~VISParser();
  /*
   * Opens .vis file
   * @param[in] a_file: pointer to VISFile class object
   * TODO: Should this be deprecated?
   */
  void OpenFile(VISFile* a_file);
  /* Closes .vis file */
  void CloseFile();
  /*
   * Parses independent line in VIS
   * @param[in] a_line: Line in VIS
   */
  void ParseLine(std::string a_line);

 protected:
  /*
   * Prepares VIS file
   */
  void PrepareFile();

 private:
  // Methods
  /*
   * Doesn't do anything
   * ---
   * TODO: Give it some function
   * Have it take the type from line, and parse it somewhere idk
   */
  /*
   * Actually parse it
   */
  void Parse();
  visl_tokens DetermineTypeFromLine(std::string a_line);
  // Properties
  std::vector<std::string> m_lines;
  visl_cpp::tokens_args m_tokens; // HACK: Is this ok?
  std::unique_ptr<VISLTokens> m_tokens_base;
  VISFile* m_file = nullptr;
};
#else
typedef struct VISParser VISParser;
#endif
#endif
