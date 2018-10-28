#ifndef MENU_H_
#define MENU_H_

#include "graphics/gui/IMenu.hpp"

#include "Component.hpp"

#include "MenuItem.hpp"
#include "Separator.hpp"

namespace ice_engine
{
namespace graphics
{
namespace gui
{

class Menu : public Component, public IMenu
{
public:
	Menu(const std::string& label = std::string()) {};
	virtual ~Menu() override = default;

	virtual void tick(const float32 delta) override {};
	
	virtual void setLabel(const std::string& label) override {};
	virtual const std::string& getLabel() const  override { return label_; };
	
	virtual IMenu* createMenu(const std::string& label) override
	{
		auto menu = std::make_unique<Menu>(label);
		auto menuPtr = menu.get();

		components_.push_back( std::move(menu) );

		return menuPtr;
	}

	virtual IMenu* getMenu(const std::string& label) const  override { return nullptr; };
	
	virtual void createSeparator() override
	{
		auto separator = std::make_unique<Separator>();
		components_.push_back( std::move(separator) );
	}
	
	virtual IMenuItem* createMenuItem(const std::string& label) override
	{
		auto menuItem = std::make_unique<MenuItem>(label);
		auto menuItemPtr = menuItem.get();

		components_.push_back( std::move(menuItem) );

		return menuItemPtr;
	}
	
private:
	std::string label_;
};

}
}
}

#endif /* MENU_H_ */
