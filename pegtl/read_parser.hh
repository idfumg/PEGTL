// Copyright (c) 2014-2016 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef PEGTL_READ_PARSER_HH
#define PEGTL_READ_PARSER_HH

#include "string_parser.hh"

#include "internal/file_reader.hh"

namespace pegtl
{
   class read_parser
         : public string_parser
   {
   public:
      explicit
      read_parser( const std::string & filename )
            : string_parser( internal::file_reader( filename ).read(), filename )
      { }

      template< typename Input >
      read_parser( const std::string & filename, const Input & from )
            : string_parser( internal::file_reader( filename ).read(), filename, from )
      { }
   };

} // pegtl

#endif
