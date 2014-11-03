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

    std::u32string Utf32FromUtf8( std::string const& i_utf8 )
    {
        std::u32string utf32;

        for ( auto byte = i_utf8.begin(); byte != i_utf8.end(); )
        {
            /*
             * Possible leading bits:
             * 0xxxxxxx - 1 byte
             * 10xxxxxx - Continuation
             * 110xxxxx - 2 bytes
             * 1110xxxx - 3 bytes
             * 11110xxx - 4 bytes
             *
             * We only need to check leading, since we know
             * where continuations are (if the file is valid utf8)
             * 4 possibilities: 2 checks
             *
             * if byte & 0xe0 == 0xe0 : 3 or 4 bytes
             *     if ( byte & 0xf0 == 0xf0 ) 4 bytes,
             *     else 3 bytes
             * else
             *     if ( byte & 0x80 == 0 ) 1
             *     else 2 bytes
             *
             * 1 byte  : character = *byte & 0x7f
             * 2 bytes : character = ((*byte & 0x1f) << 6)  | *(byte+1) & 0x3f
             * 3 bytes : character = ((*byte & 0x0f) << 12) | ((*(byte+1) & 0x3f) << 6 )  | *(byte+2) & 0x3f
             * 4 bytes : character = ((*byte & 0x07) << 18) | ((*(byte+1) & 0x3f) << 12 ) | ((*(byte+2) & 0x3f) << 6 ) | *(byte+3) & 0x3f
             *
             */
            unsigned char const lead = static_cast<unsigned char>(*byte);
            if ( (lead & 0xe0u) == 0xe0u )
            {
                if ( (lead & 0xf0u) == 0xf0u ) // 4 bytes
                {
                    utf32.push_back( ((*byte & 0x07u) << 18) | ((*(byte+1) & 0x3fu) << 12 ) | ((*(byte+2) & 0x3fu) << 6 ) | (*(byte+3) & 0x3fu));
                    byte += 4;
                }
                else // 3 bytes
                {
                    utf32.push_back( ((*byte & 0x0fu) << 12) | ((*(byte+1) & 0x3fu) << 6 ) | (*(byte+2) & 0x3fu ));
                    byte += 3;
                }
            }
            else
            {
                if ( (lead & 0x80u) == 0x00u ) // 1 byte
                {
                    utf32.push_back( *byte & 0x7fu );
                    byte += 1;
                }
                else // 2 bytes
                {
                    utf32.push_back( ((*byte & 0x1fu) << 6) | (*(byte+1) & 0x3fu));
                    byte += 2;
                }
            }
        }

        return utf32;
    }
}