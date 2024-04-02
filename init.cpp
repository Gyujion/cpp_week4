#include "database.h"

void init(Database &database)
{
    const int initialCapacity = 1; // 초기 수용개수, 1로 정의했다.
    database.entries = new Entry[initialCapacity];
    database.size = 0;
    database.capacity = initialCapacity;
}