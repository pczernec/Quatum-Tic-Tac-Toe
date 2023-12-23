#pragma once

#include "IService.hpp"

#include "IResourceFactory.hpp"
#include "IServiceSettingsFactory.hpp"

class GameService : public IService {
    public:
        GameService(
            shared_ptr<IResourceFactory> resource_factory,
            shared_ptr<IResourceFactory> resource_factory2,
            shared_ptr<IServiceSettingsFactory> settings_factory);

        void start() final;

    private:
        Service _service;
        shared_ptr<IServiceSettingsFactory> _settings_factory;
};