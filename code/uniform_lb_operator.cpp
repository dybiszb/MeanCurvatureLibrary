#include "uniform_lb_operator.h"

namespace mcurv {

    // -------------------------------------------------------------------------
    void uniformLBOperatorStrategy(Eigen::MatrixXd& solution,
                                   const VerticesT &vertices,
                                   const NormalsT &normals,
                                   const NeighborhoodT &neighbours,
                                   OMMeshT &omMesh) {
        Eigen::MatrixXd LB  = /* TODO: resolve const conflict*/
                uniformLBOperator(vertices, (NeighborhoodT &) neighbours) * vertices;

        Eigen::MatrixXd invertedSigns =
                (LB * normals.transpose()).diagonal() * -1.0;
        invertedSigns = invertedSigns.unaryExpr(&calculateMultiplier);

        solution = (LB.rowwise().norm()).cwiseProduct(invertedSigns);
    }


    // -------------------------------------------------------------------------
    template<typename Derived>
    SparseMatT uniformLBOperator(
            Eigen::MatrixBase<Derived> const &coordinates,
            NeighborhoodT &neighbours) {

        if (coordinates.cols() != 3)
            throw new std::runtime_error("Need 3D vertices in rows");

        std::vector<TripletT > coefficients;
        const long n = coordinates.rows();
        coefficients.reserve((unsigned long) n);


        // Coefficients
        for (int row = 0; row < n; ++row) {
            const std::set<size_t> neighIndices = neighbours[row];
            double const valance = neighIndices.size();

            for (const auto &neighIndex: neighIndices) {
                coefficients.push_back(TripletT(row, (int) neighIndex, -1.0));
            }
            coefficients.push_back(TripletT(row, row, valance));
        }

        // Sparse Matrix
        SparseMatT LBmat(n, n);
        LBmat.setFromTriplets(coefficients.begin(), coefficients.end());

        return LBmat;
    }
}
