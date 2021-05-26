///Reference: https://stackoverflow.com/questions/5056645/sorting-stdmap-using-value
#include "utils.h"


void toLowerCase(string& s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
}


