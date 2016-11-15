//
// Created by estilon on 14/11/16.
//

#include "Model.h"

using namespace std;

Model::Model(int driverNumber, int taskNumber, int days):
        tasks(*this, taskNumber, 0, driverNumber),
        c_cost(*this, 0, 1000),
        driversTasks(*this, 2, IntSet::empty, IntSet(0, 9))
{
    (*this).driverNumber = driverNumber;
    (*this).taskNumber = taskNumber;
    this->days = days;

    //channel(*this, tasks, driversTasks);

    branch(*this, this->tasks, INT_VAR_NONE(), INT_VAL_MIN());
}

Model::Model(bool share, Model& model): IntMinimizeSpace(share, model) {
    tasks.update(*this, share, model.tasks);
    //c_cost.update(*this, share, model.c_cost);
    //driversTasks.update(*this, share, model.driversTasks);
}

void Model::print(){

    try {
        cout << tasks << endl;
    }catch (exception e){

        cout << "Exception " << e.what() << endl;
    }

}

void Model::prepareModel() {

}

void Model::workingDays() {

    /*Matrix<SetVarArray> driverTasks(driversTasks, driverNumber, days);

    for(int i = 0; i < days - maxWorkingDays; i++) {
        for (int j = 0; j < drivers.size(); j++) {
            IntVar count(*this, 0, 0);

            for(int k = i; k < i + maxWorkingDays; k++){
                count = expr(*this, ite(cardinality(driverTasks(j, k)) == 0, count + 1, count + 0));
            }
        }
    }*/
}

