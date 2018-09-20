/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:41:51 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/18 00:35:41 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.hpp"

Float_class::Float_class(){
    return;
}

Float_class::Float_class(std::string str) : _value(str){
    return;
}
Float_class::Float_class(Float_class const &rhs){
    *this = rhs;
    return;
}

Float_class & Float_class::operator=(Float_class const &rhs){

    this->_precision = rhs.getPrecision();
    this->_typ = rhs.getType();
    return *this;
}

int         Float_class::getPrecision(void) const{
    return FLOAT;
}
eOperandType Float_class::getType(void) const{
    return FLOAT;
}

std::string const & Float_class::toString(void) const{
    return _value;
}

IOperand const * Float_class::operator+(IOperand const & rhs) const {
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

IOperand const * Float_class::operator-(IOperand const & rhs) const {
    
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

IOperand const * Float_class::operator*(IOperand const & rhs) const {
    
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

IOperand const * Float_class::operator/(IOperand const & rhs) const {
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

IOperand const * Float_class::operator%(IOperand const & rhs) const {
    
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

Float_class::~Float_class(){
    return;
}
