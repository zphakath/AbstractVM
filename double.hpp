/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:42:41 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/17 23:19:14 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
# define DOUBLE_HPP
# include "IOperand.hpp"
# include <sstream>
#include  <string>
#include "Exception.hpp"
#include "Factory.hpp"

class Double_class : public IOperand{

    protected:
        int          _precision;
        std::string  _value;
        eOperandType _typ;

    public:
        Double_class(void);
        Double_class(std::string value);
        Double_class(Double_class const & rhs);
        Double_class & operator=(Double_class const & rhs);
        ~Double_class();

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