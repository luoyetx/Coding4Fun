#pragma once

#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include "./logging.h"

namespace ds {

inline void SetRandomSeed() {
  srand(time(NULL));
}
inline void SetRandomSeed(int seed) {
  srand(seed);
}

}  // namespace ds
