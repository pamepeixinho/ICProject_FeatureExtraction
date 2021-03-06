#ifndef KFOLDDATABASEREADER_HPP
#define KFOLDDATABASEREADER_HPP

#include <QList>
#include "DatabaseReader.hpp"
class SupervisedImage;
class KFoldDatabaseReader
{
private:
    QList<QString> trainImages;
    QList<QString> testImages;
    static QList<int> randomPermutation(int n);
public:
    KFoldDatabaseReader(DatabaseReader &reader, float trainRatio);

    class PathDatabaseReader:public DatabaseReader{
    private:
        QList<QString> images;
        unsigned int current;
        SupervisedImage readAt(unsigned int i);
        PathDatabaseReader(QList<QString> images);


    public:
        virtual SupervisedImage readNext();
        virtual SupervisedImage readPrevious();
        virtual bool hasNext() const;
        virtual bool hasPrevious() const;
        virtual unsigned int getTotal() const;

        friend class KFoldDatabaseReader;
    };

    PathDatabaseReader getTrainReader() const;
    PathDatabaseReader getTestReader() const;



};

#endif // KFOLDDATABASEREADER_HPP
