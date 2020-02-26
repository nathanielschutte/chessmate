/**
 * FileLogger header
 *
 */

#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include <string.h>
#include <string>


namespace CME {
    class FileLogger
    {
        public:
            FileLogger(const char* filename, bool def_log = false);

            virtual ~FileLogger();

            virtual std::ostream& getStream(void);

            virtual void logMessage(const char* message);

            virtual void logMessage(const char* file, int line, const char* message);

            virtual bool isActive(void);

            virtual void setActive(bool active);


        protected:

        private:
            std::ofstream mFileStream;

            bool mActive;

            FileLogger(const FileLogger&);

            FileLogger& operator=(const FileLogger&);

    };
}

#endif // FILELOGGER_H
