#include <iostream>
#include <vector>
#include <string>
#include <set>


using namespace std;

struct Nota {
    int value;
    string subject;
};



// aceasta este clasa de baza/parinte
class PersoanaEvaluata {
protected:
    vector<Nota> note;// atributele din clasa de bază se pun sub eticheta protected:
public:
    // constructor cu toti parametrii
    PersoanaEvaluata(const vector<Nota> &note) : note(note) {}
    // metoda mean va fi comuna tuturor claselor derivate din PersoanaEvaluata
    double mean() {
        double sum = 0;
        for(auto nota : note) {
            sum += nota.value;
        }
        return sum / note.size();
    }
};


// acestea sunt clasele derivate:
class Pupil : public PersoanaEvaluata { // aceasta este sintaxa pentru „moștenire publică”
private:
    // adaugam noi atribute
    string cycle;
public:
    // constructori:
    // TODO va rog sa-i implementati si in clasele derivate, pentru antrenament:

    Pupil(const vector<Nota> &note) : PersoanaEvaluata(note) {}

    Pupil(const vector<Nota> &note, const string &cycle) : PersoanaEvaluata(note), cycle(cycle) {}

    // adaugam SI noi metode
    void showGradeSheet() {
        for(auto n : note){
            cout<<"Subject: "<<n.subject<<", grade: "<<n.value;

        }

        // e.g.
        //  subject: literature, value: 10
        //  subject: mathematics, value: 9
    }
    void gradesGroupedBySubject() {
        // TODO similar cu showGradeSheet, dar daca aveti doua note la aceiasi materie

        set<string> all_subjects;
        for(auto n : note){
            all_subjects.insert(n.subject);

        }

        // hint: step-by-step
        //  puteti prima data crea un vector cu toate materiile (vector<string>)

        for(auto sub: all_subjects){
            cout<<sub<<": ";

            for(auto grade: note){
                if(grade.subject == sub){
                    cout<<grade.value<<" ";
                }
            }

            cout<<endl;
        }
        //  iar dupa aceea parcurgeti cu un prim for subiectele, iar cu un al doilea for parcurgeti toate notele si le afisati pe cele cu acea materie

        // e.g. afisare
        // literature: 10 9
        // mathematics: 8 7 10
    }
};

class Student: public PersoanaEvaluata{
private:
    string facultate;
public:

    const string &getFacultate() const {
        return facultate;
    }

    void setFacultate(const string &facultate) {
        Student::facultate = facultate;
    }

    Student(const vector<Nota> &note, const string &facultate) : PersoanaEvaluata(note), facultate(facultate) {}



};

class CourseTaker: public PersoanaEvaluata{
private:
    string course_name;
public:

    const string &getCourseName() const {
        return course_name;
    }

    void setCourseName(const string &courseName) {
        course_name = courseName;
    }

    CourseTaker(const vector<Nota> &note, const string &courseName) : PersoanaEvaluata(note), course_name(courseName) {}

};


int main() {


    return 0;
}
