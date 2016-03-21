#include "krenameext.h"

#include <QDir>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QtGlobal>
#include <QStringList>
#include <QRegularExpression>

#include <iostream>

using std::cout;
using std::endl;

KRenameExt::KRenameExt(QString rootDir, QString oldName, QString newName, bool beRecur)
    :m_sRootDir(rootDir),
     m_sNewName(newName),
     m_sOldName(oldName),
     m_bRecur(beRecur)
{
    m_stDirList.clear();
}

bool KRenameExt::run()
{
    if(!checkDirName()){ exit(1); }
    if(m_bRecur){
        m_stDirList.push(m_sRootDir);

        while(!m_stDirList.empty()){
            QString tempDir = m_stDirList.pop();

            QDir temp(tempDir);
            QString tempAbsDir = temp.absolutePath() + QDir::separator();
            QStringList dirlist = temp.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);

            if(!dirlist.empty()){
                for(int index = 0;index<dirlist.length();++index){
                    m_stDirList.push(tempAbsDir + dirlist[index]);
                }
            }

            process(tempAbsDir,temp.entryList(QDir::Files));
        }
    }else{
        QDir temp(m_sRootDir);
        process(temp.absolutePath() + QDir::separator(),temp.entryList(QDir::Files));
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

bool KRenameExt::process(QString parent,QStringList lists)
{
    if(0==lists.length()) return true;
    QRegularExpression reg("."+m_sOldName);
    for(int index = 0;index < lists.length();++index){
        QString temp = lists[index];
        int pos = temp.lastIndexOf(reg);
        if(-1 ==  pos) continue;
        if(m_sOldName.length() + 1 != temp.length() - pos) continue;
        temp = parent + temp.left(pos+1) + m_sNewName;
        qDebug()<<temp;
        QFile::rename(parent + lists[index],temp);
    }
    return true;
}


