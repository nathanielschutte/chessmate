/**
 * Header to define basic player data and actions
 *
 */

#ifndef IPLAYER_H
#define IPLAYER_H


class IPlayer
{
    public:
        /** Default constructor */
        IPlayer(char* name);

        /** Default destructor */
        virtual ~IPlayer();

        /** Access m_username
         * \return The current value of m_username
         */
        char* getUsername() { return m_username; }

        /** Set m_username
         * \param val New value to set
         */
        void setUsername(char* val) { m_username = val; }

        /** Access m_wins
         * \return The current value of m_wins
         */
        unsigned int getWins() { return m_wins; }

        /** Set m_wins
         * \param val New value to set
         */
        void setWins(unsigned int val) { m_wins = val; }

        /** Increase m_wins by 1
         * \param val New value to set
         */
        void incWins(void) { ++m_wins; }

        /** Access m_losses
         * \return The current value of m_losses
         */
        unsigned int getLosses() { return m_losses; }

        /** Set m_losses
         * \param val New value to set
         */
        void setLosses(unsigned int val) { m_losses = val; }

        /** Increase m_pieces_taken by 1
         * \param val New value to set
         */
        void incLosses(void) { ++m_losses; }

        /** Access m_pieces_taken
         * \return The current value of m_pieces_taken
         */
        unsigned int getPiecesTaken() { return m_pieces_taken; }

        /** Set m_pieces_taken
         * \param val New value to set
         */
        void setPiecesTaken(unsigned int val) { m_pieces_taken = val; }

        /** Increase m_pieces_taken by 1
         * \param val New value to set
         */
        void incPiecesTaken(void) { ++m_pieces_taken; }

        /** Access m_userid
         * \return The current value of m_userid
         */
        unsigned int getUserID() { return m_userid; }

        /** Set m_userid
         * \param val New value to set
         */
        void setUserID(unsigned int val) { m_userid = val; }

    protected:

    private:
        char* m_username; //!< Member variable "m_username"
        unsigned int m_wins; //!< Member variable "m_wins"
        unsigned int m_losses; //!< Member variable "m_losses"
        unsigned int m_pieces_taken; //!< Member variable "m_pieces_taken"
        unsigned int m_userid = -1; //!< Member variable "m_userid"
};

#endif // IPLAYER_H
