/*
 * File:   MetaFunctions.hpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 02:54
 */

#ifndef METAFUNCTIONS_HPP
#define	METAFUNCTIONS_HPP

namespace tls
{
    namespace tmp
    {
        template < bool Condition, typename True, typename False >
        struct If;

        template < typename True, typename False >
        struct If < true, True, False >
        {
            typedef True result;
        };

        template < typename True, typename False >
        struct If < false, True, False >
        {
            typedef False result;
        };

        template < typename T1, typename T2 >
        struct Largest
        {
            typedef typename If < ( sizeof(T1) > sizeof(T2) ), T1, T2 >::result type;
            enum { size = sizeof( type ) };
        };
    }
}

#endif	/* METAFUNCTIONS_HPP */

