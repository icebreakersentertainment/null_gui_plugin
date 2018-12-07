#ifndef WINDOW_H_
#define WINDOW_H_

#include <algorithm>

#include "graphics/gui/IWindow.hpp"

#include "Component.hpp"

#include "Label.hpp"
#include "Button.hpp"
#include "MenuBar.hpp"
#include "Rectangle.hpp"

namespace ice_engine
{
namespace graphics
{
namespace gui
{

class Window : public Component, public IWindow
{
public:
	Window(const uint32 x, const uint32 y, const uint32 width, const uint32 height, const std::string& title = std::string()) {};
	Window(const uint32 x, const uint32 y, const uint32 width, const uint32 height, const uint32 flags, const std::string& title = std::string()) {};
	virtual ~Window() override = default;

	virtual void tick(const float32 delta) override {};

	virtual ILabel* createLabel(const uint32 x, const uint32 y, const uint32 width, const uint32 height, const std::string label = std::string()) override
	{
		auto l = std::make_unique<Label>(x, y, width, height, label);
		auto labelPtr = l.get();
		components_.push_back( std::move(l) );

		return labelPtr;
	}

	virtual IButton* createButton(const uint32 x, const uint32 y, const uint32 width, const uint32 height, const std::string label = std::string()) override
	{
		auto button = std::make_unique<Button>(x, y, width, height, label);
		auto buttonPtr = button.get();
		components_.push_back( std::move(button) );

		return buttonPtr;
	}

	virtual IMenuBar* createMenuBar() override
	{
		auto menuBar = std::make_unique<MenuBar>();
		auto menuBarPtr = menuBar.get();
		components_.push_back( std::move(menuBar) );

		return menuBarPtr;
	}

	virtual IRectangle* createRectangle(const glm::vec2& start, const glm::vec2& end, const Color& color) final
	{
		auto rectangle = std::make_unique<Rectangle>(start, end, color);
		auto rectanglePtr = rectangle.get();
		components_.push_back( std::move(rectangle) );

		return rectanglePtr;
	}

	virtual void destroy(const ILabel* label) override
	{
		components_.erase(
			std::remove_if(
				components_.begin(),
				components_.end(),
				[label](const std::unique_ptr<IComponent>& c) {
					return c.get() == label;
				}
			),
			components_.end()
		);
	}

	virtual void destroy(const IButton* button) override
	{
		components_.erase(
			std::remove_if(
				components_.begin(),
				components_.end(),
				[button](const std::unique_ptr<IComponent>& c) {
					return c.get() == button;
				}
			),
			components_.end()
		);
	}

	virtual void destroy(const IRectangle* rectangle) final
	{
		components_.erase(
			std::remove_if(
				components_.begin(),
				components_.end(),
				[rectangle](const std::unique_ptr<IComponent>& c) {
					return c.get() == rectangle;
				}
			),
			components_.end()
		);
	}

	virtual void setTitle(const std::string& title) override {};
	virtual const std::string& getTitle() const  override { return title_; };

	virtual void setBackgroundAlpha(const float32 alpha) final
			{

			}

private:
	std::string title_;
};

}
}
}

#endif /* WINDOW_H_ */
