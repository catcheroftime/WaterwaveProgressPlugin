#include "waterwaveprogress.h"
#include "waterwaveprogressplugin.h"

#include <QtPlugin>

WaterwaveProgressPlugin::WaterwaveProgressPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void WaterwaveProgressPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool WaterwaveProgressPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *WaterwaveProgressPlugin::createWidget(QWidget *parent)
{
    return new WaterwaveProgress(parent);
}

QString WaterwaveProgressPlugin::name() const
{
    return QLatin1String("WaterwaveProgress");
}

QString WaterwaveProgressPlugin::group() const
{
    return QLatin1String("");
}

QIcon WaterwaveProgressPlugin::icon() const
{
    return QIcon();
}

QString WaterwaveProgressPlugin::toolTip() const
{
    return QLatin1String("");
}

QString WaterwaveProgressPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool WaterwaveProgressPlugin::isContainer() const
{
    return false;
}

QString WaterwaveProgressPlugin::domXml() const
{
    return QLatin1String("<widget class=\"WaterwaveProgress\" name=\"waterwaveProgress\">\n</widget>\n");
}

QString WaterwaveProgressPlugin::includeFile() const
{
    return QLatin1String("waterwaveprogress.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(waterwaveprogressplugin, WaterwaveProgressPlugin)
#endif // QT_VERSION < 0x050000
