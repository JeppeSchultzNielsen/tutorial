#include <iostream>
#include <ausa/json/IO.h>
#include <ausa/sort/SortedReader.h>
#include <ausa/sort/analyzer/AbstractSortedAnalyzer.h>

using namespace std;
using namespace AUSA;
using namespace AUSA::Sort;

class Analyzer : public AbstractSortedAnalyzer {
public:
    // This gets called just after reader.run()
    virtual void setup(const SortedSetupOutput& out) override {
        AbstractSortedAnalyzer::setup(out); // This saves the output for later
    }

    // This gets called once for each event
    virtual void analyze() override {
        n+=1;
    }

    // This is called after all events have been processed
    virtual void terminate() override {
        cout << "This file contains " << n << " events." << endl;
    }

    size_t n = 0;
};


int main(int argc, char* argv[]) {
    if (argc == 1) {
        cerr << "No input file supplied!" << endl;
        exit(1);
    }
    string input = argv[1];
    cout << "Opening " << input << " for analysis" << endl;

    // This will read in the AUSAlib setup
    auto setup = JSON::readSetupFromJSON("setup/setup.json");

    // Create object that will read in data
    SortedReader reader(input, *setup);

    // Create an instance of Analyzer
    auto analyzer = std::make_shared<Analyzer>();

    // Attach analyzer to reader, so it receives data
    reader.attach(analyzer);

    // Loop over all events.
    reader.run();

    return 0;
}
