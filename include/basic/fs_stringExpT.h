﻿/*********************************************************************

 Copyright (C) 2010 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.	

*********************************************************************/
/**
 * @defgroup FSLayer Foxit Support Layer
 */

/*@{*/

/**
 * @addtogroup FSSTRING
 * @{
 */

/**
 * @file
 * @brief Foxit strings.
 */

#ifndef FS_STRINGEXPT_H
#define FS_STRINGEXPT_H

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FS_ByteString */
#ifndef FS_BYTESTRING
#define FS_BYTESTRING
/**
 * @brief An object preparing a byte buffer.
 *
 * You can use this object to store a byte stream, but you can use it with a character string.
 * See <a>FSByteStringNew</a>, <a>FSByteStringNew2</a>, <a>FSByteStringNew3</a>, <a>FSByteStringNew4</a>, <a>FSByteStringDestroy</a>.
 */
typedef struct _t_FS_ByteString* FS_ByteString;
#endif
/* @OBJEND */


/* @OBJSTART FS_WideString */
#ifndef FS_WIDESTRING
#define FS_WIDESTRING
/**
 * @brief An object used to store unicode characters.
 * 
 * On Windows platforms, a wide string is represented by UTF-16LE encoding;
 * On Unix/Linux platforms, a wide string is represented by UCS-4 encoding.
 * See <a>FSWideStringNew</a>, <a>FSWideStringNew2</a>, <a>FSWideStringNew3</a>, <a>FSWideStringDestroy</a>.
 */
typedef struct _t_FS_WideString* FS_WideString;
#endif
/* @OBJEND */

/* @COMMONSTART */
/* @TYPEDEFSTART */
#ifndef FS_STRSIZE
#define FS_STRSIZE
/** @brief String size is limited to 2^31-1. */
typedef int FS_StrSize;
#endif

/* @TYPEDEFEND */

/* @DEFGROUPSTART FSFormatingFlags */
/**
 * @brief The formating flags.
 */

/*@{*/
/** @brief For formating integer: the value is signed. */
#define FS_FORMAT_SIGNED		1

/** @brief For formating integer: using hexadecimal  format */
#define FS_FORMAT_HEX			2	
	
/** @brief For formating integer: using with FS_FORMAT_HEX to produce capital hexadecimal letters */
#define FS_FORMAT_CAPITAL		4
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKSTART FSCharmapGetWideString */
/**
 * @brief A pointer type to GetWideString function.
 *
 * The function converts a byte string to a wide string according a  character mapper.
 * @param[in] mapper		The char mapper for converting.
 * @param[in] bstr			A byte string to convert.
 * @param[out] outWstr		The result string.
 * @return void
 * @note
 */
typedef void (*FSCharmapGetWideString)(FS_CharMap mapper, FS_ByteString bstr, FS_WideString* outWstr);
/* @CALLBACKEND */

/* @CALLBACKSTART FSCharmapGetByteString */
/**
 * @brief A pointer type to GetByteString function.
 *
 * The function converts a wide string to a byte string according a  character mapper.
 * @param[in] mapper		The char mapper for converting.
 * @param[in] wstr			A wide string to convert.
 * @param[out] outBstr		The result string.
 * @return void
 * @note
 */
typedef void (*FSCharmapGetByteString)(FS_CharMap mapper, FS_WideString wstr, FS_ByteString* outBstr);
/* @CALLBACKEND */

/* @COMMONEND */


#ifdef __cplusplus
};
#endif

#endif
/** @} */

/*@}*/