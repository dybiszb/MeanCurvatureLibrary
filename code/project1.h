#ifndef PROJECT1_H_
#define PROJECT1_H_

#include <iostream>
#include <OpenMesh/Core/IO/MeshIO.hh>

class Project1 {

public:
	// why only detected if implemented here?
	// void foo(int &i) {
	// 	i = 1;
	// }
	void foo(int &i);

};

void independentMethod(int &i);

#endif