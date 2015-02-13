/*
 * gradient_descent
 * use the method of gradient descent to find the minimum of the function
 * f(x, y) = 5x^2/9 - 8xy/9 - 56x/9 + 5y^2/9 + 52y/9 + 164/9
 *
 * gradient descent algorithm
 * repeat until convergence {
 *		/theta at j := /theta at j - /alpha (partial derivative / partial derivitave (alpha at j) of J(/theta 0, theta 1)
 *	}
 *	where alpha is the given learning rate
 *
 *	AUTHOR: BRYAN TANNER
 *	DATE:	JUNE 3, 2013
 *
 */

#include <print.hpp>
#include <cmath>

int main () {
	double const learning_rate{ 0.1 };	// the rate at which the gradient_descent is approached
	double const threshold{ 0.000001 };	// the cutoff value for finding the gradient descent
	double x_previous{ !0 };			// temporary storage to update x
	double y_previous{ !0 };			// temporary storage to update y
	double x_current{ 0 };				// the updated x
	double y_current{ 0 };				// the updated y
	
	(void)learning_rate;
	size_t i{ 1 };
	size_t const max_iterations{ 1024 };	// max iterations of the cycle and then terminate because it wasn't found
	while ( i <= max_iterations && threshold < sqrt( pow(x_current-x_previous, 2) + pow(y_current-y_previous, 2) ) ) {
		
		std::cout << i << ": ( " << x_current << ", " << y_current << " )\n";

		x_previous = x_current;
		y_previous = y_current;
		
		// x|y current = x|y previous - alpha * partial derivative with respect to x|y
		x_current = x_previous - learning_rate * ((2.0 / 9.0) * ((5.0 * x_previous) - 4.0 * (y_previous + 7.0)));
		y_current = y_previous - learning_rate * ((-2.0 / 9.0) * ((4.0 * x_previous - 5.0 * y_previous - 26.0)));
		
		++i;
		
	}
	std::cout << i << ": ( " << x_current << ", " << y_current << " )\n";
}
