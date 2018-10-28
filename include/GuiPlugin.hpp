#ifndef GUIPLUGIN_H_
#define GUIPLUGIN_H_

#include <memory>

#include "IGuiPlugin.hpp"

namespace ice_engine
{

class GuiPlugin : public IGuiPlugin
{
public:
	GuiPlugin() = default;
	virtual ~GuiPlugin() override = default;

	virtual std::string getName() const override;

	virtual std::unique_ptr<graphics::gui::IGuiFactory> createFactory() const override;

};

}

#endif /* GUIPLUGIN_H_ */
