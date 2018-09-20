/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:36:29 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/22 17:34:42 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.hpp"
#include <iostream>

Parse::Parse()
{
    this->validInstr.push_back("pop");
    this->validInstr.push_back("push");
    this->validInstr.push_back("dump");
    this->validInstr.push_back("assert");
    this->validInstr.push_back("add");
    this->validInstr.push_back("sub");
    this->validInstr.push_back("mul");
    this->validInstr.push_back("div");
    this->validInstr.push_back("mod");
    this->validInstr.push_back("print");
    this->validInstr.push_back("exit");

    this->validType.push_back("int8");
    this->validType.push_back("int16");
    this->validType.push_back("int32");
    this->validType.push_back("float");
    this->validType.push_back("double");
    return;
}

Parse::Parse(Parse const &rhs)
{
    *this = rhs;
    return;
}

Parse &Parse::operator=(Parse const &rhs)
{

    return *this;
}

Parse::~Parse()
{
    return;
}

eOperandType Parse::get_type(void)
{
    return this->_typ;
}

std::string Parse::get_command(void)
{
    return this->_command;
}

std::string Parse::get_value(void)
{
    return this->_value;
}

int Parse::getWords(std::string const &words)
{
    bool inSpaces = true;
    int numWords = 0;
    int i = 0;

    while (words[i] != '\0')
    {
        if (std::isspace(words[i]))
        {
            inSpaces = true;
        }
        else if (inSpaces)
        {
            numWords++;
            inSpaces = false;
        }

        ++i;
    }
    return numWords;
}

std::string Parse::ft_split(std::string line, std::string delimiter)
{

    size_t pos = 0;
    std::string token;

    pos = line.find(delimiter);
    token = line.substr(0, pos);
    this->_line = line.erase(0, pos + delimiter.length());
    return (token);
}

void Parse::check_for_command(std::string &comm)
{

    std::vector<std::string>::const_iterator it = std::find(validInstr.begin(), validInstr.end(), comm);

    if (!(it != validInstr.end()))
    {
        throw Exception("Syntax error :Invalid Command");
        ;
        exit(1);
    }
}

void Parse::check_for_type(std::string &valtype)
{

    std::vector<std::string>::const_iterator it = std::find(validType.begin(), validType.end(), valtype);

    if (!(it != validType.end()))
    {
        throw Exception("Syntax error :Invalid Type");
        ;
        exit(1);
    }
}

std::string Parse::toUpper(std::string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

void Parse::check_for_bracket(std::string line, std::string del)
{
    size_t pos = 0;
    pos = line.find(del);
    if (pos == std::string::npos)
    {
        throw Exception("Syntax error: Missing bracket");
        exit(1);
    }
}
void Parse::assign_type(void)
{
    if (this->_type.compare("INT8") == 0)
        this->_typ = INT8;
    else if (this->_type.compare("INT16") == 0)
        this->_typ = INT16;
    else if (this->_type.compare("INT32") == 0)
        this->_typ = INT32;
    else if (this->_type.compare("FLOAT") == 0)
        this->_typ = FLOAT;
    else if (this->_type.compare("DOUBLE") == 0)
        this->_typ = DOUBLE;
}

bool Parse::readTheLine(std::string filename)
{

    std::fstream infile;
    std::string str;
    infile.open(filename);
    {
        if (!infile)
        {
            std::cout << "Error: " << filename << " failed to opened" << std::endl;
            exit(1);
        }
    }

    while (std::getline(infile, str))
    {
        if (str.size() > 0 && str[0] != ';')
        {
            readStd(str);
        }
    }
    infile.close();

    return true;
}

void Parse::Overflow(std::string type, std::string value)
{
    long double val = stold(value);

    if (type == "INT8")
    {
        if (val > (std::numeric_limits<int8_t>::max()))
            throw Exception("Error : Overflow");
        else if (val < (std::numeric_limits<int8_t>::min()))
            throw Exception("Error : Underflow");
    }
    else if (type == "INT16")
    {
        if (val > (std::numeric_limits<int16_t>::max()))
            throw Exception("Error : Overflow");
        else if (val < (std::numeric_limits<int16_t>::min()))
            throw Exception("Error : Underflow");
    }
    else if (type == "INT32")
    {
        if (val > (std::numeric_limits<int32_t>::max()))
            throw Exception("Error : Overflow");
        else if (val < (std::numeric_limits<int32_t>::min()))
            throw Exception("Error : Underflow");
    }
    else if (type == "DOUBLE")
    {
        if (val > (std::numeric_limits<double>::max()))
            throw Exception("Error : Overflow");
        else if (val < (std::numeric_limits<double>::min()))
            throw Exception("Error : Underflow");
    }
    else if (type == "FLOAT")
    {
        if (val > (std::numeric_limits<float>::max()))
            throw Exception("Error : Overflow");
        else if (val < (std::numeric_limits<float>::min()))
            throw Exception("Error : Underflow");
    }
}

bool Parse::readStd(std::string &str)
{
    str = regex_replace(str, std::regex(" +|\t+"), " ");
    str = std::regex_replace(str, std::regex("^ +| +$|( ) +"), "$1");
    this->_line = str;
    this->_command = ft_split(this->_line, " ");
    check_for_command(this->_command);
    check_for_bracket(this->_line, "(");
    this->_type = ft_split(this->_line, "(");
    check_for_type(this->_type);
    this->_type = toUpper(this->_type);
    assign_type();
    check_for_bracket(this->_line, ")");
    this->_value = ft_split(_line, ")");
    Overflow(this->_type, this->_value);
    return true;
}
