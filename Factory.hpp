/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 10:25:37 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/22 17:04:40 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
# define FACTORY_HPP
#include "parse.hpp"
#include <string>
#include <sstream>
#include "IOperand.hpp"
#include "Int8.hpp"
#include "int16.hpp"
#include "int32.hpp"
#include "float.hpp"
#include "double.hpp"




class Factory{

    

    public:
        Factory();
        Factory(Factory const & rhs);
        Factory & operator=(Factory const & rhs);
        IOperand const * 
        createOperand(const eOperandType type, const std::string &value) const;
        typedef IOperand const* (Factory::*funcptr)(const std::string &) const;
        std::vector<const IOperand *>  _operand;

        int  getNumber(int n);
        void pop(std::vector<const IOperand *> &del);
        void push(const IOperand *op);
        void dump(std::vector<const IOperand *>	&op)const;
        void assert(const IOperand *op);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void print() const;
        
    private:
        funcptr     _arryFunc[5];
        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;
};
#endif