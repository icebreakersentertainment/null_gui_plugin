#ifndef MENUBAR_H_
#define MENUBAR_H_

#include "graphics/gui/IMenuBar.hpp"

#include "Component.hpp"

#include "Menu.hpp"

namespace ice_engine
{
namespace graphics
{
namespace gui
{

class MenuBar : public Component, public IMenuBar
{
public:
	MenuBar() = default;
	virtual ~MenuBar() override = default;

	virtual void tick(const float32 delta) override {};
	
	virtual IMenu* createMenu(const std::string& label) override
	{
		auto menu = std::make_unique<Menu>(label);
		auto menuPtr = menu.get();

		components_.push_back( std::move(menu) );

		return menuPtr;
	}
	
	virtual IMenu* getMenu(const std::string& label) const override { return nullptr; };
};

}
}
}

#endif /* MENUBAR_H_ */
