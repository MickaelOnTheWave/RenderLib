#ifndef NAMEDENTITY_H
#define NAMEDENTITY_H

#include <string>

class NamedEntity
{
public:
    NamedEntity(const std::string& _name);
    NamedEntity(const NamedEntity& other);

    std::string GetName() const;

private:
    const std::string name;
};

#endif // NAMEDENTITY_H
