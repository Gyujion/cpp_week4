#include "database.h"

Entry *create(Type type, std::string key, void *value)
{
    Entry *newEntry = new Entry;
    newEntry->key = key;
    newEntry->type = type;
    newEntry->value = value;

    return newEntry;
}
