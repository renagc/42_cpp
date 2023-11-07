#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	private:
		std::string 	_name;
		int				_hitpoints;
		int				_energypoints;
		int				_attackdmg;

	public:
		ClapTrap( void );
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		const std::string &getName( void ) const;
		int	getHitPoints( void ) const;
		int getEnergyPoints( void ) const;
		int getAttackDamage( void ) const;

		void setName( const std::string &name );
		void setHitPoints( int value );
		void setEnergyPoints( int value );
		void setAttackDamage( int value );
};

#endif
