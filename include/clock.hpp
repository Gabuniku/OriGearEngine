//
// Created by gabuniku on 2023/12/11.
//

#ifndef ORIGEAR_CLOCK_HPP
#define ORIGEAR_CLOCK_HPP

#include <cstdint>

namespace OGEG {

    class Clock {
    private:
        uint32_t _last = 0;
        uint32_t _wait_ms = 0;
    public:
        Clock();

        Clock(uint32_t fps);

        void Wait();

        void Wait(uint32_t fps);

    };

} // OGEG

#endif //ORIGEAR_CLOCK_HPP
