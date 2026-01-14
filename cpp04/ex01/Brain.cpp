#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "A brain has been created!" << std::endl;
}

Brain::~Brain()
{
    std::cout << "A brain has been destroyed!" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return (*this);
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy constructor created" << std::endl;
}

std::string* Brain::getIdeas()
{
    return (this->ideas);
}

void Brain::setIdea(std::string idea)
{
    for (int i = 0; i < this->N; i++)
    {
        if (this->ideas[i].empty())
        {
            ideas[i] = idea;
            break;
        }
    }
}