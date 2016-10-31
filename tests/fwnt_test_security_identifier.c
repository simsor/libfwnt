/*
 * Library security_identifier type testing program
 *
 * Copyright (C) 2009-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwnt_test_libcerror.h"
#include "fwnt_test_libcstring.h"
#include "fwnt_test_libfwnt.h"
#include "fwnt_test_macros.h"
#include "fwnt_test_memory.h"
#include "fwnt_test_unused.h"

uint8_t fwnt_test_security_identifier_byte_stream[ 28 ] = {
	0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x15, 0x00, 0x00, 0x00, 0xc7, 0x99, 0x2e, 0x25,
	0x7c, 0x57, 0x85, 0xc0, 0x94, 0x5a, 0xce, 0x01, 0xf5, 0x03, 0x00, 0x00 };

/* Tests the libfwnt_security_identifier_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_initialize(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	int result                                         = 0;

	/* Test libfwnt_security_identifier_initialize
	 */
	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_initialize(
	          NULL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	security_identifier = (libfwnt_security_identifier_t *) 0x12345678UL;

	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	security_identifier = NULL;

#if defined( HAVE_FWNT_TEST_MEMORY )

	/* Test libfwnt_security_identifier_initialize with malloc failing
	 */
	fwnt_test_malloc_attempts_before_fail = 0;

	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	if( fwnt_test_malloc_attempts_before_fail != -1 )
	{
		fwnt_test_malloc_attempts_before_fail = -1;

		if( security_identifier != NULL )
		{
			libfwnt_security_identifier_free(
			 &security_identifier,
			 NULL );
		}
	}
	else
	{
		FWNT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWNT_TEST_ASSERT_IS_NULL(
		 "security_identifier",
		 security_identifier );

		FWNT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfwnt_security_identifier_initialize with memset failing
	 */
	fwnt_test_memset_attempts_before_fail = 0;

	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	if( fwnt_test_memset_attempts_before_fail != -1 )
	{
		fwnt_test_memset_attempts_before_fail = -1;

		if( security_identifier != NULL )
		{
			libfwnt_security_identifier_free(
			 &security_identifier,
			 NULL );
		}
	}
	else
	{
		FWNT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWNT_TEST_ASSERT_IS_NULL(
		 "security_identifier",
		 security_identifier );

		FWNT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FWNT_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_security_identifier_free(
	          NULL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to copy security identifier from byte stream
	 */
	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_byte_stream,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_from_byte_stream(
	          NULL,
	          fwnt_test_security_identifier_byte_stream,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          NULL,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_byte_stream,
	          0,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_byte_stream,
	          (size_t) SSIZE_MAX + 1,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_byte_stream,
	          8,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_byte_stream,
	          28,
	          (uint8_t) 'X',
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_get_string_size function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_get_string_size(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	size_t string_size                                 = 0;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_byte_stream,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve string size
	 */
	result = libfwnt_security_identifier_get_string_size(
	          security_identifier,
	          &string_size,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_get_string_size(
	          NULL,
	          &string_size,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_get_string_size(
	          security_identifier,
	          NULL,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_get_string_size(
	          security_identifier,
	          &string_size,
	          0xffffffffUL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_copy_to_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_to_utf8_string_with_index(
     void )
{
	uint8_t utf8_string[ 64 ];

	libcerror_error_t *error                           = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	size_t utf8_string_index                           = 0;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_byte_stream,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test copy to UTF-8 string
	 */
	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          security_identifier,
	          utf8_string,
	          47,
	          &utf8_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          NULL,
	          utf8_string,
	          47,
	          &utf8_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          security_identifier,
	          NULL,
	          47,
	          &utf8_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          security_identifier,
	          utf8_string,
	          18,
	          &utf8_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          security_identifier,
	          utf8_string,
	          47,
	          NULL,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          security_identifier,
	          utf8_string,
	          47,
	          &utf8_string_index,
	          0xffffffffUL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_copy_to_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_to_utf16_string_with_index(
     void )
{
	uint16_t utf16_string[ 64 ];

	libcerror_error_t *error                           = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	size_t utf16_string_index                          = 0;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_byte_stream,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test copy to UTF-16 string
	 */
	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          security_identifier,
	          utf16_string,
	          47,
	          &utf16_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          NULL,
	          utf16_string,
	          47,
	          &utf16_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          security_identifier,
	          NULL,
	          47,
	          &utf16_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          security_identifier,
	          utf16_string,
	          18,
	          &utf16_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          security_identifier,
	          utf16_string,
	          47,
	          NULL,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          security_identifier,
	          utf16_string,
	          47,
	          &utf16_string_index,
	          0xffffffffUL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_copy_to_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_to_utf32_string_with_index(
     void )
{
	uint32_t utf32_string[ 64 ];

	libcerror_error_t *error                           = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	size_t utf32_string_index                          = 0;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_byte_stream,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test copy to UTF-32 string
	 */
	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          security_identifier,
	          utf32_string,
	          47,
	          &utf32_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          NULL,
	          utf32_string,
	          47,
	          &utf32_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          security_identifier,
	          NULL,
	          47,
	          &utf32_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          security_identifier,
	          utf32_string,
	          18,
	          &utf32_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          security_identifier,
	          utf32_string,
	          47,
	          NULL,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          security_identifier,
	          utf32_string,
	          47,
	          &utf32_string_index,
	          0xffffffffUL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_identifier",
         security_identifier );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FWNT_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FWNT_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FWNT_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FWNT_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FWNT_TEST_UNREFERENCED_PARAMETER( argc )
	FWNT_TEST_UNREFERENCED_PARAMETER( argv )

	FWNT_TEST_RUN(
	 "libfwnt_security_identifier_initialize",
	 fwnt_test_security_identifier_initialize );

	FWNT_TEST_RUN(
	 "libfwnt_security_identifier_free",
	 fwnt_test_security_identifier_free );

	FWNT_TEST_RUN(
	 "libfwnt_security_identifier_copy_from_byte_stream",
	 fwnt_test_security_identifier_copy_from_byte_stream );

	FWNT_TEST_RUN(
	 "libfwnt_security_identifier_get_string_size",
	 fwnt_test_security_identifier_get_string_size );

	/* TODO add tests for libfwnt_security_identifier_copy_to_utf8_string */

	FWNT_TEST_RUN(
	 "libfwnt_security_identifier_copy_to_utf8_string_with_index",
	 fwnt_test_security_identifier_copy_to_utf8_string_with_index );

	/* TODO add tests for libfwnt_security_identifier_copy_to_utf16_string */

	FWNT_TEST_RUN(
	 "libfwnt_security_identifier_copy_to_utf16_string_with_index",
	 fwnt_test_security_identifier_copy_to_utf16_string_with_index );

	/* TODO add tests for libfwnt_security_identifier_copy_to_utf32_string */

	FWNT_TEST_RUN(
	 "libfwnt_security_identifier_copy_to_utf32_string_with_index",
	 fwnt_test_security_identifier_copy_to_utf32_string_with_index );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}


/* Tests copying a SID to a string
 * Returns 1 if successful, 0 if not or -1 on error
 */
int fwnt_test_security_identifier_to_string(
     libfwnt_security_identifier_t *sid,
     libcstring_system_character_t *sid_string,
     size_t sid_string_size,
     uint32_t string_format_flags,
     int expected_result )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

        fprintf(
         stdout,
         "Testing copying identifier to string: 0x%08" PRIjx " of size: %" PRIzd "\t",
         (intptr_t) sid_string,
         sid_string_size );

#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
	result = libfwnt_security_identifier_copy_to_utf16_string(
		  sid,
		  (uint16_t *) sid_string,
		  sid_string_size,
		  string_format_flags,
		  &error );
#else
	result = libfwnt_security_identifier_copy_to_utf8_string(
		  sid,
		  (uint8_t *) sid_string,
		  sid_string_size,
		  string_format_flags,
		  &error );
#endif
	if( result == expected_result )
	{
		fprintf(
		 stdout,
		 "(PASS)" );
	}
	else
	{
		fprintf(
		 stdout,
		 "(FAIL)" );
	}
	fprintf(
	 stdout,
	 "\n" );

	if( result == 1 )
	{
		fprintf(
		 stdout,
		 "SID\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
		 sid_string );
	}
	if( result == -1 )
	{
		if( expected_result != -1 )
		{
			libcerror_error_backtrace_fprint(
			 error,
			 stderr );
		}
		libcerror_error_free(
		 &error );
	}
	if( result == expected_result )
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	return( result );
}
