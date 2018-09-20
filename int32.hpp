/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:41:06 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/17 23:07:47 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_HPP
# define INT32_HPP
# include "IOperand.hpp"
# include <sstream>
#include  <string>
#include "Exception.hpp"
#include "Factory.hpp"

class Int32_class : public IOperand{

    protected:
        int          _precision;
        std::string  _value;
        eOperandType _typ;

    public:
        Int32_class(void);
        Int32_class(std::string value);
        Int32_class(Int32_class const & rhs);
        Int32_class & operator=(Int32_class const & rhs);
        ~Int32_class();

        int getPrecision( void ) const;
        eOperandType getType( void ) const;
        IOperand const * operator+( IOperand const & rhs ) const;
        IOperand const * operator-( IOperand const & rhs ) const;
        IOperand const * operator*( IOperand const & rhs ) const;
        IOperand const * operator/( IOperand const & rhs ) const;
        IOperand const * operator%( IOperand const & rhs ) const;
        std::string const & toString( void ) const;

};
#endif