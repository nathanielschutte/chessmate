#ifndef ISTATE_H
#define ISTATE_H

#include <SFML/Graphics.hpp>

namespace CME {

    // -1 reserved for null pointer failures
    static const int I_ASSET_LOAD_ERROR = -2;

    class IState
    {
        public:
            IState();

            virtual ~IState();

            // provide error codes defined above
            virtual int init() = 0;

            virtual int deinit() = 0;

            virtual int reinit() = 0;

            virtual void clean() = 0; // data to be cleaned while uninitialized, save data

            virtual void update(sf::RenderWindow& window, const float time_delta) = 0;

            virtual void draw(sf::RenderTarget& target, const float interp) = 0;

        protected:

    };
}

#endif // ISTATE_H
