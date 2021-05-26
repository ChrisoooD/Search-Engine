///Reference: https://stackoverflow.com/questions/5056645/sorting-stdmap-using-valuecc
#ifndef SEARCH_ENGINE_UTILS_H
#define SEARCH_ENGINE_UTILS_H

#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)

#include <utility>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void toLowerCase(string& s);

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
  return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
  std::multimap<B,A> dst;
  std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
                 flip_pair<A,B>);
  return dst;
}



#endif //SEARCH_ENGINE_UTILS_H
