#include "cotangent_lb_operator.h"

namespace mcurv {

    // -------------------------------------------------------------------------
    void cotangentLBOperatorStrategy(Eigen::MatrixXd& solution,
                                   const VerticesT &vertices,
                                   const NormalsT &normals,
                                   const NeighborhoodT &neighbours,
                                   OMMeshT &omMesh) {
        Eigen::MatrixXd LB  =
                cotangentLBOperator(vertices, omMesh) * vertices;

        Eigen::MatrixXd invertedSigns =
                (LB * normals.transpose()).diagonal() * -1.0;
        invertedSigns = invertedSigns.unaryExpr(&calculateMultiplier);

        solution =  (LB.rowwise().norm()).cwiseProduct(invertedSigns);
    }

    // -------------------------------------------------------------------------
    template<typename Derived>
    SparseMatT
    cotangentLBOperator(
            Eigen::MatrixBase<Derived> const &coordinates,
            const OMMeshT &omMesh) {
        if (coordinates.cols() != 3)
            throw new std::runtime_error("Need 3D vertices in rows");

        std::vector<TripletT > coefficients;
        const long n = coordinates.rows();
        coefficients.reserve((unsigned long) n);
        Eigen::VectorXd areas(n, 1);

        // Iterate over vertices
        OMMeshT::VertexIter v_it, v_end(omMesh.vertices_end());
        for (v_it = omMesh.vertices_begin(); v_it != v_end; ++v_it) {

            double accumulatedNeighbourWeights = 0.0;
            double totalArea = 0.0;

            // Iterate over one-ring neighbours
            OMMeshT::ConstVertexOHalfedgeIter voh_it = omMesh.cvoh_iter(v_it);
            for (; voh_it.is_valid(); ++voh_it) {

                // Omit boundary case
                if (omMesh.is_boundary(omMesh.edge_handle(*voh_it)))
                    continue;

                // Gather information about neighbourhood
                const OMMeshT::Point currentVertex = omMesh.point(v_it);
                const OMMeshT::Point currentNeighbour =
                        omMesh.point(omMesh.to_vertex_handle(*voh_it));
                const OMMeshT::Point previousNeighbour =
                        omMesh.point(omMesh.from_vertex_handle(
                                omMesh.prev_halfedge_handle(*voh_it)));
                const OMMeshT::Point nextNeighbour = omMesh.point(
                        omMesh.to_vertex_handle(omMesh.next_halfedge_handle(
                                omMesh.opposite_halfedge_handle(*voh_it))));
                const OMMeshT::Point toCurrentNeighbour =
                        currentNeighbour - currentVertex;
                const OMMeshT::Point toNexNeighbour =
                        nextNeighbour - currentVertex;

                // Calculate the angles
                const double alpha = std::atan2(
                        ((currentVertex - previousNeighbour) %
                         (previousNeighbour - currentNeighbour)).norm(),
                        ((currentVertex - previousNeighbour) |
                         (previousNeighbour - currentNeighbour)));

                const double beta = std::atan2(
                        ((currentVertex - nextNeighbour) % (nextNeighbour -
                                                            currentNeighbour)).norm(),
                        ((currentVertex
                          - nextNeighbour) | (nextNeighbour - currentNeighbour)));

                // Calculate per neighbour weight
                const double perNeighbourWeight = (cos(alpha) / sin(alpha) +
                                                   cos(beta) / sin(beta));

                // Accumulate weight for main vertex
                accumulatedNeighbourWeights += perNeighbourWeight;

                // Accumulate area for further normalization. Note that only area
                // of triangle with beta angle (the 'next' one) is calculated and
                // as the loop go over the ring the whole area will be covered.
                areas(v_it->idx(), 0) +=
                        2.0 * 0.5 * (toCurrentNeighbour % toNexNeighbour).norm() /
                        3.0;

                // Save per neighbour weight as a sparse matrix coefficient
                coefficients.push_back(TripletT(v_it->idx(),
                                                 omMesh.to_vertex_handle(
                                                         *voh_it).idx(),
                                                 perNeighbourWeight));
            }

            // Save vertex weight as a sparse matrix coefficient
            coefficients.push_back(TripletT(v_it->idx(), v_it->idx(),
                                             -accumulatedNeighbourWeights));
        }

        // Sparse Matrix
        SparseMatT LBmat(n, n);
        LBmat.setFromTriplets(coefficients.begin(), coefficients.end());

        // Normalize
        for (int i = 0; i < n; ++i) {
            LBmat.row(i) *= 1.0 / areas(i);
        }

        return LBmat;
    }
    
}