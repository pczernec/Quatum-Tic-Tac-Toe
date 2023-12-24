#pragma once

#include <memory>
#include <restbed>

using namespace std;
using namespace restbed;

string bytes_to_string(int size, const Byte* start);

class IResourceFactory {
    public:
        virtual shared_ptr<Resource> get_resource() const = 0;

};