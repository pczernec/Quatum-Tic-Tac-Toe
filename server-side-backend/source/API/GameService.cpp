#include "../../headers/API/GameService.hpp"

GameService::GameService(
    shared_ptr<IResourceFactory> resource_factory, shared_ptr<IResourceFactory> resource_factory2,
    shared_ptr<IServiceSettingsFactory> settings_factory)
{
    _settings_factory = settings_factory;
    _service.publish(resource_factory->get_resource());
    _service.publish(resource_factory2->get_resource());

}

void GameService::start()
{
    _service.start(_settings_factory->get_settings());
}

