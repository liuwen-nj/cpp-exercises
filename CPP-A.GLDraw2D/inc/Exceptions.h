#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_
#include <string>


class CError {
  private:
  std::string message;

  public:
  CError(std::string message) : message(message) {};

  std::string getMessage() {
    return message;
  }
};

class CErrorFileID : public CError {
public:
  CErrorFileID() : CError("Unknown file type!") {}
};

class CErrorFigureType : public CError {
public:
  CErrorFigureType() : CError("Unknown figure type!") {}
};

#endif
