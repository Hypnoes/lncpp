// tabtenn0.h -- a table-tennis base class
#ifndef TABTENN0_H_
#define TABTENN0_H_
#include <string>

using std::string;

class TableTennisPlayer
{
  private:
    string firstname;
    string lastname;
    bool hasTable;

  public:
    TableTennisPlayer(const string & fn = "none",
                      const string & ln = "none",
                      bool ht = false);
    
    void name() const;
    bool has_table() const { return hasTable; };
    void reset_table(bool v) { hasTable = v; }; 
};

#endif