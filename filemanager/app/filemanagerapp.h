#ifndef FILEMANAGERAPP_H
#define FILEMANAGERAPP_H

#include <QObject>

class WindowManager;
#define DEEPIN_UI_ENABLE 1

class FileManagerWindow;
class DFileManagerWindow;
class AppController;

class FileManagerApp : public QObject
{
    Q_OBJECT
public:
    explicit FileManagerApp(QObject *parent = 0);
    ~FileManagerApp();

    void initLogger();
    void initGtk();
    void initApp();
    void initView();
    void initController();
    void initCommandline();
    void initTranslation();
    void initConnect();

signals:

public slots:
    void show();

private:
    WindowManager* m_windowManager=NULL;
    FileManagerWindow* m_fileManagerWindow=NULL;
    DFileManagerWindow * m_dFileMangerWindow=NULL;
    AppController* m_appController = NULL;
};

#endif // FILEMANAGERAPP_H
