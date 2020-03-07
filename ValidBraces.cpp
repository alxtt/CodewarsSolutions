/*A function that takes a string of braces, and determines if the order of the braces is valid. 
It returns true if the string is valid, and false if it's invalid.

All input strings only consist of parentheses, brackets and curly braces: ()[]{}.

A string of braces is considered valid if all braces are matched with the correct brace.*/

#include <string.h>
#include <iostream>
#include <stack>

bool valid_braces(std::string braces)
{
    std::stack<char> brackets;
    char c;

    for (int i = 0; i < braces.length(); i++) {
        if (braces[i] == '(' || braces[i] == '[' || braces[i] == '{') { brackets.push(braces[i]); }
        if (brackets.empty()) { return false; }
        
        c = brackets.top();
        
        switch (braces[i]) {
            case ')':
                brackets.pop();
                if (c == '{' || c == '[') { return false; }
            break;
            
            case '}':
                brackets.pop();
                if (c == '(' || c == '[') { return false; }
            break;

            case ']':
                brackets.pop();
                if (c == '(' || c == '{') { return false; }
            break;
        }
    }
    return (brackets.empty());
}
