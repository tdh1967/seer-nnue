#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

#include <move.h>

namespace search{

using depth_type = int;

struct constants{
  size_t thread_count_;
  
  const size_t& thread_count() const { return thread_count_; }
  depth_type reduce_depth() const { return 3; }
  depth_type max_depth() const { return 128; }
  depth_type aspiration_depth() const { return 4; }
  
  template<bool is_pv>
  depth_type reduction(const depth_type& depth, const size_t& move_idx) const {
    if(move_idx == 0) return 0;
    if(move_idx < 6) return 1;
    if constexpr(is_pv){
      return depth / 4;
    }else{
      return depth / 2;
    }
  }

  constants& update_(const size_t& thread_count){
    thread_count_ = thread_count;
    return *this;
  }

  constants(const size_t& thread_count){ update_(thread_count); }
};



}
