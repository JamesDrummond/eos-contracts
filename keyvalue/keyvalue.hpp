#include <eoslib/eos.hpp>
#include <eoslib/string.hpp>

/* @abi action insertkv1
 * @abi table
*/
struct key_value1 {
   eosio::string key;
   eosio::string value;
};
