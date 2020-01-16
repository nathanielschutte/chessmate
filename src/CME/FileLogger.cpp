/**
 * Class to write internal program messages to an output file
 *
 */

#include "FileLogger.h"

namespace CME {
    FileLogger::FileLogger(const char* filename, bool def_log) {
        mFileStream.open(filename);
        if(mFileStream.is_open()) {
            logMessage(__FILE__, __LINE__, "FileLogger::ctor()");
        }
    }

    FileLogger::~FileLogger() {
        if(mFileStream.is_open()) {
            logMessage(__FILE__, __LINE__, "FileLogger::dtor()");
            mFileStream.close();
        }
    }

    std::ostream& FileLogger::getStream(void) {
        std::ostream* result = nullptr;
        if(mFileStream.is_open() && isActive()) {
            result = &mFileStream;
        }
        return *result;
    }

    void FileLogger::logMessage(const char* message) {
        if(mFileStream.is_open() && isActive()) {


            mFileStream << message << std::endl;
        }
    }

    bool FileLogger::isActive(void) {
        return mActive;
    }

    void FileLogger::setActive(bool active) {
        mActive = active;
    }

    void FileLogger::logMessage(const char* source_file, int source_line, const char* message) {
    if(mFileStream.is_open() && isActive()) {
      mFileStream << source_file << ":" << source_line << ":  " << message << std::endl;
    }
  }
}
