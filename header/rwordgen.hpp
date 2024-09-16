#include "../config.h"
#include <array>
#include <random>
#include <string>

namespace rwgen
{

constexpr std::array<char, 6> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
constexpr std::array<char, 20> consonants = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};

using sources_t = std::array<std::string, SOURCE_SIZE>;
using rng_t = std::mt19937;
using distr_t = std::uniform_int_distribution<rng_t::result_type>;

char randvow (rng_t &rng);
char randcon (rng_t &rng);

std::string pick_pattern (rng_t &rng);
std::string parse_pattern (std::string pattern, rng_t &rng);

std::string make_word (rng_t &rng);
std::string mutate (std::string origstr, rng_t &rng);

void fill_sources (sources_t &src, rng_t &rng);
void mutate_sources (sources_t &src, rng_t &rng);

}
