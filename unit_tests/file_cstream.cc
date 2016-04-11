// Copyright (c) 2016 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#include <cstdio>

#include "test.hh"

namespace pegtl
{
   struct file_content : seq< pegtl_string_t( "dummy content" ), eol, discard > {};
   struct file_grammar : seq< rep_min_max< 11, 11, file_content >, eof > {};

   void unit_test()
   {
      ::FILE * stream = ::fopen( "unit_tests/file_data.txt", "rb" );
      assert( stream );
      TEST_ASSERT( parse_cstream< file_grammar >( stream, 16 ) );
   }

} // pegtl

#include "main.hh"
