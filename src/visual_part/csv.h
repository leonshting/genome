#ifndef CSV_H
#define CSV_H

#include <QStringList>
#include <QString>

namespace CSV
{
    QList<QStringList> parseFromString(const QString &string, QChar sep);
    QList<QStringList> parseFromFile(const QString &filename, QChar sep, int flush);
    bool write(const QList<QStringList> data, const QString &filename);
    void flush_lf(int n, QString *s);
}

#endif // CSV_H
