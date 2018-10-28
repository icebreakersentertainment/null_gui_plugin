#ifndef MENUITEM_H_
#define MENUITEM_H_

#include "graphics/gui/IMenuItem.hpp"

#include "Component.hpp"

namespace ice_engine
{
namespace graphics
{
namespace gui
{

class MenuItem : public Component, public IMenuItem
{
public:
	MenuItem(const std::string& label = std::string()) {};
	virtual ~MenuItem() override = default;

	virtual void tick(const float32 delta) override {};
	
	virtual void setLabel(const std::string& label) override {};
	virtual const std::string& getLabel() const  override { return label_; };
	
	virtual void setCallback(std::function<void()>& callback) override {};
	
private:
	std::string label_;
};

}
}
}

#endif /* MENUITEM_H_ */
