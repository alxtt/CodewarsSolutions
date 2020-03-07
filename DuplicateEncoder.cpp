/*The goal of this exercise is to convert a string to a new string 
where each character in the new string is "(" if that character appears only once in the original string, 
or ")" if that character appears more than once in the original string. 

Ignore capitalization when determining if a character is a duplicate.*/

#include <string.h>
#include <map>
#include <ctype.h>

std::string duplicate_encoder(const std::string& word)
{
  std::map<char, int> symbs;
  std::string ans = word;

  for (unsigned i = 0; i < word.length(); i++) {
        if (symbs.find(tolower(word[i])) == symbs.end()) {
            symbs.insert({tolower(word[i]), 1});
        } else {
            symbs[tolower(word[i])]++;
        }
  }
  
  for (unsigned i = 0; i < word.length(); i++) {
            ans[i] =  symbs[tolower(word[i])] == 1 ? '(' : ')';
  }
  
  return ans;
}
