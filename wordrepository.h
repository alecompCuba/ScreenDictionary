#ifndef WORDREPOSITORY_H
#define WORDREPOSITORY_H
#include "Word.h"
#include <QSqlDatabase>
#include <QSql>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>

constexpr auto WORDS_SQL = QLatin1String(R"(
create table words(id TEXT PRIMARY KEY, value TEXT NOT NULL, eng TEXT NOT NULL, type INTEGER NOT NULL,
gender INTEGER NOT NULL, number INTEGER NOT NULL, irregular INTEGER NOT NULL)
)");

constexpr auto GET_ALL_WORDS_SQL = QLatin1String(R"(select * from words)");

class WordRepository
{
public:
    WordRepository();
    QList<Word> GetAll();
private:
};

#endif // WORDREPOSITORY_H
