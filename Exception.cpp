/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:28:20 by zphakath          #+#    #+#             */
/*   Updated: 2018/07/26 10:48:14 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exception.hpp"

Exception::Exception(){
    return;
}
 Exception::Exception(std::string msg) throw(){
  
        this->_errMsg = msg;
     return;
 }

Exception::~Exception() throw(){
    return;
}

Exception::Exception(Exception const & rhs){
    *this = rhs;
    return;
}

Exception & Exception::operator=(Exception const & rhs)
{
    (void)rhs;
    return (*this);
}

const char* Exception::what() const throw(){

    return (this->_errMsg.c_str());
}