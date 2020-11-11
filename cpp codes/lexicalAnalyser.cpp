#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
 * keywords
 */
vector<string> keywords
{
    "int", "string", "using", "namespace", "std" , "char", "return", "while", "if", "else"
};

/*
 * separators
 */
vector<string> separators{",", ";", "{", "}", "(", ")"};

/*
 * judge if vector contains a specific string
 */
bool vector_contains(vector<string> &v, string str)
{
    return (find(v.begin(), v.end(), str) != v.end());
}

/*
 * token :
 *  (token_type,int line_num,string value)
 */
enum class token_type
{
    identifiers,
    keywords,
    separators,
    operators,
    literals,
    comments
};
ostream &operator<<(ostream &out, token_type type)
{
    switch (type)
    {
    case token_type::identifiers:
        cout << "identifiers";
        break;
    case token_type::keywords:
        cout << "keywords";
        break;
    case token_type::separators:
        cout << "separators";
        break;
    case token_type::operators:
        cout << "operators";
        break;
    case token_type::literals:
        cout << "literals";
        break;
    case token_type::comments:
        cout << "comments";
        break;
    }
}
struct token
{
    token_type type;
    int line_num;
    string value;
    token(token_type type, int line_num, string value)
    {
        this->type = type;
        this->line_num = line_num;
        this->value = value;
    }
};
ostream &operator<<(ostream &out, token t)
{
    cout << '('
         << right << setw(15) << t.type
         << " | "
         << internal << setw(4) <<t.line_num
         << " | "
         << left << setw(18) << t.value
         << ')';
}

/*
 * used to save generated tokens
 */
vector<token> tokens;

/*
 * read srcCode and generate token
 */
void generate_token();

/*
 *  Program Entry
 */
int main(int argc, char const *argv[])
{
    generate_token();
    return 0;
}

