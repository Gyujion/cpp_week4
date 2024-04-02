#ifndef DATABASE_H
#define DATABASE_H

#include <string>

enum Type
{
  INT,
  DOUBLE,
  STRING,
  ARRAY
};

struct Array
{
  int size;
  Type type;
  void *items;
};

struct Entry
{
  Type type;
  std::string key;
  void *value;
};

struct Database
{
  struct Entry *entries; // 엔트리들을 저장할 배열
  int size;              // 현재 저장된 엔트리 수
  int capacity;          // 엔트리 최대 저장 가능 개수
};

// 엔트리를 생성한다.
Entry *create(Type type, std::string key, void *value);

Array *createArray(Type type, int size, void *items);

// 데이터베이스를 초기화한다.
void init(Database &database);

// 데이터베이스에 엔트리를 추가한다.
void add(Database &database, Entry *entry);

// 데이터베이스에서 키에 해당하는 엔트리를 찾는다.
Entry *get(Database &database, std::string &key);

// 데이터베이스에서 키에 해당하는 엔트리를 제거한다.
void remove(Database &database, std::string &key);

// 데이터베이스 안의 리스트들을 보여준다.
void list(Database &database);

// 데이터베이스를 해제한다.
void destroy(Database &database);

#endif