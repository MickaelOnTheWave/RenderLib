#ifndef VALUERESOURCEMANAGER_H
#define VALUERESOURCEMANAGER_H

#include <algorithm>
#include <vector>

template <class T>
class ValueResourceManager
{
public:
   ValueResourceManager() = default;
   virtual ~ValueResourceManager() = default;

   unsigned int Add(T& newData);
   bool Remove(const unsigned int id);
   T& Find(const unsigned int id);

   const std::vector<T>& GetData() const;

private:
   typename std::vector<T>::iterator FindIterator(const unsigned int id);

   std::vector<T> data;
   unsigned int nextId = 0;
};

template <class T>
unsigned int ValueResourceManager<T>::Add(T& newData)
{
   data.push_back(newData);
   newData.id = nextId;
   return nextId++;
}

template <class T>
bool ValueResourceManager<T>::Remove(const unsigned int id)
{
   auto it = FindIterator(id);
   if (it != data.end())
   {
      data.erase(it);
      return true;
   }
   return false;
}

template <class T>
T& ValueResourceManager<T>::Find(const unsigned int id)
{
   auto it = FindIterator(id);
   return (it != data.end()) ? *it : nullptr;
}

template<class T>
inline const std::vector<T>& ValueResourceManager<T>::GetData() const
{
   return data;
}

template <class T>
typename std::vector<T>::iterator ValueResourceManager<T>::FindIterator(const unsigned int id)
{
   auto finder = [id](auto itElement) {
      return (itElement->GetId() == id);
   };
   return std::find_if(data.begin(), data.end(), finder);
}

#endif // VALUERESOURCEMANAGER_H