void generate_token()
{
    cout << "please input source code path:";
    string path = "src";
    cin >> path;
    ifstream in;
    in.open(path, ios_base::in);
    int line_num{1};

    //current character
    char ch;
    //next char
    char nextch;
    //current word
    string word{};

    //parse source code and generate tokens
    while (in.get(ch))
    {
        word = "";
        //ignore macro declaration
        if (ch == '#')
        {
            while (in.get(ch) && ch != '\n')
                ;
            line_num++;
        }
        //when read a linefeed,line_num++
        else if (ch == '\n')
        {
            line_num++;
        }
        //skip space and tab
        else if (ch == ' ' || ch == '\t')
        {
            nextch = in.peek();
            while(nextch == ' ' || nextch == '\t')
            {
                in.get();
                nextch = in.peek();
            }
        }
        //parse identifier
        else if (isalpha(ch) || ch == '_')
        {
            word += ch;
            nextch = in.peek();
            //if next character is alphabet or number
            while (isalnum(nextch) || nextch == '_')
            {
                in.get(ch);
                word += ch;
                nextch = in.peek();
            }
            if (vector_contains(keywords, word))
                tokens.push_back(token(token_type::keywords, line_num, word));
            else
                tokens.push_back(token(token_type::identifiers, line_num, word));
        }
        //parse number literal
        //three kinds: dec(123) hex(0x123) oct(017)
        else if (isdigit(ch))
        {
            word += ch;
            if (ch > '0')
            {
                //dec number

                //read value
                while (isdigit(in.peek()))
                {
                    in.get(ch);
                    word += ch;
                }
            }
            else if (tolower(in.peek()) == 'x')
            {
                //hex number

                //read x character
                in.get(ch);
                word += ch;
                //read value
                nextch = in.peek();
                while (isdigit(nextch) || (tolower(nextch) >= 'a' && tolower(nextch) <= 'f'))
                {
                    in.get(ch);
                    word += ch;
                    nextch = in.peek();
                }
            }
            else
            {
                //oct number
                //read value
                nextch = in.peek();
                while (nextch >= '0' && nextch <= '7')
                {
                    in.get(ch);
                    word += ch;
                    nextch = in.peek();
                }
            }
            tokens.push_back(token(token_type::literals, line_num, word));
        }
        //parse string literal
        else if (ch == '"')
        {
            //read first "
            word += ch;
            while (in.get(ch) && ch != '"')
                word += ch;
            //read last "
            word += ch;
            tokens.push_back(token(token_type::literals, line_num, word));
        }
        //parse character literal
        else if (ch == '\'')
        {
            //read first '
            word += ch;
            //parse 'a' or '\n'
            while (in.get(ch) && ch != '\'')
            {
                word += ch;
            }
            //read last '
            word += ch;

            tokens.push_back(token(token_type::literals, line_num, word));
        }
        //parse operators
        else if (ch == '/')
        {
            //parse /,/=,//
            word += ch;
            if (in.peek() == '/')
            {
                //comments
                getline(in, word);
                //just for reading
                string content = word.substr(1, 15);
                content += "...";
                tokens.push_back(token(token_type::comments, line_num, content));
                continue;
            }
            else if (in.peek() == '=')
            {
                in.get(ch);
                word += ch;
            }
            tokens.push_back(token(token_type::operators, line_num, word));
        }
        else if (ch == '=')
        {
            // parse =,==
            word += ch;
            if (in.peek() == '=')
            {
                in.get(ch);
                word += ch;
            }
            tokens.push_back(token(token_type::operators, line_num, word));
        }
        else if (ch == '+')
        {
            //parse +,++,+=
            word += ch;
            nextch = in.peek();
            if (nextch == '+' || nextch == '=')
            {
                in.get(ch);
                word += ch;
            }
            tokens.push_back(token(token_type::operators, line_num, word));
        }
        else if (ch == '-')
        {
            //parse -,-,-=
            word += ch;
            nextch = in.peek();
            if (nextch == '-' || nextch == '=')
            {
                in.get(ch);
                word += ch;
            }
            tokens.push_back(token(token_type::operators, line_num, word));
        }
        else if (ch == '!')
        {
            //parse !=
            word += ch;
            if (in.peek() == '=')
            {
                in.get(ch);
                word += ch;
            }
            tokens.push_back(token(token_type::operators, line_num, word));
        }
        else if (ch == '<')
        {
            //parse <,<<,<=
            word += ch;
            nextch = in.peek();
            if (nextch == '<' || nextch == '=')
            {
                in.get(ch);
                word += ch;
            }
            tokens.push_back(token(token_type::operators, line_num, word));
        }
        else if (ch == '>')
        {
            //parse >,>>,>=
            word += ch;
            nextch = in.peek();
            if (nextch == '>' || nextch == '=')
            {
                in.get(ch);
                word += ch;
            }
            tokens.push_back(token(token_type::operators, line_num, word));
        }
        else if (ch == '|')
        {
            //parse |,||
            word += ch;
            if (in.peek() == '|')
            {
                in.get(ch);
                word += ch;
            }
            tokens.push_back(token(token_type::operators, line_num, word));
        }
        else if (ch == '&')
        {
            //parse &,&&
            word += ch;
            if (in.peek() == '&')
            {
                in.get(ch);
                word += ch;
            }
            tokens.push_back(token(token_type::operators, line_num, word));
        }
        else if (ch == '^' || ch == '*' || ch == '%')
        {
            word += ch;
            if (in.peek() == '=')
            {
                in.get(ch);
                word += ch;
            }
            tokens.push_back(token(token_type::operators, line_num, word));
        }
        //parse separators
        else if (vector_contains(separators, string(1, ch)))
        {
            word += ch;
            tokens.push_back(token(token_type::separators, line_num, word));
        }
        //error
        else
        {
            cout << "undefined word at line: " << line_num << ",when reading " << ch
            << " ,the nextchar: "<< (char)(in.peek()) << endl;
            //skip this line
            while(in.get(ch) && ch != '\n');
        }
    }

    //redirect cout
    streambuf *origin = cout.rdbuf();
    ofstream out("out",ios_base::out);
    cout.rdbuf(out.rdbuf());

    //output result
    //title
    cout << '('
         << right << setw(15) << "Token_type"
         << " | "
         << internal << setw(4) << "Line"
         << " | "
         << left << setw(18) << "Value"
         << ")\n";
    //content
    for (token t : tokens)
    {
        cout << t << endl;
    }

    //restore cout
    cout.rdbuf(origin);
    cout << "lex analyze finished,the result is in: ./out \n";
    //close in
    in.close();
    out.close();
}
