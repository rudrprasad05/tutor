package com.rudrprasad;

class Student implements Comparable{ //try comparator as HW
    int id;
    String name;
    float GPA;
    Student (int id, String name, float gpa){
        this.id = id;
        this.name = name;
        this.GPA = gpa;
    }
    @Override
    public String toString() {
        return "[" + id + ", " + name + ", "+GPA+"]";
    }

    @Override
    public int compareTo(Object obj) { //dynamic binding
        if (!(obj instanceof Student)) {
            throw new ClassCastException("Not a Student");
        }
        Student s = (Student)obj; //invalid downcasting

        return Float.compare(s.GPA, this.GPA);
    }
}
