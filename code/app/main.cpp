#include <iostream>
#include <Eigen/Core>
#include <algorithm>
#include <memory>
#include "../mean_curvature_solver.h"
#include "../utilities.h"
#include "../uniform_lb_operator.h"
#include "../cotangent_lb_operator.h"

using SolverPtrT = std::unique_ptr<mcurv::MeanCurvatureSolver>;

char *getCmdOption(char **begin, char **end, const std::string &option) {
    char **itr = std::find(begin, end, option);
    if (itr != end && ++itr != end) {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char **begin, char **end, const std::string &option) {
    return std::find(begin, end, option) != end;
}

void printHelpMessage() {
    std::cout << "The app usage: ./MeanCurvatureApp -i path1 -o path2 -c\n";
    std::cout << "-i  Path to .off file.\n";
    std::cout << "-o  Path to user's output file.\n";
    std::cout << "-c  (OPTIONAL) If specified cotangent Laplace-Beltrami operator will be used. Otherwise the uniform one.\n";
}

int main(int argc, char **argv) {
    // If requested - print help information
    if (cmdOptionExists(argv, argv + argc, "-h") ||
        cmdOptionExists(argv, argv + argc, "--help")) {
        printHelpMessage();
        return 0;
    }

    // If input and output flags are not present - error
    if (!cmdOptionExists(argv, argv + argc, "-i") ||
        !cmdOptionExists(argv, argv + argc, "-o")) {
        printHelpMessage();
        return 1;
    }

    std::string inputFileName(getCmdOption(argv, argv + argc, "-i"));
    std::string outputFileName (getCmdOption(argv, argv + argc, "-o"));

    // Load appropriate solver
    SolverPtrT solverPtr;
    if (cmdOptionExists(argv, argv + argc, "-c")) {
        solverPtr = SolverPtrT(
                new mcurv::MeanCurvatureSolver(mcurv::cotangentLBOperatorStrategy));
    } else {
        solverPtr = SolverPtrT(
                new mcurv::MeanCurvatureSolver(mcurv::uniformLBOperatorStrategy));
    }

    // Calculate the solution
    Eigen::MatrixXd solution;
    solverPtr->Execute(solution, inputFileName);

    // Save to specified file
    mcurv::dumpMatrixXdToFile(solution, outputFileName);

    return 0;
}

