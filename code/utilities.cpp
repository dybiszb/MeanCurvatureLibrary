#include "utilities.h"

namespace mcurv {

    // -------------------------------------------------------------------------
    double calculateMultiplier(const double x) {
        return (x < 0) ? -1.0 : 1.0;
    }

    // -------------------------------------------------------------------------
    void dumpMatrixXdToFile(const Eigen::MatrixXd& m, const std::string& path) {
        std::ofstream file(path);
        if (file.is_open())
        {
            file << m << '\n';
        } else {
            throw std::runtime_error("Error: could not open " + path);
        }
    }

}