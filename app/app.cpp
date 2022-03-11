//
// Created by T480S on 2021/10/19.
//
#include <cassert>
#include <iostream>

#include "leveldb/db.h"

using namespace std;
using namespace leveldb;

//#define LEVELDB_EXPORTS

#define STORAGE_LEVELDB_INCLUDE_DB_H_1

int main() {

  DB* db;
  Options options;
  options.create_if_missing = true;
  Status status = DB::Open(options, "testDB", &db);
  assert(status.ok());

  status = db->Put(WriteOptions(), "KeyNameExample", "ValueExamples");
  assert(status.ok());
  string res;
  status = db->Get(ReadOptions(), "KeyNameExample", &res);
  assert(status.ok());

  cout << "Get Value Is: " << res << endl;
  cout << "hello levelDB :" <<  endl;

  delete db;

  return 0;
}