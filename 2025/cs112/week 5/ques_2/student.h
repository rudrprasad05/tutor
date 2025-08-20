#include <string>

class student{
    public:
        student();
        ~student();
        void set_id(string);
        void set_marks(int);
        void set_grade(char);
        string get_id();
        int get_marks();
        char get_grade();

    private:
        string id;
        int marks;
        char grade;
};

