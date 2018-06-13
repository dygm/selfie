// This C* code outputs its own source code: quine.c in C*
void initLibrary();
void print(uint64_t* s);
void printInteger(uint64_t i);
void printCharacter(uint64_t c);
void println();
uint64_t main() {
  uint64_t* source;
  uint64_t i;
  initLibrary();
  source = malloc(43*8);
  *(source + 0) = (uint64_t) "// This C* code outputs its own source code: quine.c in C*";
  *(source + 1) = (uint64_t) "void initLibrary();";
  *(source + 2) = (uint64_t) "void print(uint64_t* s);";
  *(source + 3) = (uint64_t) "void printInteger(uint64_t i);";
  *(source + 4) = (uint64_t) "void printCharacter(uint64_t c);";
  *(source + 5) = (uint64_t) "void println();";
  *(source + 6) = (uint64_t) "uint64_t main() {";
  *(source + 7) = (uint64_t) "  uint64_t* source;";
  *(source + 8) = (uint64_t) "  uint64_t i;";
  *(source + 9) = (uint64_t) "  initLibrary();";
  *(source + 10) = (uint64_t) "  source = malloc(43*8);";
  *(source + 11) = (uint64_t) "  // printing source code before stored code";
  *(source + 12) = (uint64_t) "  i = 0;";
  *(source + 13) = (uint64_t) "  while (i < 11) {";
  *(source + 14) = (uint64_t) "    print(*(source + i));";
  *(source + 15) = (uint64_t) "    println();";
  *(source + 16) = (uint64_t) "    i = i + 1;";
  *(source + 17) = (uint64_t) "  }";
  *(source + 18) = (uint64_t) "  // printing stored source code";
  *(source + 19) = (uint64_t) "  i = 0;";
  *(source + 20) = (uint64_t) "  while (i < 43) {";
  *(source + 21) = (uint64_t) "    print(*(source + 40));";
  *(source + 22) = (uint64_t) "    printInteger(i);";
  *(source + 23) = (uint64_t) "    print(*(source + 41));";
  *(source + 24) = (uint64_t) "    printCharacter(34); // ASCII for doublequote";
  *(source + 25) = (uint64_t) "    print(*(source + i));";
  *(source + 26) = (uint64_t) "    printCharacter(34); // ASCII for doublequote";
  *(source + 27) = (uint64_t) "    print(*(source + 42));";
  *(source + 28) = (uint64_t) "    println();";
  *(source + 29) = (uint64_t) "    i = i + 1;";
  *(source + 30) = (uint64_t) "  }";
  *(source + 31) = (uint64_t) "  // printing source code after stored code";
  *(source + 32) = (uint64_t) "  i = 11;";
  *(source + 33) = (uint64_t) "  while (i < 40) {";
  *(source + 34) = (uint64_t) "    print(*(source + i));";
  *(source + 35) = (uint64_t) "    println();";
  *(source + 36) = (uint64_t) "    i = i + 1;";
  *(source + 37) = (uint64_t) "  }";
  *(source + 38) = (uint64_t) "  return 0;";
  *(source + 39) = (uint64_t) "}";
  *(source + 40) = (uint64_t) "  *(source + ";
  *(source + 41) = (uint64_t) ") = (uint64_t) ";
  *(source + 42) = (uint64_t) ";";
  // printing source code before stored code
  i = 0;
  while (i < 11) {
    print(*(source + i));
    println();
    i = i + 1;
  }
  // printing stored source code
  i = 0;
  while (i < 43) {
    print(*(source + 40));
    printInteger(i);
    print(*(source + 41));
    printCharacter(34); // ASCII for doublequote
    print(*(source + i));
    printCharacter(34); // ASCII for doublequote
    print(*(source + 42));
    println();
    i = i + 1;
  }
  // printing source code after stored code
  i = 11;
  while (i < 40) {
    print(*(source + i));
    println();
    i = i + 1;
  }
  return 0;
}
