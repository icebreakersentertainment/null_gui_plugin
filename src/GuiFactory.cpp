#include "GuiFactory.hpp"

#include "Gui.hpp"

namespace ice_engine
{
namespace graphics
{
namespace gui
{

std::unique_ptr<IGui> GuiFactory::create(
	utilities::Properties* properties,
	fs::IFileSystem* fileSystem,
	logger::ILogger* logger,
	IGraphicsEngine* graphicsEngine
)
{
	std::unique_ptr<IGui> ptr = std::make_unique< Gui >( properties, fileSystem, logger, graphicsEngine );
	
	return std::move( ptr );
}

}
}
}
