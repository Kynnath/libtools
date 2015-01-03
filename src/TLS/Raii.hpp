/* 
 * File:   Raii.hpp
 * Author: JoPe
 *
 * Created on 27 de diciembre de 2014, 13:38
 */

#ifndef RAII_HPP
#define	RAII_HPP

namespace tls
{
  template <typename T, typename U>
  class Raii
  {
    T m_resource;
    U m_destructor;
    
    public:
      Raii(T t, U u);
      ~Raii();
      operator T();
  };
  
  template <typename T, typename U>
  Raii::Raii(T t, U u)
  : m_resource {t}
  , m_destructor {u}
  {}
  
  Raii::~Raii()
  {
    m_destructor(m_resource);
  }
  
  Raii::operator T()
  {
    return m_resource;
  }
  
  template <typename T, typename U>
  Raii<T,U> AcquireResource(T t, U u)
  {
    return Raii<T,U>(t,u);
  }
}

#endif	/* RAII_HPP */

