//
// Created by estilon on 15/11/16.
//

#ifndef NEW_PPT_SOLVER_H
#define NEW_PPT_SOLVER_H


#include "Model.h"
#include "Configuration.h"

class Solver {
private:
    Model* model;
    Configuration configuration;


public:
    Solver(Model* model, Configuration configuration);

    void solve();

};


#endif //NEW_PPT_SOLVER_H
