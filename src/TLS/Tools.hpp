/*
 * File:   Tools.hpp
 * Author: JoPe
 *
 * Created on 7 de junio de 2014, 13:56
 */

#ifndef TOOLS_HPP
#define	TOOLS_HPP

#include <string>

namespace tls
{
    int BitsToBytes( int const& i_bits );
    int UCharArrayLEToInt( unsigned char const*const i_char, int const& i_arrayLength );
    std::u32string Utf32FromUtf8( std::string const& i_utf8 );
    std::string StringFromFile(std::ifstream & io_file);
}

#endif	/* TOOLS_HPP */

