//
// ISO8859_7Encoding.h
//
// Library: Encodings
// Package: Encodings
// Module:  ISO8859_7Encoding
//
// Definition of the Windows1252Encoding class.
//
// Copyright (c) 2018, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier: BSL-1.0
//


#ifndef Encodings_ISO8859_7Encoding_INCLUDED
#define Encodings_ISO8859_7Encoding_INCLUDED


#include "Poco/DoubleByteEncoding.h"


namespace Poco {


class Encodings_API ISO8859_7Encoding: public DoubleByteEncoding
	/// ISO-8859-7 Encoding.
	///
	/// This text encoding class has been generated from
	/// http://www.unicode.org/Public/MAPPINGS/ISO8859/8859-7.TXT.
{
public:
	ISO8859_7Encoding();
	~ISO8859_7Encoding();
	
private:
	static const char* _names[];
	static const CharacterMap _charMap;
	static const Mapping _mappingTable[];
	static const Mapping _reverseMappingTable[];
};


} // namespace Poco


#endif // Encodings_ISO8859_7Encoding_INCLUDED
