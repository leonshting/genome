#include "csv.h"

#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QRegExp>
#include <QDebug>

QList<QStringList> parse(const QString &string, QChar sep)
{
    enum State {Normal, Quote} state = Normal;
    QList<QStringList> data;
    QStringList line;
    QString value;

    for (int i = 0; i < string.size(); i++) {
        QChar current = string.at(i);

        // Normal
        if (state == Normal) {
            // newline
            if (current == '\n') {
                // add value
                line.append(value);
                value.clear();
                // add line
                data.append(line);
                line.clear();
            }
            // comma
            else if (current == sep) {
                // add line
                line.append(value);
                value.clear();
            }
            // double quote
            else if (current == '"') {
                state = Quote;
            }
            // character
            else {
                value += current;
            }
        }
        // Quote
        else if (state == Quote) {
            // double quote
            if (current == '"') {
                int index = (i+1 < string.size()) ? i+1 : string.size();
                QChar next = string.at(index);
                if (next == '"') {
                    value += '"';
                    i++;
                } else {
                    state = Normal;
                }
            }
            // other
            else {
                value += current;
            }
        }
    }

    return data;
}

QString initString(const QString &string)
{
    QString result = string;
    result.replace("\r\n", "\n");
    if (result.at(result.size()-1) != '\n') {
        result += '\n';
    }
    return result;
}

QList<QStringList> CSV::parseFromString(const QString &string, QChar sep)
{
    return parse(initString(string), sep);
}

QList<QStringList> CSV::parseFromFile(const QString &filename, QChar sep, int flush)
{
    QString string = "";
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        string = in.readAll();
        CSV::flush_lf(flush,&string);
        file.close();
    }
    return parse(initString(string), sep);
}

bool CSV::write(const QList<QStringList> data, const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    QTextStream out(&file);
    foreach (const QStringList &line, data) {
        QStringList output;
        foreach (QString value, line) {
            if (value.contains(QRegExp(",|\r\n"))) {
                output << ("\"" + value + "\"");
            } else if (value.contains("\"")) {
                output << value.replace("\"", "”");
            } else {
                output << value;
            }
        }
        out << output.join(",") << "\r\n";
    }

    file.close();

    return true;
}

void CSV::flush_lf(int n, QString *s)
{
    int i=0, j=0;
    do
    {
        if(s->at(i++) == '\n')
        {
            j++;
        }
    }
    while(j<n);
    s->remove(0,i);
}
