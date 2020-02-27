/**
 * Header to define basic player data and actions
 *
 */

#ifndef IPLAYER_H
#define IPLAYER_H


namespace CME {
    class IPlayer
    {
        public:
            IPlayer(char* name);
            virtual ~IPlayer();

            char* getUsername() { return m_username; }

            void setUsername(char* val) { m_username = val; }

            unsigned int getWins() { return m_wins; }

            void setWins(unsigned int val) { m_wins = val; }

            void incWins(void) { ++m_wins; }

            unsigned int getLosses() { return m_losses; }

            void setLosses(unsigned int val) { m_losses = val; }

            void incLosses(void) { ++m_losses; }

            unsigned int getUserID() { return m_userid; }

            void setUserID(unsigned int val) { m_userid = val; }

        protected:

        private:
            char* m_username;
            unsigned int m_wins;
            unsigned int m_losses;
            unsigned int m_userid = -1;
    };
}

#endif // IPLAYER_H
