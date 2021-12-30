#include "__dsynapseVisual_global.h"
QTextBrowser *globalLogBrowser = nullptr;

DLogs::DLogsContext DSynapseVisualLogsSpace::log_context;
DLOGS_INIT_GLOBAL_CONTEXT("DSV", DSynapseVisualLogsSpace::logsInit);
int DSynapseVisualLogParser(int level, void *opaque, const char *line) {
    QTextBrowser * tb = reinterpret_cast<QTextBrowser*>(opaque);
    tb->append(line);
}
void DSV_logit(const QString &m) {
    if(globalLogBrowser == nullptr) {
        qDebug() << "DSV_logit: no log output";
        return;
    }
    globalLogBrowser->append(m);
}
