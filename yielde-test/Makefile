Rocksdb := ../librocksdb.a

put-test-2: put-test-2.cc
	$(CXX) $@.cc -o $@ $(Rocksdb) -I../include -O0 -g -std=c++17

put-test: put-test.cc
	$(CXX) $@.cc -o $@ $(Rocksdb) -I../include -O0 -g -std=c++17
