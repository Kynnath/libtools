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
    explicit operator Type() const { return value; }

    friend bool operator==(Typedef const& lhs, Typedef const& rhs)
    {
      return lhs.value == rhs.value;
    }
    friend bool operator!=(Typedef const& lhs, Typedef const& rhs)
    {
      return !operator==(lhs,rhs);
    }
  };
}

#endif	/* TYPEDEF_HPP */

