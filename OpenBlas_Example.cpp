#include <cblas.h>
#include <stdio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <chrono>
#include <vector>


using std::cout;
using std::cin;
using std::endl;
using std::vector;

typedef vector<double>::iterator vectype;

void matrix_mult(vectype A, size_t A_height, size_t A_width, 
	vectype B, size_t B_height, size_t B_width, 
	vectype AB)
{


	assert(A_width == B_height); // algebraic condition for matrix multiplication
	auto m = static_cast<int>(A_height);
	auto n = static_cast<int>(B_width);
	auto k = static_cast<int>(A_width);
	k = static_cast<int>(B_height);
	double alpha = 1.0; 
	double beta = 0.0;  

	// http://www.netlib.org/lapack/explore-html/d7/d2b/dgemm_8f.html
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, alpha, &*A, k, &*B, n, beta, &*AB, n);

}


#define N 1000
#define K 1000
#define M 1000

int main()
{
	vector<double> A(M*K, 0.0);
	vector<double> B(K*N, 0.0);
	vector<double> C(M*N, 0.0);

	int i, n = N, k = K, m = M; 


	for (i = 0; i < (m*k); i++) {
		A[i] = (double)rand() / RAND_MAX + 1.0;
	}

	for (i = 0; i < (k*n); i++) {
		B[i] = (double)rand() / RAND_MAX  + 1.0;
	}

	for (i = 0; i < (m*n); i++) {
		C[i] = 0.0;
	}

auto start = std::chrono::system_clock::now();
	matrix_mult(A.begin(), m, k, B.begin(), k, n, C.begin());
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;
		std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

  	//cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans,3,3,2,1,A, 3, B, 3,2,C,3);

  	return 0;
}

