#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <algorithm>
#include <vector>

template <class T>
class ResourceManager
{
public:
   ResourceManager() = default;
   virtual ~ResourceManager() = default;

   void Add(T* newData);
   bool Remove(const unsigned int id);
   T* Find(const unsigned int id);

   const std::vector<T*>& GetData() const;

private:
   typename std::vector<T*>::iterator FindIterator(const unsigned int id);

   std::vector<T*> data;
};

template <class T>
void ResourceManager<T>::Add(T* newData)
{
   data.push_back(newData);
}

template <class T>
bool ResourceManager<T>::Remove(const unsigned int id)
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
T* ResourceManager<T>::Find(const unsigned int id)
{
   auto it = FindIterator(id);
   return (it != data.end()) ? *it : nullptr;
}

template<class T>
inline const std::vector<T*>& ResourceManager<T>::GetData() const
{
   return data;
}

template <class T>
typename std::vector<T*>::iterator ResourceManager<T>::FindIterator(const unsigned int id)
{
   auto finder = [id](auto itElement) {
      return (itElement->GetId() == id);
   };
   return std::find_if(data.begin(), data.end(), finder);
}

#endif // RESOURCEMANAGER_H
