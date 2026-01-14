#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Brain
{
	private:
		static const int N = 100;
		std::string ideas[N];
	public:
		Brain();
		~Brain();
		Brain& operator=(const Brain& obj);
		Brain(const Brain& other);
		std::string* getIdeas();
		void setIdea(std::string idea);
};

#endif