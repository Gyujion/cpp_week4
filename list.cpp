#include "database.h"
#include <iostream>

void list(Database &database)
{
    for (int i = 0; i < database.capacity; i++)
    {
        std::cout << database.entries[i].key << ": ";
        switch (database.entries[i].type)
        {
        case INT:
            std::cout << *(int *)(database.entries[i].value) << std::endl;
            break;
        case DOUBLE:
            std::cout << *(double *)database.entries[i].value << std::endl;
            break;
        case STRING:
            std::cout << *(std::string *)database.entries[i].value << std::endl;
            break;
        case ARRAY:
            break;
        }
    }
}