/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp org.deepin.dde.Appearance1.xml -c Appearance_Interface -p appearance_interface
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef APPEARANCE_INTERFACE_H
#define APPEARANCE_INTERFACE_H

#include "ddplugin_background_global.h"

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
/*
 * Proxy class for interface org.deepin.dde.Appearance1
 */

typedef QMap<QString, double> ScaleFactors;

DDP_BACKGROUND_BEGIN_NAMESPACE

class Appearance_Interface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.deepin.dde.Appearance1"; }

public:
    Appearance_Interface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~Appearance_Interface();

    Q_PROPERTY(QString Background READ background)
    inline QString background() const
    { return qvariant_cast< QString >(property("Background")); }

    Q_PROPERTY(QString CursorTheme READ cursorTheme)
    inline QString cursorTheme() const
    { return qvariant_cast< QString >(property("CursorTheme")); }

    Q_PROPERTY(double FontSize READ fontSize WRITE setFontSize)
    inline double fontSize() const
    { return qvariant_cast< double >(property("FontSize")); }
    inline void setFontSize(double value)
    { setProperty("FontSize", QVariant::fromValue(value)); }

    Q_PROPERTY(QString GlobalTheme READ globalTheme)
    inline QString globalTheme() const
    { return qvariant_cast< QString >(property("GlobalTheme")); }

    Q_PROPERTY(QString GtkTheme READ gtkTheme)
    inline QString gtkTheme() const
    { return qvariant_cast< QString >(property("GtkTheme")); }

    Q_PROPERTY(QString IconTheme READ iconTheme)
    inline QString iconTheme() const
    { return qvariant_cast< QString >(property("IconTheme")); }

    Q_PROPERTY(QString MonospaceFont READ monospaceFont)
    inline QString monospaceFont() const
    { return qvariant_cast< QString >(property("MonospaceFont")); }

    Q_PROPERTY(double Opacity READ opacity WRITE setOpacity)
    inline double opacity() const
    { return qvariant_cast< double >(property("Opacity")); }
    inline void setOpacity(double value)
    { setProperty("Opacity", QVariant::fromValue(value)); }

    Q_PROPERTY(QString QtActiveColor READ qtActiveColor WRITE setQtActiveColor)
    inline QString qtActiveColor() const
    { return qvariant_cast< QString >(property("QtActiveColor")); }
    inline void setQtActiveColor(const QString &value)
    { setProperty("QtActiveColor", QVariant::fromValue(value)); }

    Q_PROPERTY(QString StandardFont READ standardFont)
    inline QString standardFont() const
    { return qvariant_cast< QString >(property("StandardFont")); }

    Q_PROPERTY(QString WallpaperSlideShow READ wallpaperSlideShow WRITE setWallpaperSlideShow)
    inline QString wallpaperSlideShow() const
    { return qvariant_cast< QString >(property("WallpaperSlideShow")); }
    inline void setWallpaperSlideShow(const QString &value)
    { setProperty("WallpaperSlideShow", QVariant::fromValue(value)); }

    Q_PROPERTY(QString WallpaperURls READ wallpaperURls)
    inline QString wallpaperURls() const
    { return qvariant_cast< QString >(property("WallpaperURls")); }

    Q_PROPERTY(int WindowRadius READ windowRadius WRITE setWindowRadius)
    inline int windowRadius() const
    { return qvariant_cast< int >(property("WindowRadius")); }
    inline void setWindowRadius(int value)
    { setProperty("WindowRadius", QVariant::fromValue(value)); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Delete(const QString &ty, const QString &name)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(ty) << QVariant::fromValue(name);
        return asyncCallWithArgumentList(QStringLiteral("Delete"), argumentList);
    }

    inline QDBusPendingReply<QString> GetCurrentWorkspaceBackground()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("GetCurrentWorkspaceBackground"), argumentList);
    }

    inline QDBusPendingReply<QString> GetCurrentWorkspaceBackgroundForMonitor(const QString &strMonitorName)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(strMonitorName);
        return asyncCallWithArgumentList(QStringLiteral("GetCurrentWorkspaceBackgroundForMonitor"), argumentList);
    }

    inline QDBusPendingReply<double> GetScaleFactor()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("GetScaleFactor"), argumentList);
    }

    inline QDBusPendingReply<ScaleFactors> GetScreenScaleFactors()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("GetScreenScaleFactors"), argumentList);
    }

    inline QDBusPendingReply<QString> GetWallpaperSlideShow(const QString &monitorName)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(monitorName);
        return asyncCallWithArgumentList(QStringLiteral("GetWallpaperSlideShow"), argumentList);
    }

    inline QDBusPendingReply<QString> GetWorkspaceBackgroundForMonitor(int index, const QString &strMonitorName)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(index) << QVariant::fromValue(strMonitorName);
        return asyncCallWithArgumentList(QStringLiteral("GetWorkspaceBackgroundForMonitor"), argumentList);
    }

    inline QDBusPendingReply<QString> List(const QString &ty)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(ty);
        return asyncCallWithArgumentList(QStringLiteral("List"), argumentList);
    }

    inline QDBusPendingReply<> Reset()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Reset"), argumentList);
    }

    inline QDBusPendingReply<> Set(const QString &ty, const QString &value)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(ty) << QVariant::fromValue(value);
        return asyncCallWithArgumentList(QStringLiteral("Set"), argumentList);
    }

    inline QDBusPendingReply<> SetCurrentWorkspaceBackground(const QString &uri)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(uri);
        return asyncCallWithArgumentList(QStringLiteral("SetCurrentWorkspaceBackground"), argumentList);
    }

    inline QDBusPendingReply<> SetCurrentWorkspaceBackgroundForMonitor(const QString &uri, const QString &strMonitorName)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(uri) << QVariant::fromValue(strMonitorName);
        return asyncCallWithArgumentList(QStringLiteral("SetCurrentWorkspaceBackgroundForMonitor"), argumentList);
    }

    inline QDBusPendingReply<> SetMonitorBackground(const QString &monitorName, const QString &imageGile)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(monitorName) << QVariant::fromValue(imageGile);
        return asyncCallWithArgumentList(QStringLiteral("SetMonitorBackground"), argumentList);
    }

    inline QDBusPendingReply<> SetScaleFactor(double scale)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(scale);
        return asyncCallWithArgumentList(QStringLiteral("SetScaleFactor"), argumentList);
    }

    inline QDBusPendingReply<> SetScreenScaleFactors(ScaleFactors scaleFactor)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(scaleFactor);
        return asyncCallWithArgumentList(QStringLiteral("SetScreenScaleFactors"), argumentList);
    }

    inline QDBusPendingReply<> SetWallpaperSlideShow(const QString &monitorName, const QString &slideShow)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(monitorName) << QVariant::fromValue(slideShow);
        return asyncCallWithArgumentList(QStringLiteral("SetWallpaperSlideShow"), argumentList);
    }

    inline QDBusPendingReply<> SetWorkspaceBackgroundForMonitor(int index, const QString &strMonitorName, const QString &uri)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(index) << QVariant::fromValue(strMonitorName) << QVariant::fromValue(uri);
        return asyncCallWithArgumentList(QStringLiteral("SetWorkspaceBackgroundForMonitor"), argumentList);
    }

    inline QDBusPendingReply<QString> Show(const QString &ty, const QStringList &names)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(ty) << QVariant::fromValue(names);
        return asyncCallWithArgumentList(QStringLiteral("Show"), argumentList);
    }

    inline QDBusPendingReply<QString> Thumbnail(const QString &ty, const QString &name)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(ty) << QVariant::fromValue(name);
        return asyncCallWithArgumentList(QStringLiteral("Thumbnail"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void Changed(const QString &ty, const QString &value);
    void Refreshed(const QString &type);
};

namespace org {
  namespace deepin {
    namespace dde {
      typedef ddplugin_background::Appearance_Interface Appearance1;
    }
  }
}

DDP_BACKGROUND_END_NAMESPACE

#endif
