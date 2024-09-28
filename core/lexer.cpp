// lexer.cpp

#include "./includes/lexer.hpp"

Token createToken(const std::string &value, TokenType type)
{
    return { value, type };
}

bool isAlpha(const std::string& src) {
    for (char ch : src) {
        if (!std::isalpha(static_cast<unsigned char>(ch))) 
            return false;
    }
    return true;
}

inline bool isSkippable(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r';
}

inline bool isInt(char ch) {
    return std::isdigit(static_cast<unsigned char>(ch));
}

std::vector<Token> Tokenize(const std::string &sourceCode) {
    std::vector<Token> tokens;
    tokens.reserve(sourceCode.size() / 2); 

    auto it = sourceCode.begin();
    auto end = sourceCode.end();

    while (it != end) {
        char ch = *it;

        switch (ch) {
            case '(':
                tokens.push_back({ "(", TokenType::OpenParen });
                ++it;
                break;

            case ')':
                tokens.push_back({ ")", TokenType::CloseParen });
                ++it;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                tokens.push_back({ std::string(1, ch), TokenType::BinaryOperator });
                ++it;
                break;

            case '=':
                tokens.push_back({"=", TokenType::Equals});
                ++it;
                break;

            case ';':
                tokens.push_back({";", TokenType::Semicolon});
                ++it;
                break;

            case ':':
                tokens.push_back({":", TokenType::Colon});
                ++it;
                break;

            case ',':
                tokens.push_back({",", TokenType::Comma});
                ++it;
                break;

            default:
                if (isInt(ch)) {
                    std::string num;

                    while (it != end && isInt(*it)) {
                        num += *it;
                        ++it;
                    }

                    tokens.push_back({num, TokenType::Number});
                } 

                else if (std::isalpha(static_cast<unsigned char>(ch))) {
                    std::string ident;

                    while (it != end && std::isalpha(static_cast<unsigned char>(*it))) {
                        ident += *it;
                        ++it;
                    }

                    auto keywordIt = KEYWORDS.find(ident);
                    
                    if (keywordIt != KEYWORDS.end()) 
                        tokens.push_back({ident, keywordIt->second});
                    
                    else 
                        tokens.push_back({ident, TokenType::Identifier});
                    
                } 
                
                else if (isSkippable(ch)) 
                    ++it;  
                
                else {
                    std::cerr << "Unrecognized character found in source: " << static_cast<int>(ch) << " (" << ch << ")" << std::endl;
                    exit(1);
                }

                break;
        }
    }

    tokens.push_back({"EndOfFile", TokenType::_EOF});
    return tokens;
}