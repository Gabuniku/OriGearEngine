//
// Created by gabuniku on 23/12/09.
//

#ifndef ORIGEAR_DESTROYABLE_HPP
#define ORIGEAR_DESTROYABLE_HPP

namespace OGEG {

    class Destroyable {
    private:
        bool _destroyed = true;

        void _destroy();

    public:
        Destroyable();

        ~Destroyable();

        virtual void Destroy();

    };

} // OGEG

#endif //ORIGEAR_DESTROYABLE_HPP
