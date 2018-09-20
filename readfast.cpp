/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfast.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:15:17 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/22 17:25:33 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include "parse.hpp"

int main(int ac, char **av)
{
    Parse obj;
    Factory fac;
    std::string str;
    int instructions;

    instructions = 0;
    try
    {
        while (str != ";;")
        {
            std::getline(std::cin, str);
            instructions = obj.getWords(str);
            if (str.size() > 0 && str[0] != ';')
            {
                if (instructions == 1)
                {
                    obj.check_for_command(str);
                    if (str.compare("push") == 0 || str.compare("assert") == 0)
                        throw Exception("Error: incomplete instruction");
                    else
                    {
                        if (str.compare("pop") == 0)
                            fac.pop(fac._operand);
                        else if (str.compare("dump") == 0)
                            fac.dump(fac._operand);
                        else if (str.compare("add") == 0)
                            fac.add();
                        else if (str.compare("sub") == 0)
                            fac.sub();
                        else if (str.compare("mul") == 0)
                            fac.mul();
                        else if (str.compare("div") == 0)
                            fac.div();
                        else if (str.compare("mod") == 0)
                            fac.mod();
                        else if (str.compare("print") == 0)
                            fac.print();
                        else if (str.compare("exit") == 0)
                            return (0);
                    }
                }
                else
                {
                    bool l = obj.readStd(str);
                    std::string com = obj.get_command();
                    if (com.compare("push") == 0)
                        fac.push(fac.createOperand(obj.get_type(), obj.get_value()));
                    else if (com.compare("assert") == 0)
                        fac.assert(fac.createOperand(obj.get_type(), obj.get_value()));
                }
            }
        }
    }
    catch (Exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}