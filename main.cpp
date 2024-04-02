#include "database.h"
#include <iostream>
#include <string>

using namespace std;

void list(Database &database);
void add(Database &database, Entry *entry);
Entry *create(Type type, std::string key, void *value);
Array *createArray(Type type, int size);

int main()
{
    Database DB;
    Entry basicEntry;
    Array arrayEntry;
    init(DB);

    std::string input;
    std::string key, type;
    Type realType, arrayType;
    int inputInt, size;
    double inputDouble;
    while (true)
    {
        cout << "command (list, add, get, del, exit): ";
        cin >> input;

        if (input == "exit")
            break;
        else if (input == "list")
            list(DB);
        else if (input == "add")
        {
            cout << "key: ";
            cin >> key;
            cout << "type (int, double, string, array): ";
            cin >> type;
            if (type == "int")
                realType = INT;
            else if (type == "double")
                realType = DOUBLE;
            else if (type == "string")
                realType = STRING;
            else
                realType = ARRAY;
            switch (realType)
            {
            case INT:
                cout << "value: ";
                cin >> inputInt;
                basicEntry = *create(realType, key, &inputInt);
                add(DB, &basicEntry);
                break;
            case DOUBLE:
                cout << "value: ";
                cin >> inputDouble;
                basicEntry = *create(realType, key, &inputDouble);
                add(DB, &basicEntry);
                break;
            case STRING:
                cout << "value: ";
                cin.ignore(1024, '\n');
                getline(cin, input);
                basicEntry = *create(realType, key, &input);
                add(DB, &basicEntry);
                break;
            case ARRAY:

                break;
            }
        }
    }

    return 0;
}