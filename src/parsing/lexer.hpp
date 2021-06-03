#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "tokens.hpp"

using namespace std;

void lex(string line) {
    vector<Token> tokens;

    for(int i = 0; i < line.length(); i++) {
        Token type = Type(string(1, line.at(i)));

        if(type.id == "Declarator") {
            tokens.push_back((Token){"$", "Declarator"});
            i++;
            //printf("%c\n", line.at(i));

            

            type = Type(string(1, line.at(i)));
            //printf("%s\n", Type(char_to_ptr(line.at(i))));
            if(type.id == "Letter") {
                if(
                    line.at(i) == 'v' && 
                    line.at(i+1) == 'a' &&
                    line.at(i+2) == 'r'
                ) {
                    i += 3;

                    tokens.push_back((Token){"var", "Variable"});                            
                } else if(
                    line.at(i) == 'd' && 
                    line.at(i+1) == 'e' &&
                    line.at(i+2) == 'c'
                ) {
                    i += 3;

                    tokens.push_back((Token){"dec", "Function"});
                } else if(
                    line.at(i) == 'c' && 
                    line.at(i+1) == 'l' &&
                    line.at(i+2) == 'a' &&
                    line.at(i+3) == 's' &&
                    line.at(i+4) == 's'
                ) {
                    i += 5;

                    tokens.push_back((Token){"class", "Class"});
                } else {
                    // Todo: Return error
                }
            } else {
                // Todo: Return error
            }
            
            type = Type(string(1, line.at(i)));

            if(type.id == "Space") {
                i++;

                if(Type(string(1, line.at(i))).id == "Letter") {
                    while(
                        Type(string(1, line.at(i))).id == "Letter" || 
                        Type(string(1, line.at(i))).id == "Number" ||
                        Type(string(1, line.at(i))).id == "Underscore"
                    ) {
                        cout << line.at(i) << endl;
                        i++;
                    }
                }
            } else {
                // Todo: Return error
            }
        }

    }
}

#endif