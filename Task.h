//
// Created by estilon on 15/11/16.
//

#ifndef NEW_PPT_TASK_H
#define NEW_PPT_TASK_H


#include <ctime>

class Task {

    int id;
    int lineCode;
    int schedulingDay;
    int dayType;
    int vehicleCode;
    int startingTaskType;
    int controlPostCode;
    int length;
    tm starting;
    tm ending;
};


#endif //NEW_PPT_TASK_H
