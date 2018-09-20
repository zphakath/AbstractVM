/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:28:13 by zphakath          #+#    #+#             */
/*   Updated: 2018/08/18 04:33:34 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP
#include <iostream>
#include <exception>

class Exception : public std::exception{

    public:
        Exception();
        Exception(std::string message) throw();
        virtual ~Exception() throw();
        Exception(Exception const & rhs);
        Exception & operator=(Exception const & rhs);
        virtual const char* what() const throw();

private:
    std::string _errMsg;

};
#endif