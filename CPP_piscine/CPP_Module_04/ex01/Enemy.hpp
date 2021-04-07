
#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>
# include <string>

class Enemy
{
	private:
		int _HP;
		std::string _Type;
		Enemy();
	public:
		/* canonical */
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		Enemy &operator= (const Enemy& rhs);
		virtual ~Enemy();

		/* getters */
		std::string const getType() const;
		int getHP() const;
		
		/* setters */
		void setHP(int value); 
		void setType(std::string type);

		/* actions */
		virtual void takeDamage(int damage);
};

#endif
