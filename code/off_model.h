#ifndef OFF_MODEL_H
#define OFF_MODEL_H

#include "types_definitions.h"

namespace mcurv {

    class OFFModel {
    public:
        OFFModel(const std::string &path);

    private:
        VerticesT mVertices;
        FacesT mFaces;
    };

}


#endif
