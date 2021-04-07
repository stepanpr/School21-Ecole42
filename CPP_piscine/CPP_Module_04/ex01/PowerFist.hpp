


#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include "AWeapon.hpp"

// • PowerFist:
// ◦ Name: "Power Fist"
// ◦ Damage: 50
// ◦ AP cost: 8
// ◦ Output of attack(): "* pschhh... SBAM! *"

class PowerFist : public AWeapon
{
	private:
		std::string _Name;
		int _Damage;
		int _AP;
	public:
		/* canonical */
		PowerFist();
		PowerFist(std::string const & name, int apcost, int damage);
		PowerFist(PowerFist const & src);
		PowerFist &operator= (const PowerFist& rhs);
		virtual ~PowerFist();

		/* actions */
		virtual void attack() const;
};

#endif
