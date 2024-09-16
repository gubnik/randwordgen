#include "header/rwordgen.hpp"

int main (int argc, char ** argv)
{
  std::random_device dev;
  rwgen::rng_t rng (dev());
  rwgen::sources_t Sources;
  rwgen::fill_sources(Sources, rng);
  rwgen::mutate_sources(Sources, rng);
  
  return 0;
}
