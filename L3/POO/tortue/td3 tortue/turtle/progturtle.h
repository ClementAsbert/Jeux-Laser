#ifndef PROGTURTLE_H_INCLUDED
#define PROGTURTLE_H_INCLUDED

#include <string>


namespace lolo{
    class turle;
    class progturtle{
    public:
        progturtle(const std::string& prog="", int step =10, int leftANgle=90, int rightAngle=90);
        std::string programme()const;
        int step() const;
        void run(turle& t);
    protected:
        void setProgram(const std::string& prog);
        void setStep(int step);
    private:
        std::string d_program;
        int d_step;
        int d_leftAngle, d_rightAngle;
    };
}

#endif // PROGTURTLE_H_INCLUDED
