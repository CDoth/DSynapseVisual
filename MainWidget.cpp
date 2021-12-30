#include "MainWidget.h"

using namespace DSynapseVisualLogsSpace;

#define ADD_TASK(X) addTask(new X)
DSVMainWidget::DSVMainWidget(QWidget *parent) : DWidget(parent) {

    CREATE_WIDGET
    resize(500,500);

    log_context.parse_set_special_tool(DSynapseVisualLogParser);
    log_context.set_special_data(logOutput);
    log_context.parse_special(true);
    log_context.parse_console(false);

    globalLogBrowser = logOutput;
    //12

}
void DSVMainWidget::_alloc() {

    buttonsBoard_tasks = new DButtonsBoard(this);
    currentTask = nullptr;
//    currentNet = new DNetMaster(this);
    logOutput = new QTextBrowser(this);

    layoutMain = new QGridLayout(this);
}
void DSVMainWidget::_place() {

    layoutMain->addWidget(buttonsBoard_tasks, 0, 0);
//    layoutMain->addWidget(currentNet, 0, 2);
    layoutMain->addWidget(logOutput, 1, 0, 1, 0);

}
void DSVMainWidget::_init() {

    buttonsBoard_tasks->x_addButton("task 1");
    buttonsBoard_tasks->x_addButton("task 2");
    buttonsBoard_tasks->x_addButton("task 3");
    buttonsBoard_tasks->x_addButton("task 4");
    //--------------------------------------------
    ADD_TASK(DSVTask_FunctionApproximation);
    //--------------------------------------------
}
void DSVMainWidget::_connect() {

    connect(buttonsBoard_tasks, SIGNAL(clicked(int)), this, SLOT(startTask(int)));
}
void DSVMainWidget::_disconnect() {

}
void DSVMainWidget::_dealloc() {

}
void DSVMainWidget::addTask(DSVTask_base *t) {
    t->hide();
    t->setRectColor(Qt::red);
    layoutMain->addWidget(t, 0, 1);
    tasks.push_back(t);
}
void DSVMainWidget::startTask(int t) {

    if(t < 0 || t >= tasks.size()) {
        DL_BADVALUE(1, "Task index: [%d] (available range: [%d;%d])", t, 0, tasks.size()-1);
        return;
    }

    auto __t = tasks[t];
    if(currentTask == __t) {
        return;
    }
    if(currentTask)
        currentTask->hide();
    currentTask = __t;
    if(currentTask)
        currentTask->show();
}

