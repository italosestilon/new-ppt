//
// Created by estilon on 14/11/16.
//

#ifndef NEW_PPT_MODEL_H
#define NEW_PPT_MODEL_H

#include <gecode/int.hh>
#include <gecode/set.hh>
#include <gecode/gist.hh>
#include <gecode/minimodel.hh>
#include <fstream>
#include <map>
#include <dirent.h>
#include <sys/stat.h>
#include "Driver.h"
#include "Task.h"

using namespace Gecode;

class Model : public IntMinimizeSpace {

private:
    IntVarArray tasks;
    SetVarArray driversTasks;
    IntVar c_cost;
    int driverNumber;
    int taskNumber;
    void workingDays();

public:

    vector<Driver> drivers;

    vector<Task> tasksT;

    int days;

    int maxWorkingDays;

    Model(int driverNumber, int taskNumber, int days);

    Model(bool share, Model& model);

    void prepareModel();

    void print();

    virtual Space* copy(bool share){
        return new Model(share, *this);
    }

    virtual IntVar cost(void) const {
        return c_cost;
    }

    virtual void constrain(const Space& _b){
        const Model& m = static_cast<const Model&>(_b);
        rel(*this, c_cost, IRT_LE, m.c_cost.val());
    }
};


#endif //NEW_PPT_MODEL_H
