#ifndef SEPARATOR_H_
#define SEPARATOR_H_

#include "Component.hpp"

namespace ice_engine
{
namespace graphics
{
namespace gui
{

class Separator : public Component
{
public:
	Separator() = default;
	virtual ~Separator() override = default;

	virtual void tick(const float32 delta) override {};
};

}
}
}

#endif /* SEPARATOR_H_ */
