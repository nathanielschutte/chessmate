#ifndef STATEHANDLER_H
#define STATEHANDLER_H

#include "IState.h"
#include "CME/IGame.h"

#include <stddef.h>
#include <SFML/Graphics.hpp>

namespace CME {

    typedef int req_t;
    typedef int ref_id;

    struct state_id {
        IState* state_it;
        ref_id state_ref;
    };

    class StateHandler
    {
        const ref_id HOLD = -1;

        const req_t NONE = 0;
        const req_t CHANGE = 1;
        const req_t RESET = 2;

        public:
            StateHandler(IGame* game);
            virtual ~StateHandler();

            void init();

            void addState(ref_id state_ref, IState* state_it);

            void requestState(ref_id state_req, req_t type_req);

            void requestStateChange(ref_id state_req);

            void requestStateReset();

            bool fulfillRequest();

            void setInitialState(ref_id state_req);

            void updateCurrentState(sf::RenderWindow& window, const float time_delta);

            void drawCurrentState(sf::RenderTarget& target, const float interp);


            inline req_t requestFlag() {return request_flag; }

        protected:

        private:
            IGame* m_game;
            IState* state_cur; // current, active state
            IState* state_req; // requested state

            std::vector<state_id> states;

            req_t request_flag; // holds request type, 0 if none


            // ==========================

            IState* getStateClass(ref_id state_ref);

            int initCurrent();

            int deinitCurrent();

            int reinitCurrent();

            int initRequest();

            void updateCurrent(sf::RenderWindow& window, const float time_delta);

            void drawCurrent(sf::RenderTarget& target, const float interp);

    };
}

#endif // STATEHANDLER_H
