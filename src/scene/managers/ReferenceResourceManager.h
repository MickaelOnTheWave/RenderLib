#ifndef REFERENCERESOURCEMANAGER_H
#define REFERENCERESOURCEMANAGER_H

#include <algorithm>
#include <vector>

template <class T>
class ReferenceResourceManager
{
public:
   ReferenceResourceManager() = default;
   virtual ~ReferenceResourceManager() = default;

   unsigned int Add(T* newData);
   bool Remove(const unsigned int id);
   T* Find(const unsigned int id);

   const std::vector<T*>& GetData() const;

private:
   typename std::vector<T*>::iterator FindIterator(const unsigned int id);

   std::vector<T*> data;
   unsigned int nextId = 0;
};

template <class T>
unsigned int ReferenceResourceManager<T>::Add(T* newData)
{
   data.push_back(newData);
   newData->id = nextId;
   return nextId++;
}

template <class T>
bool ReferenceResourceManager<T>::Remove(const unsigned int id)
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
T* ReferenceResourceManager<T>::Find(const unsigned int id)
{
   auto it = FindIterator(id);
   return (it != data.end()) ? *it : nullptr;
}

template<class T>
inline const std::vector<T*>& ReferenceResourceManager<T>::GetData() const
{
   return data;
}

template <class T>
typename std::vector<T*>::iterator ReferenceResourceManager<T>::FindIterator(const unsigned int id)
{
   auto finder = [id](auto itElement) {
      return (itElement->GetId() == id);
   };
   return std::find_if(data.begin(), data.end(), finder);
}

#endif // REFERENCERESOURCEMANAGER_H
