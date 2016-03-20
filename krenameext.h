#ifndef KRENAMEEXT_H
#define KRENAMEEXT_H

#include <QString>

class KRenameExt
{
public:
    KRenameExt(QString,QString,QString,bool);
    bool run();
private:
    bool checkDirName();
    bool process(QStringList &);
private:
    QString m_sRootDir;
    QString m_sOldName;
    QString m_sNewName;
    bool m_bRecur;
};

#endif // KRENAMEEXT_H
