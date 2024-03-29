/*
 * PLATFORMTYPES.h
 *
 * Created: 7/30/2023 2:23:57 AM
 *  Author: Ahmed Aref Omaira
 */ 


#ifndef PLATFORMTYPES_H_
#define PLATFORMTYPES_H_

/**************************************************
 *                                                *
 *           PLATFORM TYPES TYPEDEFS              *
 *                                                *
 **************************************************/
/**************************************************
 *          Basic Data Types Typedefs             *
 **************************************************/
/*********** Unsigned integer data types **********/
typedef unsigned char               uint8_t;
typedef unsigned short              uint16_t;
typedef unsigned int                uint32_t;
typedef unsigned long long int      uint64_t;

/************ Signed integer data types ***********/
typedef signed char                 sint8_t;
typedef signed short                sint16_t;
typedef signed int                  sint32_t;
typedef signed long long int        sint64_t;

/******* Volatile unsigned integer data types ******/
typedef volatile unsigned char              vuint8_t;
typedef volatile unsigned short             vuint16_t;
typedef volatile unsigned int               vuint32_t;
typedef volatile unsigned long long int     vuint64_t;

/******** Volatile signed integer data types *******/
typedef volatile signed char                vsint8_t;
typedef volatile signed short               vsint16_t;
typedef volatile signed int                 vsint32_t;
typedef volatile signed long long int       vsint64_t;

/**************** Float data types ****************/
typedef float       float32_t;
typedef double      float64_t;


/**************************************************
 *     Pointer to Basic Data Types Typedefs       *
 **************************************************/
/***** Pointer to unsigned integer data types *****/
typedef unsigned char*               ptr_uint8_t;
typedef unsigned short*              ptr_uint16_t;
typedef unsigned int*                ptr_uint32_t;
typedef unsigned long long int*      ptr_uint64_t;

/****** Pointer to signed integer data types ******/
typedef signed char*                 ptr_sint8_t;
typedef signed short*                ptr_sint16_t;
typedef signed int*                  ptr_sint32_t;
typedef signed long long int*        ptr_sint64_t;

/*** Pointer to volatile unsigned integer data types ***/
typedef volatile unsigned char*              ptr_vuint8_t;
typedef volatile unsigned short*             ptr_vuint16_t;
typedef volatile unsigned int*               ptr_vuint32_t;
typedef volatile unsigned long long int*     ptr_vuint64_t;

/*** Pointer to volatile signed integer data types ****/
typedef volatile signed char                ptr_vsint8_t;
typedef volatile signed short               ptr_vsint16_t;
typedef volatile signed int                 ptr_vsint32_t;
typedef volatile signed long long int       ptr_vsint64_t;

/********** Pointer to float data types ************/
typedef float       ptr_float32_t;
typedef double      ptr_float64_t;

/************* Pointer to functions ***************/
typedef void(*ptr_VoidFunctionVoid_t)(void);


/**************************************************
 *         Boolean Data Types Typedefs            *
 **************************************************/
typedef enum
{
	FALSE,
	TRUE
}bool_t;



/**************************************************
 *                                                *
 *          GENERIC MACROS DEFINITION             *
 *                                                *
 **************************************************/
#define FAIL		(uint8_t)(0)
#define SUCCESS		(uint8_t)(1)
#define NULL		(uint8_t)(0)

#define HIGH		(0b1)
#define LOW			(0b0)


#endif /* PLATFORMTYPES_H_ */
