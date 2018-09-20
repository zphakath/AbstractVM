/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:42:04 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/17 23:16:59 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
# define FLOAT_HPP
# include "IOperand.hpp"
# include <sstream>
#include  <string>
#include "Exception.hpp"
#include "Factory.hpp"

class Float_class : public IOperand{

    protected:
        int          _precision;
        std::string  _value;
        eOperandType _typ;

    public:
        Float_class(void);
        Float_class(std::string value);
        Float_class(Float_class  const & rhs);
        Float_class & operator=(Float_class const & rhs);
        ~Float_class();

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