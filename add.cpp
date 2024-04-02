#include "database.h"

void add(Database &database, Entry *entry)
{
    // 최대 수용개수에 도달하면 새로운 배열을 할당
    if (database.size == database.capacity)
    {
        // 새로운 최대수용 개수는 원래 수용개수가 0이면 1을 아니면 수용개수에 곱하기 2
        int newCapacity = database.capacity == 0 ? 1 : database.capacity * 2;
        Entry *newEntries = new Entry[newCapacity];

        for (int i = 0; i < database.size; i++)
            newEntries[i] = database.entries[i];
        // 기존 배열 해제
        delete[] database.entries;

        // 새로운 엔트리와 수용개수 갱신
        database.entries = newEntries;
        database.capacity = newCapacity;
    }
    // 데이터베이스의 엔트리에 새로운 엔트리 추가
    database.entries[database.size++] = *entry;
}