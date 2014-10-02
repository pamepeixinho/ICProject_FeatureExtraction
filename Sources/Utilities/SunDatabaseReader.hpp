

#ifndef SUN_DATABASE_READER__HPP
#define SUN_DATABASE_READER__HPP

#include "DatabaseReader.hpp"
#include <QString>
#include <QDir>
#include <assert.h>
#include <QList>
#include <QFileInfoList>
#include <QFileInfo>

class SunDatabaseReader:public DatabaseReader{

    private:
        QDir sourceDir;
        QList<QString> image_files;
        QList<QString> supervision_files;
        void discover_files(QString);
        QList<QString>::iterator image_files_it;
        QList<QString>::iterator supervision_files_it;
        

    public:
        SunDatabaseReader(QString sourceDir);
        SupervisedImage* readNext();

};



#endif
