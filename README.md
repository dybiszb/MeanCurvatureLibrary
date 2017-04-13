# Mean Curvature Library

A command line application for approximating mean curvature of a provided 3D 
model in .off format. Two approaches are available:
- Cotangent Laplace-Beltrami operator
- Uniform Laplace-Beltrami operator

## Technology:
- C++
- Google Test
- Eigen
- LibIGL
- OpenMesh

## Dependencies<a name="dependencies"></a>
Although *Eigen* and *LibIGL* libraries are provided, one need to have OpenMesh 
library installed. It can be acquired from *https://www.openmesh.org/* and installed.
The application's cmake will try to lacalize it on users's computer using
standard set of paths. 


## Building<a name="build"></a>
Note: Sources have been compiled and checked only on Ubuntu 16.04 64b with gcc 5.4.0.

- In repository main folder call following commands:

    ```
   mkdir build
   cd build
    ```
- If you want to compile without unit tests call
     ```
   cmake -Dtest=OFF ..
    ```
   Otherwise, the build will by default compile the tests, hence you can simply call
     ```
   cmake ..
    ```
- Now, run  
   ```
   make
    ```

## Usage
Single executable for the tests is located at:
```
build/testing/unit_tests/runUnitTests
```
The compiled application is located at:
```
build/code/MeanCurvatureApp
```
## Example
Please go to the directory with the compiled application and run 
```
./MeanCurvatureApp -i ../testing/unit_tests/res/bunny.off -o result.txt
```
File *result.txt* should now contain (per-vertex) mean curvature of classic 
standford bunny model. Note that *-c* flag is optional and corresponds to 
the cotangent-based operator. By default (i.e. no flag) the uniform 
operator is used.

Run *./MeanCurvatureApp -h* for the further instructions. 