#include "krenameext.h"

#include <QDir>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QtGlobal>
#include <QStringList>

#include <iostream>

using std::cout;
using std::endl;

KRenameExt::KRenameExt(QString rootDir, QString oldName, QString newName, bool beRecur)
    :m_sRootDir(rootDir),
     m_sNewName(newName),
     m_sOldName(oldName),
     m_bRecur(beRecur)
{

}

bool KRenameExt::run()
{
    if(!checkDirName()){ exit(1); }
    //QStringList list = dir.entryList(QDir::Files);
    QStringList list = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);

    for(int index = 0;index<list.length();++index)
    {
        qDebug()<<list[index]<<"--";
    }
}

bool KRenameExt::checkDirName()
{
    if(m_sRootDir == ""){
        std::cout<<"an empty rootdir!"<<std::endl;
        return false;
    }
    QDir dir(m_sRootDir);

    if(!dir.exists()){
        std::cout<<"the rootdir doesn't exist!"<<std::endl;
        return false;
    }
    m_sRootDir = dir.absolutePath();

    return true;
}

bool KRenameExt::process(QStringList & lists)
{
    //QFile::rename()
}


