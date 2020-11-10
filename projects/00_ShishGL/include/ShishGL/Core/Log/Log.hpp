/*============================================================================*/
#ifndef SHISHGL_LOG_HPP
#define SHISHGL_LOG_HPP
/*============================================================================*/
#include <cstdio>
#include <cstdarg>

#include "../Primitives/Time.hpp"
/*============================================================================*/
namespace ShishGL {

    class LogSystem {
    public:

        typedef enum {
            LOG_OK = 0,
            LOG_OPEN_ERR,
            LOG_ALREADY_OPENED,
            LOG_CLOSE_ERR,
            LOG_FILE_BROKEN,
            LOG_PRINT_ERR
        } LogStatus;

        /*--------------------------------------------------------------------*/

        static LogStatus printLog(const char* format, ...)
        __attribute__((format(printf, 1, 2)));

        static LogStatus printWarning(const char* format, ...)
        __attribute__((format(printf, 1, 2)));

        static LogStatus printError(const char* format, ...)
        __attribute__((format(printf, 1, 2)));

        static void flush();

        /*--------------------------------------------------------------------*/

        virtual ~LogSystem() = default;

    private:

        LogSystem() = default;

        /*--------------------------------------------------------------------*/

        static LogStatus openLog();

        static LogStatus closeLog();

        static LogStatus print(const TimeDelta& elapsed,
                               const char* format, va_list args);

        /*--------------------------------------------------------------------*/
        static FILE* LOG_FILE;
        /*--------------------------------------------------------------------*/

        static Timer& RunTimer();

        friend class CoreApplication;
    };

}
/*============================================================================*/
#endif //SHISHGL_LOG_HPP
/*============================================================================*/