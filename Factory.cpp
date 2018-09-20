/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 10:36:42 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/22 17:23:22 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

Factory::Factory()
{

    _arryFunc[0] = &Factory::createInt8;
    _arryFunc[1] = &Factory::createInt16;
    _arryFunc[2] = &Factory::createInt32;
    _arryFunc[3] = &Factory::createFloat;
    _arryFunc[4] = &Factory::createDouble;
    return;
}

Factory::Factory(Factory const &rhs)
{
    *this = rhs;
    return;
}

Factory &Factory::operator=(Factory const &rhs)
{
    (void)rhs;
    return (*this);
}
IOperand const *
Factory::createOperand(const eOperandType type, const std::string &value) const
{
    return (this->*_arryFunc[type])(value);
}
IOperand const *Factory::createInt8(std::string const &value) const
{
    IOperand const *op = new Int8_class(value);
    return op;
}
IOperand const *Factory::createInt16(std::string const &value) const
{
    IOperand const *op = new Int16_class(value);
    return op;
}
IOperand const *Factory::createInt32(std::string const &value) const
{
    IOperand *op = new Int32_class(value);
    return op;
}
IOperand const *Factory::createFloat(std::string const &value) const
{
    IOperand *op = new Float_class(value);
    return op;
}
IOperand const *Factory::createDouble(std::string const &value) const
{
    IOperand *op = new Double_class(value);
    return op;
}

void Factory::pop(std::vector<const IOperand *> &del)
{

    if (del.empty())
        throw Exception("Error: The stack is empty ");
    else
        del.pop_back();
}

void Factory::push(const IOperand *op)
{
    this->_operand.push_back(op);
}

void Factory::dump(std::vector<const IOperand *> &op) const
{
    int i = op.size() - 1;
    if (!this->_operand.empty())
    {
        while (i >= 0)
        {
            std::cout<< op[i]->toString() << std::endl;
            i--;
        }
    }
    else
        throw Exception("The stack is empty");
}

void Factory::assert(const IOperand *op)
{
    std::string str1;
    std::string str2;

    str1 = this->_operand[this->_operand.size() - 1]->toString();
    str2 = op->toString();
    if (!this->_operand.empty())
    {
        if (str1.compare(str2) != 0)
        {
            throw Exception("Error : The values doesn't match");
        }
        std::cout << "match" << std::endl;
    }
    else
        throw Exception("The stack is empty");
}

void Factory::add()
{
    IOperand const *p1;
    IOperand const *p2;
    IOperand const *sum;

    if (this->_operand.size() >= 2)
    {
        p1 = _operand[this->_operand.size() - 1];
        _operand.pop_back();
        p2 = _operand[this->_operand.size() - 1];
        _operand.pop_back();
        sum = p1->operator+(*p2);
        this->_operand.push_back(sum);
    }
    else
        throw Exception("Less than two values on the stack");
}

void Factory::sub()
{

    IOperand const *p1;
    IOperand const *p2;
    IOperand const *dif;

    if (this->_operand.size() >= 2)
    {
        p1 = _operand[this->_operand.size() - 1];
        _operand.pop_back();
        p2 = _operand[this->_operand.size() - 1];
        _operand.pop_back();
        dif = p1->operator-(*p2);
        this->_operand.push_back(dif);
    }
    else
        throw Exception("Less than two values on the stack");
}

void Factory::mul()
{

    IOperand const *p1;
    IOperand const *p2;
    IOperand const *prod;

    if (this->_operand.size() >= 2)
    {
        p1 = _operand[this->_operand.size() - 1];
        _operand.pop_back();
        p2 = _operand[this->_operand.size() - 1];
        _operand.pop_back();
        prod = p1->operator*(*p2);
        this->_operand.push_back(prod);
    }
    else
        throw Exception("Less than two values on the stack");
}

void Factory::div()
{
    IOperand const *p1;
    IOperand const *p2;
    IOperand const *res;

    if (this->_operand.size() >= 2)
    {
        p1 = _operand[this->_operand.size() - 2];
        p2 = _operand[this->_operand.size() - 1];
        _operand.pop_back();
        _operand.pop_back();
        if (p2->toString() == "0")
            throw Exception("Error : dividing by zero");
        _operand.pop_back();
        res = p1->operator/(*p2);
        this->_operand.push_back(res);
    }
    else
        throw Exception("Less than values on the stack");
}

void Factory::mod()
{
    IOperand const *p1;
    IOperand const *p2;
    IOperand const *res;

    if (this->_operand.size() >= 2)
    {
        p1 = _operand[this->_operand.size() - 1];
        _operand.pop_back();
        p2 = _operand[this->_operand.size() - 1];
        _operand.pop_back();
        res = p1->operator%(*p2);
        this->_operand.push_back(res);
    }
    else
        throw Exception("Less than values on the stack");
}

void Factory::print() const
{

    if (!this->_operand.empty())
    {

        if ((this->_operand[this->_operand.size() - 1]->getPrecision()) == 0)
        {
            int value = std::stoi(this->_operand[this->_operand.size() - 1]->toString());
            char asccival =  static_cast<char>(value);
            std::cout <<'\n'<< asccival << std::endl;
        }
        else 
            throw Exception("The values is not an assic value");
    }
    else
        throw Exception("Stack is empty");
}
