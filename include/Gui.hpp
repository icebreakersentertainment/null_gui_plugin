#ifndef GUI_H_
#define GUI_H_

#include <vector>
#include <memory>

#include "graphics/IGraphicsEngine.hpp"
#include "graphics/gui/IGui.hpp"

#include "Component.hpp"
#include "Window.hpp"

#include "graphics/IEventListener.hpp"

#include "utilities/Properties.hpp"
#include "logger/ILogger.hpp"
#include "fs/IFileSystem.hpp"

namespace ice_engine
{
namespace graphics
{
namespace gui
{

class Gui : public IGui, public graphics::IEventListener
{
public:
	Gui(
		utilities::Properties* properties,
		fs::IFileSystem* fileSystem,
		logger::ILogger* logger,
		IGraphicsEngine* graphicsEngine
	) {};
	virtual ~Gui() override = default;

	virtual void setViewport(const uint32 width, const uint32 height) override {};

	virtual void render() override {};
	virtual void tick(const float32 delta) override {};
	
	virtual IWindow* createWindow(const uint32 x, const uint32 y, const uint32 width, const uint32 height, const std::string title = std::string()) override
	{
		auto window = std::make_unique<Window>(x, y, width, height, title);
		windows_.push_back( std::move(window) );

		return windows_.back().get();
	}

	virtual IWindow* createWindow(const uint32 x, const uint32 y, const uint32 width, const uint32 height, const uint32 flags, const std::string title = std::string()) override
	{
		auto window = std::make_unique<Window>(x, y, width, height, flags, title);
		windows_.push_back( std::move(window) );

		return windows_.back().get();
	}
	
	virtual bool processEvent(const graphics::WindowEvent& event) override { return false; };
	virtual bool processEvent(const graphics::KeyboardEvent& event) override { return false; };
	virtual bool processEvent(const graphics::MouseButtonEvent& event) override { return false; };
	virtual bool processEvent(const graphics::MouseMotionEvent& event) override { return false; };
	virtual bool processEvent(const graphics::MouseWheelEvent& event) override { return false; };
	
	// Implements the IEventListener interface
	virtual bool processEvent(const graphics::Event& event) override { return false; };

private:
	std::vector<std::unique_ptr<IWindow>> windows_;
};

}
}
}

#endif /* GUI_H_ */
