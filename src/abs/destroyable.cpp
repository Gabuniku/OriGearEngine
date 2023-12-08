//
// Created by gabuniku on 23/12/09.
//

#include "abs/destroyable.hpp"
#include <cstdio>

namespace OGEG {
    Destroyable::Destroyable() {
        _destroyed = false;
    };

    Destroyable::~Destroyable() {
        _destroy();
    }

    void Destroyable::_destroy() {
        if (!_destroyed) {
            Destroy();
            _destroyed = true;
        }
    }

    void Destroyable::Destroy() {
        fputs("Error : Must override the Destroyable::Destroy function!", stderr);
    }

} // OGEG