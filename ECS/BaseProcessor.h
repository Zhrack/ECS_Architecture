#ifndef BASE_PROCESSOR_H_
#define BASE_PROCESSOR_H_

#include <vector>
#include <memory>
#include <unordered_map>

#include "Observer.h"
#include "Dependency.h"

class EntityManager;

class BaseProcessor : public Observer
{
public:
    BaseProcessor(EntityManager* manager, const std::vector<CompType>& deps);
    virtual ~BaseProcessor();

    void updateIntersection(std::vector<Dependency>& newEntities);

    void updateProcessor(float elapsed);

protected:
    virtual void update(float elapsed) = 0;

    // event callbacks
    void onNewComponent(const Event& event);
    void onRemoveComponent(const Event& event);
    void onNewEntity(const Event& event);
    void onRemoveEntity(const Event& event);

protected:
    /// <summary>
    /// The list of dependencies of this Processor
    /// </summary>
    std::vector<CompType>   mWantedTypes;
    std::vector<Dependency> mCurrentDeps;

    EntityManager*          mEntityMngr;


    // Inherited via Observer
    virtual void onNotify(const Event & event) override;

};

using BaseProcessorPtr = std::unique_ptr<BaseProcessor>;

#endif // !BASE_PROCESSOR_H_
