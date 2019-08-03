#ifndef RENDER_PROCESSOR_H_
#define RENDER_PROCESSOR_H_

#include "BaseProcessor.h"

#include <SFML/Graphics.hpp>

class RenderProcessor : public BaseProcessor
{
public:
    RenderProcessor(EntityManager* manager, sf::RenderWindow* win);
    virtual ~RenderProcessor();

    // Inherited via BaseProcessor
    virtual void update(float elapsed) override;

private:
    // Inherited via BaseProcessor
    virtual void onNotify(const Event & event) override;

private:
    sf::RenderWindow* mWindow;
};


#endif // !RENDER_PROCESSOR_H_
