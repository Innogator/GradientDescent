#ifndef FILE__PRINT_HPP
#define FILE__PRINT_HPP

#include <iostream>
#include <vector>

template < size_t n >
std::ostream & operator << ( std::ostream & o, char const ( & c )[ n ] ) {
	for ( size_t i = 0; i < n - 1; ++i ) {
		o << c[ i ];
	}
	return o;
}

template < typename T, size_t n >
std::ostream & operator << ( std::ostream & o, T const ( & t )[ n ] ) {
	auto i = std::begin( t );
	auto end = std::end( t );
	o << '{';
	if ( i != end ) {
		o << ' ' << *i;
		for ( ++i; i != end; ++i ) {
			o << ", " << *i;
		}
		o << ' ';
	}
	o << '}';
	return o;
}

template < typename T, typename A >
std::ostream & operator << ( std::ostream & o, std::vector< T, A > const & v ) {
	auto i = std::begin( v );
	auto end = std::end( v );
	o << '{';
	if ( i != end ) {
		o << ' ' << *i;
		for ( ++i; i != end; ++i ) {
			o << ", " << *i;
		}
		o << ' ';
	}
	o << '}';
	return o;
}

#endif