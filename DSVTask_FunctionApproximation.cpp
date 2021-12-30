#include "DSVTask_FunctionApproximation.h"
#include <QRandomGenerator>
using namespace DSL_func_approximation;
DSVTask_FunctionApproximation::DSVTask_FunctionApproximation(QWidget *parent) : DSVTask_base(parent) {

    CREATE_WIDGET
}
void DSVTask_FunctionApproximation::_alloc() {
//    buttonBoard = new DButtonsBoard(this);
//    originalPlot = new DDiscretePlot2(this);
//    netPlot = new DDiscretePlot2(this);


    plot = new DPlot(this);
    settings = new DPlotSettings(this);
    layoutMain = new QVBoxLayout(this);
}
void DSVTask_FunctionApproximation::_place() {

//    layoutMain->addWidget(buttonBoard);
//    layoutMain->addWidget(originalPlot);
//    layoutMain->addWidget(netPlot);



    layoutMain->addWidget(plot);
    layoutMain->addWidget(settings);
}
void DSVTask_FunctionApproximation::_init() {
//    auto func = DSL_func_approximation::funcs;
//    while((func)->f)  {
//        buttonBoard->x_addButton(func->name);
//        ++func;
//    }
//    //-----------------------------------
//    originalPlot->setMinimumSize(100,100);
//    netPlot->setMinimumSize(100,100);


    plot->setMinimumSize(200, 200);
    settings->setMinimumSize(200, 200);
    plot->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

    settings->setTarget(plot);
    settings->setRectColor(Qt::green);

    QRandomGenerator random;
    auto g = plot->addGroup("Test");

    g->setUnitDrawable(DPlotPointGroup::ConnectionLine, true);

    //----------------------- test1:
//    int n = 15;
//    while(n--) {
//        g->addPoint(random.generate() % 100);
//    }
    //----------------------- test2:
    g->setBaseFunction(FuncBase_cos);
    g->setBaseFunctionStep(0.1);
    g->setBaseFunctionSource(nullptr);
    g->setBaseFunctionIterations(100);
    g->setBaseFunctionStartArgument(-5.0);
//    g->fillByBaseFunction();
    //--------------------- test3:
//    int n = 15;
//    while(n--) {
//        g->addPoint(random.generate() % 100, random.generate() % 100);
//    }
    //--------------------- test4:
//    g->setSize(10);
    //--------------------- test5:


}
void DSVTask_FunctionApproximation::_connect() {

}
void DSVTask_FunctionApproximation::_disconnect() {

}
void DSVTask_FunctionApproximation::_dealloc() {

}
