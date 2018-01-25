#include <eoslib/eos.hpp>
#include <eoslib/string.hpp>

/* @abi action insert
 * @abi table
*/
struct record {
   eosio::string key;
   eosio::string value;
};
