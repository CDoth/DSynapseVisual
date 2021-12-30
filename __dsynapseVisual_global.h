#ifndef __DSYNAPSEVISUAL_GLOBAL_H
#define __DSYNAPSEVISUAL_GLOBAL_H
#include <DWidget.h>
#include <DLogs.h>
#include <QTextBrowser>

extern QTextBrowser *globalLogBrowser;

namespace DSynapseVisualLogsSpace {
    extern DLogs::DLogsContext log_context;
    extern DLogs::DLogsContextInitializator logsInit;
}
int DSynapseVisualLogParser(int level, void *opaque, const char *line);
void DSV_logit(const QString &m);
#define DSVLOG(m) DSV_logit(m)

class DSVTask_base : public DWidget {
    Q_OBJECT
public:
    DSVTask_base(QWidget *parent = nullptr) : DWidget(parent) {}
};



#endif // __DSYNAPSEVISUAL_GLOBAL_H

