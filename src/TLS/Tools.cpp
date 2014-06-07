/*
 * File:   Tools.cpp
 * Author: JoPe
 *
 * Created on 7 de junio de 2014, 13:56
 */

#include "Tools.hpp"

#include <cassert>

namespace tls
{
    int BitsToBytes( int const& i_bits )
    {
        return ( ( i_bits+7 ) / 8 );
    }

    int UCharArrayLEToInt( unsigned char const*const i_char, int const& i_arrayLength )
    {
        assert( i_arrayLength > 0 && i_arrayLength <= 4 );

        int result = 0;
        for( auto index = 0; index < i_arrayLength; ++index )
        {
            result |= ( i_char[index] << (8*index) );
        }
        return result;
    }
}