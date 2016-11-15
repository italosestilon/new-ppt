//
// Created by estilon on 15/11/16.
//

#include "Solver.h"
#include "Configuration.h"

Solver::Solver(Model* model, Configuration configuration) : model(model) {
}

void Solver::solve() {

    Search::Options options = Search::Options();
    options.threads = configuration.threads;


    Search::Cutoff* cutoff = Search::Cutoff::rnd(clock(), 100, 1000, 20);

    Search::Stop* time_out = Search::Stop::time(configuration.timeout);

    options.stop = time_out;

    //options.cutoff = cutoff;

    BAB<Model> rbs(model, options);

    while(Model *m = rbs.next()){
        m->print();
    }
}



