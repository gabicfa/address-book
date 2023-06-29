#include "StringUtils.h"

namespace utils {
    std::string toLowerCase(const std::string& input) {
        // Convert a string to lowercase
        std::string lowercasedInput = input;
        std::transform(lowercasedInput.begin(), lowercasedInput.end(), lowercasedInput.begin(), ::tolower);
        return lowercasedInput;
    }
}
