#include "../header/rwordgen.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using rng_t = rwgen::rng_t;
using distr_t = rwgen::distr_t;
using sources_t = rwgen::sources_t;

char rwgen::randvow(rng_t &rng)
{
  return rwgen::vowels[distr_t(0, vowels.size() - 1)(rng)];
}

char rwgen::randcon(rng_t &rng)
{
  return consonants[distr_t(0, vowels.size() - 1)(rng)];
}

std::string rwgen::pick_pattern(rng_t &rng)
{
  std::size_t pattern_size = 0;
  while (PATTERNS[pattern_size++]);
  return std::string (PATTERNS[distr_t(0, pattern_size - 2)(rng)]);
}

std::string rwgen::parse_pattern(std::string pattern, rng_t &rng)
{
  std::string ret_val;
  for (char c : pattern)
  {
    switch (c) {
      case 'c':
        ret_val += rwgen::randcon(rng);
        break;
      case 'v':
        ret_val += rwgen::randvow(rng);
        break;
      default:
        throw std::runtime_error("A pattern must only consist of c and v. Provided pattern: " + pattern);
    }
  }
  return ret_val;
}

std::string rwgen::make_word (rng_t &rng)
{
  std::string ret_val;
  for (int i = 0; i < distr_t(1, MAX_PARTS)(rng); i++)
  {
    ret_val += rwgen::parse_pattern(rwgen::pick_pattern(rng), rng);
  }
  return ret_val;
}

std::string rwgen::mutate(std::string origstr, rng_t &rng)
{
  auto isvow = [&](char &c){
    for (const char &ic : rwgen::vowels) if (ic == c) return true;
    return false;
  };
  std::string nstr = origstr;
  while (nstr == origstr)
  {
    nstr = "";
    for (char &c : origstr)
    {
      if (distr_t(0, MUTATION_SCALE)(rng))
      {
        nstr += c;
        continue;
      }
      if (isvow(c)) nstr += randvow(rng);
      else nstr += randcon(rng);
    }
  }
  return nstr;
}

void rwgen::fill_sources(sources_t &src, rng_t &rng)
{
  for (auto &str : src)
  {
    str = make_word(rng);
  }
}

void rwgen::mutate_sources(sources_t &src, rng_t &rng)
{
  for (auto &str : src)
  {
       std::cout << str << '\n';
    for (int i = 0; i < VARIATIONS; i++) std::cout << "-> " << mutate(str, rng) << '\n';
  }
}
