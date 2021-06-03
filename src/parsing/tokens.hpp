#ifndef TOKENS_H
#define TOKENS_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

// The main composition of the token list
struct Token {
    string literal_val;
    string id;
};

// Makes referencing the struct Token easier
typedef struct Token Token;

// The list of tokens and their ids
Token Token_List[29] = {
    // Declarations
    (Token){"$", "Declarator"},
    (Token){"dec", "Function"},
    (Token){"var", "Variable"},
    (Token){"class", "Class"},
    // Operators
    (Token){"+", "Plus"},
    (Token){"-", "Minus"},
    (Token){"/", "Divide"},
    (Token){"*", "Multiply"},
    (Token){"%", "Modulo"},
    (Token){"=", "Equal"},
    // Containers
    (Token){"{", "L-Brace"},
    (Token){"}", "R-Brace"},
    (Token){"[", "L-Bracket"},
    (Token){"]", "R-Bracket"},
    (Token){"(", "L-Paren"},
    (Token){")", "R-Paren"},
    // Comparators
    (Token){"==", "Equal-To"},
    (Token){"!=", "Not-Equal-To"},
    (Token){">=", "Greater-Than-Equal"},
    (Token){"<=", "Less-Than-Equal"},
    (Token){">", "Greater-Than"},
    (Token){"<", "Less-Than"},
    // Characters
    (Token){"abcdefghijklmnopqrstuvwxyz", "Letter"},
    (Token){"1234567890", "Number"},
    // Strings
    (Token){"\"", "Quote"},
    (Token){"'", "Quote"},
    // Extras
    (Token){";", "Semicolon"},
    (Token){" ", "Space"},
    (Token){"_", "Underscore"}
};

// Gets the type of a provided token
Token Type(string token) {
    // Checks for all types exept for number and letter
    for(int i = 0; i < 29; i++) {
        if(Token_List[i].literal_val == token) {
            return Token_List[i];
        }
    }

    // Checks for type number or letter
    string abcs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "1234567890";
    if(abcs.find(token) != string::npos) {
        return (Token){token, "Letter"};
    } else if(numbers.find(token) != string::npos) {
        return (Token){token, "Number"};
    }
}

#endif