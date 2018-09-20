/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int16.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:40:32 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/17 23:04:45 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT16_HPP
# define INT16_HPP
# include "IOperand.hpp"
# include <sstream>
#include  <string>
#include "Exception.hpp"
#include "Factory.hpp"

class Int16_class : public IOperand{

    protected:
        int          _precision;
        std::string  _value;
        eOperandType _typ;

    public:
        Int16_class(void);
        Int16_class(std::string value);
        Int16_class(Int16_class const & rhs);
        Int16_class & operator=(Int16_class const & rhs);
        ~Int16_class();

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