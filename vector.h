#ifndef _VECTOR_H_
#define _VECTOR_H_ 
#include <stdlib.h> 
#include <math.h> 
#include <stdio.h>

/*
*	A data structure representing vectors over the real numbers. Individual elements
*	of these vectors are represented as doube precision floating point numbers.
*/
typedef struct vectorstruct vector_t;

typedef enum vectorstatusenum{
	OK,
	DIMENSION_ERROR,
	VALUE_ERROR,
	NULL_POINTER_ERROR,
} vectorstatus_e;

/*
 * Creates a new vector of dimenson specified by input argument. In order to 
 * free memory, calls to this function must be followed by a corrosponding call 
 * to the: "deleteVector(vector_t* vector)" function.
 */
vector_t* newVector(int dimension);

/*
 * Frees the memory occupied by the vector pointed to by input: "vector".
 * a corrosponding call to this function must be made whenever a vector is created
 * using the: "newVector(int dimension)" function.
 * 
 * On successful execution, returns: "OK"
 * If NULL pointer is passed, returns: "NULL_POINTER_ERROR".
 */
vectorstatus_e deleteVector(vector_t* vector);

/*
 * Outputs a formatted representation of the vector pointed to by input: "vector"
 * to stdout.
 * 
 * On successful execution, returns:"OK"
 * If NULL pointer is passed, returns: "NULL_POINTER_ERROR"
 */
vectorstatus_e printVector(vector_t* vector);

/*
 * Sets the vector element at the input: "index" of the vector pointed to 
 * by input: "vector" to the input:"element".
 * 
 * On successful execution, returns:"OK"
 * If NULL pointer is passed, returns:"NULL_POINTER_ERROR"
 */
vectorstatus_e set_element(vector_t* vector,int index, double element);

/*
 * Stores the vector element at the input: "index" of the vector pointed to 
 * by input: "vector" in the variable pointed to by input:"element".
 * 
 * On successful execution, returns:"OK"
 * If NULL pointer is passed, returns:"NULL_POINTER_ERROR"
 */
vectorstatus_e get_element(vector_t* vector,int index, double* element);


/*
 * Stores the dimension of the vector pointed to by input: "vector" to the
 * memory address pointed to by input: "result"
 */
vectorstatus_e get_dim(vector_t* vector, int* result);

/*
 *
 */
vectorstatus_e vectorAdd(vector_t* a, vector_t* b, vector_t* result);

/*
 *
 */
vectorstatus_e vectorSubtract(vector_t* a, vector_t* b, vector_t* result);

/*
 *
 */
vectorstatus_e scalarMultiply(vector_t* a, double b, vector_t* result);

/*
 *
 */
vectorstatus_e scalarDivide(vector_t* a, double b, vector_t* result);

/*
 *
 */
vectorstatus_e dotProduct(vector_t* a, vector_t* b, double* result);

/*
 *
 */
vectorstatus_e crossProduct(vector_t* a, vector_t* b, vector_t* result);

/*
 *
 */
vectorstatus_e magnitude(vector_t* vector, double* result);

/*
 *
 */
vectorstatus_e normalise(vector_t* vector, vector_t* result);

#endif
