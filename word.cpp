#include "word.h"

Word::Word() {}

Word::Word(QString id, QString value, QString eng, WordType type, WordGender gender, WordNumber number, bool irregular)
    : m_id(id), m_value(value), m_eng(eng), m_type(type), m_gender(gender), m_number(number), m_irregular(irregular) {}

QString Word::GetValue() { return m_value; }