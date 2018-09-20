/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:36:16 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/22 13:43:59 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HPP
# define PARSE_HPP
#include <fstream>
#include <vector>
#include "Exception.hpp"
#include <string>
#include "algorithm"
#include <regex>
#include "Factory.hpp"
#include "IOperand.hpp"

class Parse {

    public:
        Parse();
        Parse(Parse const & rhs);
        Parse & operator=(Parse const & rhs);
        ~Parse();

        bool                        readTheLine(std::string filename);
        bool                        readStd(std::string &str);
        void                        ft_value(void);
        void                        assign_type(void);
        void                        Overflow(std::string type, std::string value);
        void                        check_for_error(void);
        void                        check_for_bracket(std::string line, std::string del);
        void                        check_for_type(std::string & valtype);
        void                        check_for_command(std::string & comm);
        void                        choose_funtion(std::string &comm);
        int                         getWords(std::string const &words);
        eOperandType                get_type(void);
        std::string                 get_value(void);
        std::string                 get_command(void);
        std::string                 getLine(int n) const;
        std::string                 toUpper(std::string & s);
        std::string                ft_split(std::string line, std::string delim);

        
    
    private:
        
        std::string                _line;
        std::string                _command;
        std::string                _type;
        std::string                _value;
        eOperandType               _typ;
        std::vector<std::string>    validInstr; 
        std::vector<std::string>    validType;

}; 
#endif