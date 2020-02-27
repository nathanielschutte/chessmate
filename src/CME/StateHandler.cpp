#include "StateHandler.h"

namespace CME {
    StateHandler::StateHandler(IGame* game)
    {
        m_game = game;
    }

    StateHandler::~StateHandler()
    {
        deinitCurrent();
        for(int i = 0; i < states.size(); i++)
        {
            states.at(i).state_it->clean();
        }
    }

    // nothing really yet
    void StateHandler::init()
    {
        request_flag = NONE;
        state_cur = nullptr;
        state_req = nullptr;
    }

    void StateHandler::updateCurrentState(sf::RenderWindow& window, const float time_delta)
    {
        updateCurrent(window, time_delta);
    }

    void StateHandler::drawCurrentState(sf::RenderTarget& target, const float interp)
    {
        drawCurrent(target, interp);
    }


    void StateHandler::requestState(ref_id s_req, req_t type_req)
    {
        if(type_req)
        {
            state_req = getStateClass(s_req);
            if(state_req != nullptr)
            {
                request_flag = type_req;
            }
        }
    }

    void StateHandler::requestStateChange(ref_id state_req)
    {
        requestState(state_req, CHANGE);
    }

    void StateHandler::requestStateReset()
    {
        requestState(1, RESET);
    }


    /**
    * Perform requested state request
    * Room for error handling (multiple errors, integer code) upon bad init/deinit/reinit
    */
    bool StateHandler::fulfillRequest()
    {
        int req_status = 0; // track request status
        switch(request_flag)
        {
        case CHANGE:
            req_status = initRequest(); // attempt request init
            if(req_status < 0)
            {
                switch(req_status)
                {
                case I_ASSET_LOAD_ERROR:
                    throw "Error loading required state assets";
                }
                default:
                    throw "Could not initialize requested state";
            }
            req_status = deinitCurrent(); // attempt current deinit
            if(req_status < 0)
            {
                throw "Could not de-initialize current state";
            }

            // change current state over to request
            state_cur = state_req;

            break; // end CHANGE
        case RESET:
            req_status = reinitCurrent();
            if(req_status < 0)
            {
                throw "Could not re-initialize current state";
            }

            break; // end RESET
        }
        request_flag = NONE; // only tries once
        return req_status == 0; // true on success, nothing changes this right now
    }

    void StateHandler::setInitialState(ref_id state_req)
    {
        IState* state_init = getStateClass(state_req);
        if(state_init != nullptr)
        {
            state_cur = state_init;
            initCurrent();
        }
    }

    void StateHandler::addState(ref_id state_ref, IState* state_it)
    {
        state_id state_push;
        state_push.state_ref = state_ref;
        state_push.state_it = state_it;
        states.push_back(state_push);
    }

    IState* StateHandler::getStateClass(ref_id state_ref)
    {
        IState* state_r = nullptr;
        for(unsigned int i = 0; i < states.size(); i++)
        {
            if(states.at(i).state_ref == state_ref)
            {
                state_r = states.at(i).state_it;
            }
        }

        return state_r;
    }


    void StateHandler::updateCurrent(sf::RenderWindow& window, const float time_delta)
    {
        if(state_cur != nullptr)
        {
            state_cur->update(window, time_delta);
        }
    }


    void StateHandler::drawCurrent(sf::RenderTarget& target, const float interp)
    {
        if(state_cur != nullptr)
        {
            state_cur->draw(target, interp);
        }
    }


    /**
    * Attempt to init current state, return -1 on error
    */
    int StateHandler::initCurrent()
    {
        if(state_cur != nullptr)
        {
            return state_cur->init();
        }
        else
            return -1;
    }

    /**
    * Attempt to deinit current state, return -1 on error
    */
    int StateHandler::deinitCurrent()
    {
        if(state_cur != nullptr)
        {
            return state_cur->deinit();
        }
        else
            return -1;
    }

    /**
    * Attempt to reinit current state, return -1 on error
    */
    int StateHandler::reinitCurrent()
    {
        if(state_cur != nullptr)
        {
            return state_cur->reinit();
        }
        else
            return -1;
    }

    /**
    * Attempt to init current state, return -1 on error
    */
    int StateHandler::initRequest()
    {
        if(state_req != nullptr)
        {
            return state_req->init();
        }
        else
            return -1;
    }
}
