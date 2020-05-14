
#include <ostream>
namespace Color {
    enum Code {
      /* Foreground color codes */
      FG_RED      = 31,
      FG_GREEN    = 32,
      FG_YELLOW   = 33,
      FG_BLUE     = 34,
      FG_MAGENTA  = 35,
      FG_CYAN     = 36,
      FG_WHITE    = 37,
      FG_DEFAULT  = 39,

      /* Some background color codes, not used */
      BG_RED      = 41,
      BG_GREEN    = 42,
      BG_BLUE     = 44,
      BG_DEFAULT  = 49
    };
    std::ostream& operator<<(std::ostream& os, Code code) {
        return os << "\033[" << static_cast<int>(code) << "m";
    }
}
