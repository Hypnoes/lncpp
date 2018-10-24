// tabtenn1.h -- a table-tennis base class
#ifndef TABTENN1_H_
#define TABTENN1_H_
#include <string>
using std::string;

class TableTennisPlayer
{
  private:
    string _firstname;
    string _lastname;
    bool _hasTable;

  public:
    TableTennisPlayer(const string & fn = "none",
                      const string & ln = "none",
                      bool ht = false);
    
    void name() const;
    bool has_table() const { return _hasTable; }
    void reset_table(bool v) { _hasTable = v; }
};

class RatedPlayer : public TableTennisPlayer
{
  private:
    unsigned int _rating;

  public:
    RatedPlayer(unsigned int r = 0, const string & fn = "none",
                const string & ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int rating() const { return _rating; }
    void reset_rating(unsigned int r) { _rating = r; }
};
#endif