/* 
 * File:   iterator.hpp
 * Author: JoPe
 *
 * Created on 22 de diciembre de 2014, 21:15
 */

#ifndef ITERATOR_HPP
#define	ITERATOR_HPP

namespace tls
{
  template <typename T>
  typename T::const_iterator cbegin(T const& t)
  {
    return t.cbegin();
  }
  
  template <typename T>
  typename T::const_iterator cend(T const& t)
  {
    return t.cend();
  }
}

#endif	/* ITERATOR_HPP */

