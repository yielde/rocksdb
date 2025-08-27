#include <future>
#include <thread>
#include <iostream>
#include <unistd.h>
#include "rocksdb/db.h"

using namespace rocksdb;

static const std::string kDBPath = "/tmp/rocksdb-group-commit-demo1";

int main() {
  Options options;
  options.create_if_missing = true;
  options.IncreaseParallelism();
  // options.OptimizeLevelStyleCompaction();
  DB* db = nullptr;
  Status s = DB::Open(options, kDBPath, &db);

  std::promise<void> go;
  std::shared_future<void> ready(go.get_future());

  std::thread t1([&] {
    ready.wait(); // 等待主线程发信号
    db->Put(WriteOptions(), "key1", "value1");
  });

  std::thread t2([&] {
    ready.wait();
    db->Put(WriteOptions(), "key2", "value2");
  });

  // 两个线程都在 wait，这里发车
  go.set_value();
  t1.join();
  t2.join();
  delete db;
}