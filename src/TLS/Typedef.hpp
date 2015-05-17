/*
 * File:   Typedef.hpp
 * Author: JoPe
 *
 * Created on 17 de mayo de 2015, 19:03
 */

#ifndef TYPEDEF_HPP
#define	TYPEDEF_HPP

namespace tls
{
  template <class Type, class Unique>
  struct Typedef
  {
    Type value;
    explicit operator Type(){ return value; }
  };
}

#endif	/* TYPEDEF_HPP */

