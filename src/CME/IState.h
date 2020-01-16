#ifndef ISTATE_H
#define ISTATE_H

namespace CME {
    class IState
    {
        public:
            IState();

            virtual ~IState();

        protected:

            virtual void init(void) = 0;

            virtual void deinit(void) = 0;

            virtual void reinit(void) = 0;
    };
}

#endif // ISTATE_H
