/*
 * File:   Union.hpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 01:44
 */

#ifndef UNION_HPP
#define	UNION_HPP

#include <type_traits>

namespace tls
{
    template < std::size_t i_size, std::size_t i_alignment >
    struct Memory
    {
        enum
        {
            Size = i_size,
            Alignment = i_alignment
        };
    };

    template < typename ... Types >
    class Union;

    template < typename T > // Single type case
    class Union< T >
    {
        char m_buffer[ sizeof(T) ]; // Size has to be ( size of largest element in union + ( size of largest element - size of largest element % largest alignment )

        public:
            Union ( T const& t );
            ~Union();
            T const& Get() const;
    };

    template < typename T, typename ... Types > // Recursive definition
    class Union< T, Types... >
        : public Union< Types... >
    {

    };

    ////////////////////////////////////////////////////////////////////////////
    template < typename T >
    Union<T>::Union( T const& t )
    {
        new ( m_buffer ) T ( t );
    }

    template < typename T >
    Union<T>::~Union()
    {
        reinterpret_cast<T*>( m_buffer )->~T();
    }

    template < typename T >
    T const& Union<T>::Get() const
    {
        return *reinterpret_cast<T const*>( m_buffer );
    }
}

#endif	/* UNION_HPP */

