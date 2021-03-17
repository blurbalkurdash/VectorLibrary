/*
 *	Author: Thomas Holle
 *	Date: 18/12/2020
 * 	
 * 	The implementation of a data structure to represent vectors over the real 
 *  numbers and implementations of associated functions to operate on such vectors.
 */

#include "vector.h"

struct vectorstruct{
	int dimension;
	double* elements;
};

vector_t* newVector(int dimension){
	vector_t* vector = malloc(sizeof(vector_t));
	if(vector == NULL){return NULL;}
	vector->dimension = dimension;
	vector->elements = malloc(dimension * sizeof(double));
	return vector;
}

vectorstatus_e deleteVector(vector_t* vector){
	if(vector == NULL){return NULL_POINTER_ERROR;}
	free(vector->elements);
	free(vector);
	return OK;
}

vectorstatus_e set_element(vector_t* vector,int index, double element){
	if(vector == NULL){return NULL_POINTER_ERROR;}
	if(index >= vector->dimension){return DIMENSION_ERROR;}
	vector->elements[index] = element;
	return OK;
}

vectorstatus_e get_element(vector_t* vector,int index, double* element){
	if(vector == NULL || element == NULL){return NULL_POINTER_ERROR;}
	if(index >= vector->dimension){return DIMENSION_ERROR;}
	*element = vector->elements[index];
	return OK;
}
vectorstatus_e get_dim(vector_t* vector,int*result){
	if(vector == NULL || result ==NULL){return NULL_POINTER_ERROR;}
	*result = vector->dimension;
	return OK;
}

vectorstatus_e printVector(vector_t* vector){
	if(vector == NULL){return NULL_POINTER_ERROR;}

	printf("<");
	int dim = vector->dimension;
	for(int i=0; i < dim; i++){
		printf("%0.3f",vector->elements[i]);
		if(i != dim - 1){printf(",");}
	}
	printf(">\n");

	return OK;
}

vectorstatus_e vectorAdd(vector_t* a, vector_t* b, vector_t* result){
	if(a == NULL || b == NULL || result == NULL){return NULL_POINTER_ERROR;}
	int dim = a->dimension;
	if(b->dimension != dim || result->dimension != dim){return DIMENSION_ERROR;}
	
	for(int i=0; i<dim; i++){
		result->elements[i] = a->elements[i] + b->elements[i];
	}

	return OK;
}

vectorstatus_e vectorSubtract(vector_t* a, vector_t* b, vector_t* result){
	if(a == NULL || b == NULL || result == NULL){return NULL_POINTER_ERROR;}
	int dim = a->dimension;
	if(b->dimension != dim || result->dimension != dim){return DIMENSION_ERROR;}
	
	for(int i=0; i<dim; i++){
		result->elements[i] = a->elements[i] - b->elements[i];
	}

	return OK;
}

vectorstatus_e scalarMultiply(vector_t* a, double b, vector_t* result){
	if(a == NULL || result == NULL){return NULL_POINTER_ERROR;}

	int dim = a->dimension;
	for(int i=0; i<dim; i++){
		result->elements[i] = a->elements[i] * b;
	}
	
	return OK;
}

vectorstatus_e scalarDivide(vector_t* a, double b, vector_t* result){
	if(a == NULL || result == NULL){return NULL_POINTER_ERROR;}
	if(b == 0){return VALUE_ERROR;}
	int dim = a->dimension;
	if(result->dimension != dim){return DIMENSION_ERROR;}
	
	for(int i=0; i<dim; i++){
		result->elements[i] = a->elements[i] / b;
	}

	return OK;
}

vectorstatus_e dotProduct(vector_t* a, vector_t* b, double* result){
	if(a == NULL || b == NULL || result == NULL){return NULL_POINTER_ERROR;}
	int dim = a->dimension;
	if(b->dimension != dim){return DIMENSION_ERROR;}

	*result = 0;
	for(int i=0; i<dim; i++){
		*result += (a->elements[i] * b->elements[i]);
	}

	return OK;
}

vectorstatus_e crossProduct(vector_t* a, vector_t* b, vector_t* result){
	if(a == NULL || b == NULL || result == NULL){return NULL_POINTER_ERROR;}
	if(a->dimension != 3 || b->dimension != 3 || result->dimension != 3){return DIMENSION_ERROR;}

	result->elements[0] = (a->elements[1] * b->elements[2]) - (a->elements[2] * b->elements[1]);
	result->elements[1] = (a->elements[2] * b->elements[0]) - (a->elements[0] * b->elements[2]);
	result->elements[2] = (a->elements[0] * b->elements[1]) - (a->elements[1] * b->elements[0]);

	return OK;
}

vectorstatus_e magnitude(vector_t* vector, double* result){
	if(vector == NULL || result == NULL){return NULL_POINTER_ERROR;}
	*result = 0;
	for(int i=0; i<vector->dimension;i++){
		*result += vector->elements[i] * vector->elements[i];
	}
	*result = sqrt(*result);
	return OK;
}

vectorstatus_e normalise(vector_t* vector, vector_t* result){
	if(vector == NULL || result == NULL){return NULL_POINTER_ERROR;}
	double norm;
	vectorstatus_e status = magnitude(vector,&norm);
	if(status != OK){return status;}
	return scalarDivide(vector,norm,result);
}
