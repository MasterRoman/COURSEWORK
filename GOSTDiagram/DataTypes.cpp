#include "DataTypes.h"



System::String^ functionTypeToString(FunctionType v)
{
    switch (v)
    {
    case POINTER:   return "0"; break;
    case LINE:   return "1"; break;
    case PROCESS: return "2"; break;
    case DECISSION: return "3"; break;
    case DATA:   return "4"; break;
    case TERMINATOR:   return "5"; break;
    case PAGEREFERENCE: return "6"; break;
    case TEXT: return "7"; break;
    }
}
