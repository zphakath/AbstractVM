/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zodwa <zodwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:03:55 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/19 01:06:00 by zodwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.hpp"

Int8_class::Int8_class(){
    return;
}

Int8_class::Int8_class(std::string str) :_value(str){
    return;
}
Int8_class::Int8_class(Int8_class const &rhs){
    *this = rhs;
    return;
}

Int8_class & Int8_class::operator=(Int8_class const &rhs){

    this->_precision = rhs.getPrecision();
    this->_typ = rhs.getType();
    return *this;
}

int         Int8_class::getPrecision(void) const{
    return INT8;
}
eOperandType Int8_class::getType(void) const{
    return INT8;
}

std::string const & Int8_class::toString(void) const{
    return _value;
}

IOperand const * Int8_class::operator+(IOperand const & rhs) const {
    Factory obj;
    std::string result;

    int val = static_cast<int>(std::stoi(this->toString())); // original

    if (rhs.getPrecision( )> 2){

        if (rhs.getPrecision( )== 3){
            float fvalue = static_cast<float>(std::stod(rhs.toString()));
            float fsum = val + fvalue;
            std::stringstream ss;
            ss << fsum;
            result = ss.str();
        }
        else if (rhs.getPrecision()== 4){
            double dvalue = static_cast<double>(std::stod(rhs.toString()));
            double dsum = val + dvalue;
            std::stringstream ss;
            ss << dsum;
            result = ss.str();
        }
    }
    else{
            int value = static_cast<int>(std::stoi(rhs.toString()));
            int sum = val + value;
            std::stringstream ss;
            ss << sum;
            result = ss.str();
    }

    if(this->getPrecision() < rhs.getPrecision())
        return (obj.createOperand(rhs.getType(), result));
    
    return (obj.createOperand(this->getType(), result)); 
    
}

IOperand const * Int8_class::operator-(IOperand const & rhs) const {
    
    Factory obj;
    std::string result;

    int val = static_cast<int>(std::stoi(this->toString())); // original

    if (rhs.getPrecision( )> 2){

        if (rhs.getPrecision( )== 3){
            float fvalue = static_cast<float>(std::stod(rhs.toString()));
            float fsum = val - fvalue;
            std::stringstream ss;
            ss << fsum;
            result = ss.str();
        }
        else if (rhs.getPrecision( )== 4){
            double dvalue = static_cast<double>(std::stod(rhs.toString()));
            double dsum = val - dvalue;
            std::stringstream ss;
            ss << dsum;
            result = ss.str();
        }
    }
    else{
            int value = static_cast<int>(std::stoi(rhs.toString()));
            int sum = val - value;
            std::stringstream ss;
            ss << sum;
            result = ss.str();
    }

    if(this->getPrecision() < rhs.getPrecision())
        return (obj.createOperand(rhs.getType(), result));
    
    return (obj.createOperand(this->getType(), result)); 
    
}

IOperand const * Int8_class::operator*(IOperand const & rhs) const {
    
        Factory obj;
        std::string result;

    int val = static_cast<int>(std::stoi(this->toString())); // original

    if (rhs.getPrecision( )> 2){

        if (rhs.getPrecision( )== 3){
            float fvalue = static_cast<float>(std::stod(rhs.toString()));
            float fsum = val * fvalue;
            std::stringstream ss;
            ss << fsum;
            result = ss.str();
        }
        else if (rhs.getPrecision() == 4){
            double dvalue = static_cast<double>(std::stod(rhs.toString()));
            double dsum = val * dvalue;
            std::stringstream ss;
            ss << dsum;
            result = ss.str();
        }
    }
    else{
            int value = static_cast<int>(std::stoi(rhs.toString()));
            int sum = val * value;
            std::stringstream ss;
            ss << sum;
            result = ss.str();
    }

    if(this->getPrecision() < rhs.getPrecision())
        return (obj.createOperand(rhs.getType(), result));
    
    return (obj.createOperand(this->getType(), result)); 
    
}

IOperand const * Int8_class::operator/(IOperand const & rhs) const {
    Factory obj;
    std::string result;

    int val = static_cast<int>(std::stoi(this->toString())); // original

    if (rhs.getPrecision() > 2){

        if (rhs.getPrecision() == 3){
            float fvalue = static_cast<float>(std::stod(rhs.toString()));
            float fsum = val / fvalue;
            std::stringstream ss;
            ss << fsum;
            result = ss.str();
        }
        else if (rhs.getPrecision() == 4){
            double dvalue = static_cast<double>(std::stod(rhs.toString()));
            double dsum = val / dvalue;
            std::stringstream ss;
            ss << dsum;
            result = ss.str();
        }
    }
    else{
            int value = static_cast<int>(std::stoi(rhs.toString()));
            int sum = val / value;
            std::stringstream ss;
            ss << sum;
            result = ss.str();
    }

   if(this->getPrecision() < rhs.getPrecision())
        return (obj.createOperand(rhs.getType(), result));
    
    return (obj.createOperand(this->getType(), result)); 
}

IOperand const * Int8_class::operator%(IOperand const & rhs) const {
    
    Factory obj;
    std::string result;

    int val = static_cast<int>(std::stoi(this->toString())); // original

    if (rhs.getPrecision() > 2){
        throw Exception("Error: trying to mode a Float or double ");
    }
    else{
            int value = static_cast<int>(std::stoi(rhs.toString()));
            int sum = val % value;
            std::stringstream ss;
            ss << sum;
            result = ss.str();
    }

    if(this->getPrecision() < rhs.getPrecision())
        return (obj.createOperand(rhs.getType(), result));
    
    return (obj.createOperand(this->getType(), result));
    
} 

Int8_class::~Int8_class(){
    return;
}
