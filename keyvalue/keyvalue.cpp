#include "keyvalue.hpp"
#include "keyvalue.gen.hpp"

#include <eoslib/db.hpp>
#include <eoslib/types.hpp>
#include <eoslib/raw.hpp>

extern "C" {
   void init()  {

   }

   void apply( uint64_t code, uint64_t action ) {
      if( code == N(record) ) {
         if( action == N(insert) ) {
            // eosc push message record insert '{"key":"a", "value":"aa"}' -S record
            // eosc get table record record record1
            auto r = eosio::current_message<record>();
            eosio::print("Inserting record\n");
            eosio::dump(r);
            bytes b = eosio::raw::pack(r.value);
            uint32_t err = store_str( N(record), (char *)r.key.get_data(), r.key.get_size(), (char*)b.data, b.len);
         } else {
            assert(0, "unknown message");
         }
      }
   }
}
