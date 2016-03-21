#ifndef KRENAMEEXT_H
#define KRENAMEEXT_H

#include <QString>

#include <QStack>

class KRenameExt
{
public:
    KRenameExt(QString,QString,QString,bool);
    bool run();
private:
    bool checkDirName();
    bool process(QString,QStringList);
private:
    QString m_sRootDir;
    QString m_sOldName;
    QString m_sNewName;
    bool m_bRecur;
    QStack<QString> m_stDirList;
};

#endif // KRENAMEEXT_H
