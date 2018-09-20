/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int16.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:40:45 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/18 00:35:53 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int16.hpp"

Int16_class::Int16_class(){
    return;
}

Int16_class::Int16_class(std::string str) : _value(str){
    return;
}
Int16_class::Int16_class(Int16_class const &rhs){
    *this = rhs;
    return;
}

Int16_class & Int16_class::operator=(Int16_class const &rhs){

    this->_precision = rhs.getPrecision();
    this->_typ = rhs.getType();
    return *this;
}

int         Int16_class::getPrecision(void) const{
    return INT16;
}
eOperandType Int16_class::getType(void) const{
    return INT16;
}

std::string const & Int16_class::toString(void) const{
    return _value;
}

IOperand const * Int16_class::operator+(IOperand const & rhs) const {
    Factory obj;
    std::string result;

    int val = static_cast<int>(std::stoi(this->toString())); // original

    if (rhs.getPrecision() > 2){

        if (rhs.getPrecision() == 3){
            float fvalue = static_cast<float>(std::stod(rhs.toString()));
            float fsum = val + fvalue;
            std::stringstream ss;
            ss << fsum;
            result = ss.str();
        }
        else if (rhs.getPrecision() == 4){
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

IOperand const * Int16_class::operator-(IOperand const & rhs) const {
    
    Factory obj;
    std::string result;

    int val = static_cast<int>(std::stoi(this->toString())); // original

    if (rhs.getPrecision() > 2){

        if (rhs.getPrecision() == 3){
            float fvalue = static_cast<float>(std::stod(rhs.toString()));
            float fsum = val - fvalue;
            std::stringstream ss;
            ss << fsum;
            result = ss.str();
        }
        else if (rhs.getPrecision() == 4){
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

IOperand const * Int16_class::operator*(IOperand const & rhs) const {
    
        Factory obj;
        std::string result;

    int val = static_cast<int>(std::stoi(this->toString())); // original

    if (rhs.getPrecision() > 2){

        if (rhs.getPrecision() == 3){
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

IOperand const * Int16_class::operator/(IOperand const & rhs) const {
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

IOperand const * Int16_class::operator%(IOperand const & rhs) const {
    
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

Int16_class::~Int16_class(){
    return;
}
