#include "keyvalue.hpp"
#include "simpledb.gen.hpp"

#include <eoslib/db.hpp>
#include <eoslib/types.hpp>
#include <eoslib/raw.hpp>

extern "C" {
   void init()  {

   }
   
   void apply( uint64_t code, uint64_t action ) {
      if( code == N(keyvalue) ) {
         if( action == N(insertkv1) ) {
            // eosc push message keyvalue insertkv1 '{"key":"a", "value":"aa"}' -S keyvalue
            // eosc get table keyvalue keyvalue keyvalue1
            auto kv1 = eosio::current_message<key_value1>();
            eosio::print("Inserting key_value1\n");
            eosio::dump(kv1);
            bytes b = eosio::raw::pack(kv1.value);
            uint32_t err = store_str( N(keyvalue), N(keyvalue1), (char *)kv1.key.get_data(), kv1.key.get_size(), (char*)b.data, b.len);
         } else {
            assert(0, "unknown message");
         }
      }
   }
}
