/*
** Logger.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by mateandmetal
** Login   <https://github.com/SFML/SFML/wiki/Source%3A-Simple-File-Logger-%28by-mateandmetal%29>
**
*/


#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>

// Use the namespace you want
namespace log {

    class Logger {

    public:


        // If you can´t/dont-want-to use C++11, remove the "class" word after enum
        enum class e_logType { LOG_ERROR, LOG_WARNING, LOG_INFO };


        // ctor (remove parameters if you don´t need them)
        explicit Logger (const char *engine_version, const char *fname = "log_log.txt")
                :   numWarnings (0U),
                    numErrors (0U)
        {

            myFile.open (fname);

            // Write the first lines
            if (myFile.is_open()) {
                myFile << "My Game Engine, version " << engine_version << std::endl;
                myFile << "Log file created" << std::endl << std::endl;
            } // if

        }


        // dtor
        ~Logger () {

            if (myFile.is_open()) {
                myFile << std::endl << std::endl;

                // Report number of errors and warnings
                myFile << numWarnings << " warnings" << std::endl;
                myFile << numErrors << " errors" << std::endl;

                myFile.close();
            } // if

        }


        // Overload << operator using log type
        friend Logger &operator << (Logger &logger, const e_logType l_type) {

            switch (l_type) {
                case log::Logger::e_logType::LOG_ERROR:
                    logger.myFile << "[ERROR]: ";
                    ++logger.numErrors;
                    break;

                case log::Logger::e_logType::LOG_WARNING:
                    logger.myFile << "[WARNING]: ";
                    ++logger.numWarnings;
                    break;

                default:
                    logger.myFile << "[INFO]: ";
                    break;
            } // sw


            return logger;

        }


        // Overload << operator using C style strings
        // No need for std::string objects here
        friend Logger &operator << (Logger &logger, const char *text) {

            logger.myFile << text << std::endl;
            return logger;

        }


        // Make it Non Copyable (or you can inherit from sf::NonCopyable if you want)
        Logger (const Logger &) = delete;
        Logger &operator= (const Logger &) = delete;



    private:

        std::ofstream           myFile;

        unsigned int            numWarnings;
        unsigned int            numErrors;

    }; // class end

}  // namespace




#endif //LOGGER_H
