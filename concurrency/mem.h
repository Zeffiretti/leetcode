#ifndef CXX_MEM
#define CXX_MEM
#include <memory>
// if cxx < 14
#if __cplusplus < 201402L
namespace std {
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
}  // namespace std
#endif /* __cplusplus < 201402L */

#endif /* CXX_MEM */
