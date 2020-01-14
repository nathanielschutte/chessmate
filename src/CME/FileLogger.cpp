#include "FileLogger.h"

namespace GQE {
    FileLogger::FileLogger(const char* filename, bool def_log) {
        mFileStream.open(filename);
        if(mFileStream.is_open()) {
            LogMessage(__FILE__, __LINE__, "FileLogger::ctor()");
        }
    }

    FileLogger::~FileLogger() {
        if(mFileStream.is_open()) {
            LogMessage(__FILE__, __LINE__, "FileLogger::dtor()");
            mFileStream.close();
        }
    }

    std::ostream& FileLogger::getStream(void) {
        std::ostream* result = &gNullStream;
        if(mFileStream.is_open() && IsActive()) {
            result = &mFileStream;
        }
        return *result;
    }

    void FileLogger::logMessage(const char* message) {
        if(mFileStream.is_open() && isActive()) {


            mFileStream << message << std::endl;
        }
    }

    bool isActive(void) {
        return isActive;
    }

    void setActive(bool active) {
        mActive = active;
    }

    void FileLogger::logMessage(const char* source_file, int source_line, const char* message)
  {
    if(mFileStream.is_open() && isActive())
    {
      mFileStream << source_file << ":" << sourceline << ":  " message << std::endl;
    }
  }
}
