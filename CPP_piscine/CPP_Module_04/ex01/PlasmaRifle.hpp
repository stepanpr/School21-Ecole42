


#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

// PlasmaRifle:
// ◦ Name: "Plasma Rifle"
// ◦ Damage: 21
// ◦ AP cost: 5
// ◦ Output of attack(): "* piouuu piouuu piouuu *"

class PlasmaRifle : public AWeapon
{
	private:
		std::string _Name;
		int _Damage;
		int _AP;
		PlasmaRifle(std::string const & name, int apcost, int damage);
	public:
		/* canonical */
		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const & src);
		PlasmaRifle &operator= (const PlasmaRifle& rhs);
		virtual ~PlasmaRifle();

		/* actions */
		virtual void attack() const;
};

#endif
