/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zodwa <zodwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:03:34 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/19 01:06:34 by zodwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP
# include "IOperand.hpp"
# include <sstream>
#include  <string>
#include "Exception.hpp"
#include "Factory.hpp"

class Int8_class : public IOperand{

    protected:
        int          _precision;
        std::string  _value;
        eOperandType _typ;

    public:
        Int8_class(void);
        Int8_class(std::string value);
        Int8_class(Int8_class const & rhs);
        Int8_class & operator=(Int8_class const & rhs);
        ~Int8_class();

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