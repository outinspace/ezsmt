#ifndef SMTSOLVER_H_
#define SMTSOLVER_H_

#include "param.h"
#include "program.h"
#include <boost/process.hpp>

class SMTSolver {
public:
  void callSMTSolver(Param &params, Program &program);

private:
  bool parseSolverResults(boost::process::ipstream &inputStream,
                                   vector<string> &resultAnswerSet,
                                   map<string, string> &resultMinimizationValues);
  string getProgramBodyString(Program &program);
  string getCheckSatString(Program &program);
  string getAnswerSetNegationString(vector<string> &answerSet);
  string getMinimizationAssertionString(map<string,string> &minimizationResults);
  void writeToFile(string input, string outputFileName);
};

#endif // SMTSOLVER_H_
