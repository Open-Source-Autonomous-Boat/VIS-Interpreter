#include "VISTypes.h"

#include <iterator>
#include <memory>
#include <string>
#include <variant>
#include <vector>

#ifdef __cplusplus


void visl_cpp::tokens_struct::ReplaceFunc(std::function<void(visl_cpp::tokens_func)> a_func) {
  this->m_func = a_func;
}
std::string visl_cpp::tokens_struct::GetName() const { return this->m_name; }

void visl_cpp::tokens_struct::Exec(visl_cpp::tokens_func a_args) const {
  this->m_func(a_args);
}

VISLTokens::VISLTokens(visl_cpp::tokens_map a_tokens_base) {
  this->m_tokens = a_tokens_base;
}

bool VISLTokens::IsEmpty() const {
  return this->m_tokens.empty();
}

std::vector<std::string> VISLTokens::GetAllNames() const {
  visl_cpp::tokens_map::const_iterator i = this->m_tokens.cbegin();
  std::vector<std::string> names = {};
  for (;i != this->m_tokens.cend(); ++i) {
    names.push_back(i->second.GetName());
  }
  return names;
}

visl_tokens VISLTokens::GetToken(std::string a_value) const {
  visl_cpp::tokens_map::const_iterator i = this->m_tokens.cbegin();
  for (; i != this->m_tokens.cend(); ++i) {
    if (i->second.GetName() == a_value) {
      return i->first;
    }
  }
  return visl_tokens::visl_emp;
}

struct visl_cpp::tokens_struct VISLTokens::Get(visl_tokens a_token) const {
  return this->m_tokens.find(a_token)->second;
}

#endif
