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
    template<int n, int m, class T>
    double DoubleFromFixedPoint(T fixed)
    {
      static_assert(n >= 0 && m >= 0, "Fixed point parts have to be positive.");
      static_assert(n+m == sizeof(T)*8, "Bad length of fixed point.");
      double constexpr divisor = (1 << m);
      T constexpr mask = divisor - 1;
      return (fixed >> m) + (fixed & mask)/divisor;
    }
}

#endif	/* TOOLS_HPP */

