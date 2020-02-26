#ifndef STATEHANDLER_H
#define STATEHANDLER_H

namespace CME {

    enum Request {Change, Reinit};

    enum State {StartMenu, InGame, PostGame, Hold};

    class StateHandler
    {
        public:
            StateHandler();
            virtual ~StateHandler();

        void request(State state_req, Request type_req)

        protected:

        private:
    };
}

#endif // STATEHANDLER_H
