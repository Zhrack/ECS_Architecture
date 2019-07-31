#ifndef COMPONENT_DEFS_H_
#define COMPONENT_DEFS_H_

#include <vector>
#include <memory>

using EntityID = unsigned long;

template<typename T>
using Component = std::vector<std::unique_ptr<T>>;

#endif // !COMPONENT_DEFS_H_
