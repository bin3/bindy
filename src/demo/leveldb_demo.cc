/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-6-5
 */

#include <iostream>
#include <string>
#include <leveldb/db.h>
#include <leveldb/write_batch.h>
#include <leveldb/cache.h>
#include <leveldb/filter_policy.h>
using namespace std;

const std::string kDbName = "/tmp/testdb";

void Use() {
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status s = leveldb::DB::Open(options, kDbName, &db);
  if (!s.ok()) {
    std::cerr << s.ToString() << std::endl;
    return;
  }

  s = db->Put(leveldb::WriteOptions(), "key1", "value1");
  assert(s.ok());

  leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
  for (it->SeekToFirst(); it->Valid(); it->Next()) {
    cout << it->key().ToString() << ": " << it->value().ToString() << endl;
  }
  assert(it->status().ok()); // Check for any errors found during the scan
  delete it;

  std::string key1 = "key1";
  std::string key2 = "key2";
  std::string value;
  s = db->Get(leveldb::ReadOptions(), key1, &value);
  if (s.ok())
    s = db->Put(leveldb::WriteOptions(), key2, value);
  if (s.ok())
    s = db->Delete(leveldb::WriteOptions(), key1);

  s = db->Get(leveldb::ReadOptions(), key1, &value);
  if (s.ok()) {
    leveldb::WriteBatch batch;
    batch.Delete(key1);
    batch.Put(key2, value);
    s = db->Write(leveldb::WriteOptions(), &batch);
  }

  delete db;
}

void UseCache() {
  leveldb::Options options;
  options.block_cache = leveldb::NewLRUCache(100 * 1048576); // 100MB cache
  leveldb::DB* db;
  leveldb::DB::Open(options, kDbName, &db);
  delete db;
  delete options.block_cache;
}

void UseSnapshot() {
  leveldb::DB* db;
  leveldb::DB::Open(leveldb::Options(), kDbName, &db);
  leveldb::ReadOptions options;
  options.snapshot = db->GetSnapshot();

//  ... apply some updates to db ...
//    leveldb::Iterator* iter = db->NewIterator(options);
//    ... read using iter to view the state when the snapshot was created ...

  db->ReleaseSnapshot(options.snapshot);

  delete db;
}

void UseFilter() {
  leveldb::Options options;
  options.filter_policy = leveldb::NewBloomFilterPolicy(10);
  leveldb::DB* db;
  leveldb::DB::Open(options, kDbName, &db);
  //... use the database ...
  delete db;
  delete options.filter_policy;
}

void UseGetApproximateSizes() {
  leveldb::DB* db;
  leveldb::DB::Open(leveldb::Options(), kDbName, &db);
  leveldb::Range ranges[2];
  ranges[0] = leveldb::Range("a", "c");
  ranges[1] = leveldb::Range("x", "z");
  uint64_t sizes[2];
  db->GetApproximateSizes(ranges, 2, sizes);
}

int main(int argc, char **argv) {
  Use();
  UseCache();
  return 0;
}
