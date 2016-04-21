
#include "FreeSpeech-cpp/crypto.h"

extern "C" {
    void* RSA_GenKey_C(size_t bits) {
      RSA_GenKey(bits);
    }
}