#pragma once
#include <eoslib/types.hpp>
#include <eoslib/datastream.hpp>
#include <eoslib/raw_fwd.hpp>

namespace eosio { namespace raw {
   template<typename Stream> inline void pack( Stream& s, const record& value ) {
      raw::pack(s, value.key);
      raw::pack(s, value.value);
   }
   template<typename Stream> inline void unpack( Stream& s, record& value ) {
      raw::unpack(s, value.key);
      raw::unpack(s, value.value);
   }
} }

#include <eoslib/raw.hpp>
namespace eosio {
   void print_ident(int n){while(n-->0){print("  ");}};
   template<typename Type>
   Type current_message_ex() {
      uint32_t size = action_size();
      char* data = (char *)eosio::malloc(size);
      assert(data && read_message(data, size) == size, "error reading message");
      Type value;
      eosio::raw::unpack(data, size, value);
      eosio::free(data);
      return value;
   }
   void dump(const record& value, int tab=0) {
      print_ident(tab);print("key:[");print("]\n");
      print_ident(tab);print("value:[");print("]\n");
   }
   template<>
   record current_action<record>() {
      return current_message_ex<record>();
   }
} //eosio
