#ifndef WORD_H
#define WORD_H
#include <QString>

enum WordType {
    Noun = 1, Verb, Adjective, Pronoun
};

enum WordGender {
    Masculine = 1, Feminine, Neuter
};

enum WordNumber {
    Singular = 1, Plural
};

class Word
{
public:
    Word();
    Word(QString id, QString value, QString eng, WordType type, WordGender gender, WordNumber number, bool irregular);
    QString GetValue();
private:
    QString m_id;
    QString m_value;
    QString m_eng;
    WordType m_type;
    WordGender m_gender;
    WordNumber m_number;
    bool m_irregular;
};

#endif // WORD_H