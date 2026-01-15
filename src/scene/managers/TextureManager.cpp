#include "TextureManager.h"
/*
#include <algorithm>

void TextureManager::Add(Texture* newData)
{
   data.push_back(newData);
}

bool TextureManager::Remove(const unsigned int id)
{
   auto it = FindIterator(id);
   if (it != data.end())
   {
      data.erase(it);
      return true;
   }
   return false;
}

Texture* TextureManager::Find(const unsigned int id)
{
   auto it = FindIterator(id);
   return (it != data.end()) ? *it : nullptr;
}

std::vector<Texture*>::iterator TextureManager::FindIterator(const unsigned int id)
{
   auto finder = [id](auto itElement) {
      return (itElement->GetId() == id);
   };
   return std::find_if(data.begin(), data.end(), finder);
}
*/
