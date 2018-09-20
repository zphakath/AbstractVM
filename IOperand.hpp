/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:20:01 by zphakath          #+#    #+#             */
/*   Updated: 2018/07/20 17:12:28 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP
#include <iostream>

enum eOperandType{INT8, INT16, INT32,FLOAT , DOUBLE};

class IOperand {

public:

virtual int getPrecision( void ) const = 0;
virtual eOperandType getType( void ) const = 0;
virtual IOperand const * operator+( IOperand const & rhs ) const = 0;
virtual IOperand const * operator-( IOperand const & rhs ) const = 0;
virtual IOperand const * operator*( IOperand const & rhs ) const = 0;
virtual IOperand const * operator/( IOperand const & rhs ) const = 0;
virtual IOperand const * operator%( IOperand const & rhs ) const = 0;
virtual std::string const & toString( void ) const = 0;
virtual ~IOperand( void ) {}
};
#endif