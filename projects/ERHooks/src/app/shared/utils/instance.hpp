#pragma once

#include <vector>

template<typename T>
class Instances;

template <typename T>
class Instance
{
private:
    inline static std::vector<T *> insts{};

private:
    friend class Instances<T>;

public:
    Instance(T *const ptr) {
        insts.push_back(ptr);
    }
};

template<typename T>
class Instances final
{
public:
    inline static const std::vector<T *> &Get() {
        return Instance<T>::insts;
    }
};