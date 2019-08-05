#ifndef MOVEMENT_PROCESSOR_H_
#define MOVEMENT_PROCESSOR_H_

#include "BaseProcessor.h"

class MovementProcessor :
    public BaseProcessor
{
public:
    MovementProcessor(EntityManager* manager);
    virtual ~MovementProcessor();

    // Inherited via BaseProcessor
    virtual void update(float elapsed) override;
};


#endif // !MOVEMENT_PROCESSOR_H_
