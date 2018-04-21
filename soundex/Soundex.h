#ifndef Soundex_h
#define Soundex_h
#include <string>

class Soundex
{
public:
   std::string encode(const std::string& word) const {
      auto encoded = word.substr(0, 1);
	  
      if (word.length() > 1)
         encoded += "1";
      return zeroPad(encoded);
   }

private:
   std::string zeroPad(const std::string& word) const {
      return word + "000";
   }
};

#endif

