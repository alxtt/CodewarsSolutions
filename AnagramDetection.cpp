/*An anagram is the result of rearranging the letters of a word to produce a new word.
Note: anagrams are case insensitive

Complete the function to return true if the two arguments given are anagrams of each other; return false otherwise.
*/

// Есть решение за o(n) с контейнерами

#include <string>

boolisAnagram(std::string test, std::string original)
{
    std::transform(test.begin(), test.end(), test.begin(), [](unsigned char c){ return std::tolower(c); });
    std::transform(original.begin(), original.end(), original.begin(), [](unsigned char c){ return std::tolower(c); });
    std::sort(test.begin(), test.end());
    std::sort(original.begin(), original.end());
    return ((test == original) ? 1 : 0);
}
