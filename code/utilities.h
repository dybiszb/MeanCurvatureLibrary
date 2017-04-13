#ifndef UTILITIES_H
#define UTILITIES_H

#include <Eigen/Core>
#include <fstream>

namespace mcurv {

    /**
     * The procedure used only as unary functor for Eigen's matrix.
     *
     * @param x ----
     * @return  -1.0 if provided value is negative and 1.0 when it is >= 0
     */
    double calculateMultiplier(const double x);

    /**
     * Saves provided matrix in a file. Each line contains the matrix's row
     * values separated by single whitespace.
     *
     * @param m    Matrix to save.
     * @param path Path to a file.
     */
    void dumpMatrixXdToFile(const Eigen::MatrixXd& m, const std::string& path);
}


#endif
