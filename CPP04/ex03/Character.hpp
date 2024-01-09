#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		std::string			name;
		static const int	inventorySize = 4;
		AMateria*			inventory[inventorySize];

	public:
		Character();
		Character(const Character& copy);
		Character(const std::string& name);
		~Character();

		Character&	operator=(const Character& other);

		std::string	const & getName() const;
		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter& target);

	public:
		static const int	floorSize = 100;
		int					garbageCount;
		AMateria*			floor[Character::floorSize];
};

#endif
