#include <iostream>
#include <string>
#include "TipoToken.h"

using namespace std;

class token{
public:
   TipoToken type;
   string lexema;

    size_t linea;
    size_t posision;

public:
    explicit token(const string& lexema, size_t linea = 0, size_t posision = 0){
        this->lexema = lexema;
        this->type = TToken(lexema);

        this->linea = linea;
        this->posision = posision;
    }


    static TipoToken TToken(const string& lexema){
        if (lexema == "if")
            return TipoToken::IF;
        if (lexema == "else")
            return TipoToken::ELSE;
        if (lexema == "const")
            return ::CONST;
        if (lexema == "int")
            return TipoToken::INT;
        if (lexema == "char")
            return TipoToken::CHAR;
        if (lexema == "for")
            return TipoToken::FOR;
        if (lexema == "while")
            return TipoToken::WHILE;
        if (lexema == "do")
            return TipoToken::DO_WHILE;
        if (lexema == "break")
            return TipoToken::BREAK;
        if (lexema == "true")
            return TipoToken::TRUE;
        if (lexema == "false")
            return TipoToken::FALSE;
        if (lexema == ">")
            return TipoToken::GREATER;
        if (lexema == "<")
            return TipoToken::LESS;
        if (lexema == "<=")
            return TipoToken::LESS_EQUAL;
        if (lexema == ">=")
            return TipoToken::GREATER_EQUAL;
        if (lexema == "==")
            return TipoToken::EQUAL;
        if (lexema == "!=")
            return TipoToken::NOT_EQUAL;
        if (lexema == "&&")
            return TipoToken::AND;
        if (lexema == "||")
            return TipoToken::OR;
        if (lexema == "!")
            return TipoToken::EXCLAMATION;
        if (lexema == "+")
            return TipoToken::PLUS;
        if (lexema == "-")
            return TipoToken::MINUS;
        if (lexema == "*")
            return TipoToken::STAR;
        if (lexema == "/")
            return TipoToken::SLASH;
        if (lexema == "{")
            return TipoToken::LEFTBRACE;
        if (lexema == "}")
            return TipoToken::RIGHTBRACE;
        if (lexema == "(")
            return TipoToken::LEFTPAREN;
        if (lexema == ")")
            return TipoToken::RIGHTPAREN;
        if (lexema == "=")
            return TipoToken::ASSIGN;
        if (lexema == "return")
            return TipoToken::RETURN;
        if (lexema == "switch")
            return TipoToken::SWITCH;
        if (lexema == "case")
            return TipoToken::CASE;
        if (lexema == ";")
            return TipoToken::SEMICOLON;
        if (lexema == ":")
            return TipoToken::COLON;
        if (lexema == ",")
            return TipoToken::COMMA;
        if (lexema == ".")
            return TipoToken::POINT;
        if (lexema == "//")
            return TipoToken::COMMENT;

        if (pertenece_String(lexema))
            return TipoToken::STRING;


        return TipoToken::IDENTIFIER;
    }

        static bool pertenede_Integer(const string& actual)
    {
        for (const auto& symbol : actual)
            if (symbol < '0' || symbol > '9')
                return false;
        return true;
    }

    static bool pertenece_String(const string& actual)
    {
        return actual.front() == '"' && actual.back() == '"';
    }

    static bool pertence_Double(const string& actual)
    {
        bool point = false;

        for (const char& s : actual)
        {
            if (s == '.' && !point)
            {
                point = true;
                continue;
            }

            if (s == '.')
                return false;

            if (s < '0' || s > '9')
                return false;

        }

        return true;
    }

        static bool pertenecer_Char(const string& actual)
    {
        return actual.front() == '\'' && actual.back() == '\'';
    }

    void print()
    {
        cout << lexema << " tipo: \"" << TokenString(type) << "\" " <<
        "\tlinea:" << linea <<
        "\tposision:" << posision <<
        "\n";
    }


    static string TokenString(TipoToken tipo_token)
    {
        switch (tipo_token)
        {
            case TipoToken::IDENTIFIER:
            {
                return "identifier";
            }
            case TipoToken::STRING:
            {
                return "string";
            }
            case TipoToken::TRUE:
            {
                return "true";
            }
            case TipoToken::FALSE:
            {
                return "false";
            }
            case TipoToken::CONST:
            {
                return "const";
            }
            case TipoToken::INT:
            {
                return "int";
            }
            case TipoToken::CHAR:
            {
                return "char";
            }
            case TipoToken::DO_WHILE:
            {
                return "do while";
            }
            case TipoToken::WHILE:
            {
                return "while";
            }
            case TipoToken::FOR:
            {
                return "for";
            }
            case TipoToken::BREAK:
            {
                return "break";
            }
            case TipoToken::SWITCH:
            {
                return "switch";
            }
            case TipoToken::CASE:
            {
                return "case";
            }
            case TipoToken::IF:
            {
                return "if";
            }
            case TipoToken::ELSE:
            {
                return "else";
            }
            case TipoToken::LESS:
            {
                return "less";
            }
            case TipoToken::GREATER:
            {
                return "greater";
            }
            case TipoToken::LESS_EQUAL:
            {
                return "less and equal";
            }
            case TipoToken::GREATER_EQUAL:
            {
                return "greater and equal";
            }
            case TipoToken::EQUAL:
            {
                return "equal";
            }
            case TipoToken::NOT_EQUAL:
            {
                return "not equal";
            }
            case TipoToken::AND:
            {
                return "logic and";
            }
            case TipoToken::OR:
            {
                return "logic or";
            }
            case TipoToken::EXCLAMATION:
            {
                return "exclamation";
            }
            case TipoToken::PLUS:
            {
                return "plus";
            }
            case TipoToken::MINUS:
            {
                return "minus";
            }
            case TipoToken::STAR:
            {
                return "star";
            }
            case TipoToken::SLASH:
            {
                return "true";
            }
            case TipoToken::LEFTBRACE:
            {
                return "left brace";
            }
            case TipoToken::RIGHTBRACE:
            {
                return "right brace";
            }
            case TipoToken::LEFTPAREN:
            {
                return "left paren";
            }
            case TipoToken::RIGHTPAREN:
            {
                return "right paren";
            }
            case TipoToken::ASSIGN:
            {
                return "assign";
            }
            case TipoToken::FUNCTION:
            {
                return "function";
            }
            case TipoToken::RETURN:
            {
                return "return";
            }
            case TipoToken::SEMICOLON:
            {
                return "semicolon";
            }
            case TipoToken::COLON:
            {
                return "colon";
            }
            case TipoToken::COMMA:
            {
                return "comma";
            }
            case TipoToken::POINT:
            {
                return "point";
            }
            case TipoToken::COMMENT:
            {
                return "comment";
            }


            default:
                return "";
        }
    }

};