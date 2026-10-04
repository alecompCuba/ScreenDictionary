#include "wordrepository.h"

WordRepository::WordRepository()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // default DB connection
    db.setDatabaseName("lavender.db");
    if (!db.open())
        throw std::runtime_error("Unable to establish connection to DB");
    QStringList tables = db.tables();
    QSqlQuery q;
    if (!tables.contains("words", Qt::CaseInsensitive)) {
        qDebug() << "Creating words table";
        q.exec(WORDS_SQL);
    }
}

QList<Word> WordRepository::GetAll()
{
    QSqlQueryModel q;
    q.setQuery(GET_ALL_WORDS_SQL);
    QList<Word> words(q.rowCount());
    for (int i = 0; i < q.rowCount(); ++i)
    {
        QString id = q.record(i).value("id").toString();
        QString value = q.record(i).value("value").toString();
        QString eng = q.record(i).value("eng").toString();
        WordType type = static_cast<WordType>(q.record(i).value("type").toInt());
        WordGender gender = static_cast<WordGender>(q.record(i).value("gender").toInt());
        WordNumber number = static_cast<WordNumber>(q.record(i).value("number").toInt());
        bool irregular = static_cast<bool>(q.record(i).value("irregularr").toInt());
        Word word(id, value, eng, type, gender, number, irregular);
        words.push_back(word);
    }
    return words;
}