#include <iostream>
#include "Model.h"
#include "Configuration.h"
#include "Solver.h"

using namespace std;

int main() {
    Model* model = new Model(10, 10, 5);

    model->days = 5;
    model->maxWorkingDays = 4;

    vector<Driver> drivers;

    for(int i = 0; i < 10; i++){
        Driver driver;

        drivers.push_back(driver);
    }

    model->drivers = drivers;

    Configuration configuration;

    configuration.threads = 1;
    configuration.timeout = 1000;

    Solver solver = Solver(model, configuration);

    solver.solve();

    cout << "Hello, World!" << endl;
    return 0;
}