#ifndef DSVTASK_FUNCTIONAPPROXIMATION_H
#define DSVTASK_FUNCTIONAPPROXIMATION_H

#include "DNetMaster.h"
#include <DButtonsBoard.h>
//#include <DDiscretePlot2.h>
#include "__dsynapseVisual_global.h"
#include <DSL_func_approximation.h>
#include "DPlot.h"

class DSVTask_FunctionApproximation : public DSVTask_base {
    Q_OBJECT
public:
    DSVTask_FunctionApproximation(QWidget *parent = nullptr);
private:
    void _alloc();
    void _place();
    void _init();
    void _connect();
    void _disconnect();
    void _dealloc();

private:
//    DButtonsBoard *buttonBoard;
//    DDiscretePlot2 *originalPlot;
//    DDiscretePlot2 *netPlot;

    DPlot *plot;
    DPlotSettings *settings;

    QVBoxLayout *layoutMain;
};

#endif // DSVTASK_FUNCTIONAPPROXIMATION_H
