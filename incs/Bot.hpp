#ifndef BOT_HPP
#define BOT_HPP

/* For std::string */
#include <string>

/* For std::set */
#include <vector>

/* For std::map */
#include <map>

/* For std::set */
#include <set>

/* For std::istringstream */
#include <sstream>


/* For send() */
#include <sys/socket.h>

/* Déclaration anticipée de Client */
class Client;

/* Déclaration anticipée de Channel */
class Channel;

/**
 * class Bot
 */
class Bot
{
    public:

        /* Constructeur */
        Bot();

        /* Destructeur */
        ~Bot();


        /*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */
        /*                                   MOTS INTERDITS                          */
        /*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */

        /* Ajoute un mot interdit */
        void addForbiddenWord(const std::string &word);

        /* Retire un mot interdit */
        void removeForbiddenWord(const std::string &word);

        /* Vérifie si un mot est interdit */
        bool isForbiddenWord(const std::string &word) const;


        /*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */
        /*                                   MESSAGES                                */
        /*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */

        /* Traite un message */
        void handleMessage(Client *client, Channel *channel, const std::string &message);


        /*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */
        /*                                 SANCTIONS                                 */
        /*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */

        /* Ajoute un avertissement */
        void sendWarning(Client *client, Channel *channel);

        /* Exclut un client */
        void kickClient(Client *client, Channel *channel);

    private:
    
        /*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */
        /*                              DONNÉES INTERNES                             */
        /*   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   */

        /* Mots interdits */
        std::set<std::string> _forbiddenWords;

        /* Avertissements */
        std::map<Client*, int> _warnings;
};

#endif /* BOT_HPP */
