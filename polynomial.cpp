#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <iomanip>

// Define a shorthand for complex numbers
using Complex = std::complex<double>;

// Function to evaluate the polynomial P(x) at a given complex value x
// Uses Horner's method for efficiency
Complex evaluatePolynomial(const std::vector<Complex>& coeffs, Complex x) {
    Complex result = 0.0;
    for (const auto& coeff : coeffs) {
        result = result * x + coeff;
    }
    return result;
}

// The Durand-Kerner algorithm to find all roots of a polynomial
std::vector<Complex> findPolynomialRoots(std::vector<Complex> coeffs, int maxIterations = 2000, double tolerance = 1e-10) {
    int degree = coeffs.size() - 1;
    if (degree <= 0) return {};

    // Normalize the polynomial so the leading coefficient becomes 1
    Complex leadingCoeff = coeffs[0];
    for (auto& coeff : coeffs) {
        coeff /= leadingCoeff;
    }

    // Initialize the root guesses
    // We use a complex number starting point to break symmetry and find complex roots
    std::vector<Complex> roots(degree);
    Complex r(0.4, 0.9); 
    for (int i = 0; i < degree; ++i) {
        roots[i] = std::pow(r, i);
    }

    // Iteratively refine the roots
    for (int iter = 0; iter < maxIterations; ++iter) {
        double maxDiff = 0.0;
        std::vector<Complex> nextRoots = roots;

        for (int i = 0; i < degree; ++i) {
            Complex numerator = evaluatePolynomial(coeffs, roots[i]);
            Complex denominator = 1.0;

            // Calculate the product of (R_i - R_j) for all j != i
            for (int j = 0; j < degree; ++j) {
                if (i != j) {
                    denominator *= (roots[i] - roots[j]);
                }
            }

            // Calculate the correction factor and apply it
            Complex correction = numerator / denominator;
            nextRoots[i] -= correction;
            
            // Track the largest correction to know when to stop
            maxDiff = std::max(maxDiff, std::abs(correction));
        }

        roots = nextRoots;
        
        // Stop if the roots have settled (converged)
        if (maxDiff < tolerance) break;
    }

    return roots;
}

int main() {
    int degree;
    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> degree;

    if (degree < 1) {
        std::cout << "Degree must be at least 1." << std::endl;
        return 1;
    }

    std::vector<Complex> coefficients(degree + 1);
    std::cout << "Enter the " << degree + 1 << " coefficients (from highest degree to constant term):\n";
    
    for (int i = 0; i <= degree; ++i) {
        double realPart;
        std::cin >> realPart;
        coefficients[i] = Complex(realPart, 0.0);
    }

    // Ensure the leading coefficient isn't 0
    if (std::abs(coefficients[0]) == 0.0) {
        std::cout << "The leading coefficient cannot be zero." << std::endl;
        return 1;
    }

    // Calculate the roots
    std::vector<Complex> roots = findPolynomialRoots(coefficients);

    // Display the results
    std::cout << "\nThe roots are:\n";
    std::cout << std::fixed << std::setprecision(5);
    for (int i = 0; i < degree; ++i) {
        double real = roots[i].real();
        double imag = roots[i].imag();
        
        // Clean up tiny floating point errors to print absolute 0
        if (std::abs(real) < 1e-9) real = 0.0;
        if (std::abs(imag) < 1e-9) imag = 0.0;

        std::cout << "Root " << i + 1 << " = " << real;
        if (imag >= 0) std::cout << " + " << imag << "i";
        else std::cout << " - " << std::abs(imag) << "i";
        std::cout << std::endl;
    }

    return 0;
}
