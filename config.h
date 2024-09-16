#include <array>
#include <string>

/* Defines the amount of source words
 */
#define SOURCE_SIZE 10

/* Defines possible patterns present in a word
 * A pattern must consist solely of c and v 
 * More patterns could provide more diverse pool of words
 */
constexpr const char *
PATTERNS [] =
{
    "cv",
    "vc",
    "cvc",
    "vv",
    NULL // do not delete
  };

/* Defines the maximum amount of parts a word is allowed to consist of
 */
#define MAX_PARTS 4

/* Defines the amount of variations provided for each word 
 */
#define VARIATIONS 5

/* Defines rarity of mutation in a word
 * The bigger the scale, the less likely a mutation is to happen
 */
#define MUTATION_SCALE 6
