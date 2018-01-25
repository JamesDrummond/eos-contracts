#include "keyvalue.hpp"
#include "keyvalue.gen.hpp"

#include <eoslib/db.hpp>
#include <eoslib/types.hpp>
#include <eoslib/raw.hpp>

extern "C" {
   void init()  {

   }

   void apply( uint64_t code, uint64_t action ) {
      if( code == N(keyvalue) ) {
         if( action == N(insert) ) {
            // eosc push message keyvalue insert '{"key":"a", "value":"aa"}' -S keyvalue
            // eosc get table keyvalue keyvalue record
            auto r = eosio::current_message<record>();
            eosio::print("Inserting record\n");
            eosio::dump(r);
            bytes b = eosio::raw::pack(r.value);
            uint32_t err = store_str( N(keyvalue), (char *)r.key.get_data(), r.key.get_size(), (char*)b.data, b.len);
         } else {
            assert(0, "unknown message");
         }
      }
   }
}
