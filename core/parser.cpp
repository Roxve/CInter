#include "parser.hpp"

bool Parser::not_EOF() const
{
    return !tokens.empty() && tokens[0].type != TokenType::_EOF;
}

Token Parser::at() const
{
    return tokens.front();
}

Token Parser::eat()
{
    Token previous = tokens.front();
        
    tokens.erase(tokens.begin());
        
    return previous;
}

Token Parser::expect(TokenType type, std::string &err)
{
    Token previous = eat();
    
    if (previous.type != type) {
        std::cerr << "Parser Error:\n" << err << " - Expecting: " << static_cast<int>(type) << std::endl;
        
        exit(1); 
    }
    return previous;
}

Program Parser::produceAST(std::string &sourceCode)
{

}
