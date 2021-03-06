#ifndef Soundex_h
#define Soundex_h

#include <string>
#include <unordered_map>

class Soundex
{
public:
   static const size_t MaxCodeLength{4};

   std::string encode(const std::string& word) const {
      return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
   }

private:
   char lower(char c) const {
      return std::tolower(static_cast<unsigned char>(c));
   }

   std::string head(const std::string& word) const {
      return word.substr(0, 1);
   }

   std::string tail(const std::string& word) const {
      return word.substr(1);
   }

   const std::string NotADigit{"*"};

   std::string encodedDigits(const std::string& word) const {
	   std::string encoding;

	   encodeHead(encoding, word);
	   encodeTail(encoding, word);
	   return encoding;
   }

   void encodeHead(std::string& encoding, const std::string& word) const{
	   encoding += encodedDigit(word.front());
   }

   void encodeTail(std::string& encoding, const std::string& word) const{
      auto lastLetter = word.front();

      for (auto letter:tail(word))
      {
         if (!isComplete(encoding)) {
		 encodeLetter(encoding, letter, lastLetter);
	 }
	 lastLetter = letter;
      }
   }

   void encodeLetter(std::string& encoding, char letter, char lastLetter ) const {
	 auto digit = encodedDigit(letter);
	 if (digit != NotADigit && (digit != lastDigit(encoding) || isVowel(lastLetter)))
	 {
            encoding += digit;
	 }
   }

   bool isVowel(char letter) const {
	   return std::string("aeiouy").find(lower(letter)) != std::string::npos;
   }

   std::string lastDigit(const std::string& encoding) const {
      if (encoding.empty()) return NotADigit;
      return std::string(1, encoding.back());
   }

   bool isComplete (const std::string& encoding) const {
      return encoding.length() == MaxCodeLength;
   }

   std::string encodedDigit(char letter) const {
      const std::unordered_map<char, std::string> encodings {
         {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
         {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                     {'s', "2"}, {'x', "2"}, {'z', "2"},
         {'d', "3"}, {'t', "3"},
         {'l', "4"},
         {'m', "5"}, {'n', "5"},
         {'r', "6"}
      };
      auto it = encodings.find(lower(letter));
      return it == encodings.end() ? NotADigit : it->second;
   }

   std::string zeroPad(const std::string& word) const {
      auto zerosNeeded = MaxCodeLength - word.length();
      return word + std::string(zerosNeeded, '0');
   }

   std::string upperFront(const std::string& string) const {
      return std::string(1, 
            std::toupper(static_cast<unsigned char>(string.front())));
   }
};

#endif
