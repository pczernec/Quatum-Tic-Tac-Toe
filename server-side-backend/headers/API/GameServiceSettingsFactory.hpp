# pragma once

#include "IServiceSettingsFactory.hpp"

class GameServiceSettingsFactory : public IServiceSettingsFactory {
    public:
        GameServiceSettingsFactory();
        shared_ptr<Settings> get_settings() const final;

    private:
        shared_ptr<Settings> _settings;

};