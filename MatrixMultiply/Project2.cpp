/* Project2.cpp
 * Ima Student
 * EE312, Spring 2014
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include "MatrixMultiply.h"

/*
 * An example routine demonstrating the use of row-major ordering
 *
 * You do not need to use this function in your solution
 * (I didn't use it in mine!)
 *
 * given two matrices a and b, where the number of rows in b is equal
 * to the number of columns in a,
 * and given a row number 'row' and a column number 'col',
 * calculate the dot product of the row'th row from a and the col'th column from b
 *
 * recall the dot product is the sum of the element-by-element product of
 * the two vectors.
 */
double dotProduct(double a[], const uint32_t a_rows, const uint32_t a_cols,
    /* a is a matrix with a_rows rows and a_cols columns */
    double b[], const uint32_t b_cols,
    /* b is also a matrix.  It has a_cols rows and b_cols columns */
    uint32_t row, // an index of a row of a
    uint32_t col) { // an index of a column of b

        double sum = 0.0; // the result of the dot product is stored here
        uint32_t k = 0;
        while (k < a_cols) { // recall: a_cols == b_rows
            /* we need to multiply a[row, k] and b[k, col] and add that to sum */
            sum = sum + a[(row * a_cols) + k] * b[k * b_cols + col];
            /* recall a[i,j] is stored at a[(i * a_cols) + j] and b[i, j] is at b[(i * b_cols) + j] */
            k += 1;
        }

        return sum;
}

void multiplyMatrices(
        double a[],
        const uint32_t max_a_rows,
        const uint32_t max_a_cols,
        double b[],
        const uint32_t max_b_cols,
        double c[]) {

	    uint32_t rowA = 0;
	    uint32_t colB = 0;
	    uint32_t k =0;

	    while(rowA < max_a_rows){
	    	colB = 0;
	    	while(colB < max_b_cols){
	    		k=0;
	    		c[(rowA*max_b_cols)+colB] = 0;
	    		while(k < max_a_cols){
	    			c[(rowA*max_b_cols)+colB] = a[(rowA * max_a_cols) + k] + b[(k * max_b_cols) + colB];
	    			k+=1;
	    		}
	    		colB+=1;
	    	}
	    	rowA+=1;
	    }


}


#define READY_FOR_STAGE2
#ifdef READY_FOR_STAGE2

/* these three variables are used in Stage 2 to implement allocateSpace */
#define TOTAL_SPACE 10000
double memory_pool[TOTAL_SPACE];
uint32_t top_of_pool = 0;

/* you need to write this function. clearly it doesn't currently do anything */
PtrDouble allocateSpace(uint32_t size) {
	double *ptr = memory_pool + top_of_pool;
	top_of_pool = top_of_pool + size;
	return ptr;
}

void multiplyMatrixChain(
    PtrDouble matrix_list[],
    uint32_t rows[],
    uint32_t cols[],
    uint32_t num_matrices,
    double out[],
    uint32_t out_rows,
    uint32_t out_cols) {

	double* a_mat = matrix_list[0];
	uint32_t a_rows = rows[0]; // number of rows in a matrix
	uint32_t a_cols = cols[0]; // number of cols in a matrix
	uint32_t next_src = 1; // index of next matrix to multiply by
	double* b_mat;
	double* c_mat = 0;
	uint32_t b_cols;


	while (next_src < num_matrices) {
		/* Each iteration of the loop perform the following
		 * set c_mat = a_mat * b_mat where
		 * a_mat is the result from the previous iteration of the loop (or matrix_list[0] on the first iteration)
		 * b_mat is the next matrix in the matrix list
		 * c_mat is allocated space (using our handy-dandy memory allocator function) */
		b_mat = matrix_list[next_src];
		b_cols = cols[next_src];

		if(next_src - 1 != num_matrices){

		c_mat = allocateSpace(a_rows * b_cols);
		multiplyMatrices(a_mat, a_rows, a_cols, b_mat, b_cols,c_mat);
		}
		else{
			multiplyMatrices(a_mat, a_rows, a_cols, b_mat, b_cols,out);
		}


		next_src += 1;
		top_of_pool = 1;

	}
	/* when the loop completes, c_mat points to the final matrix result */

	/* don't forget to ensure that the final result matrix is put
	* into the 'out' array!!! */

	/* deallocate all memory (this only takes one line, 'cause we have such a simple memory allocator) */
}

#endif /* READY_FOR_STAGE_2 */
