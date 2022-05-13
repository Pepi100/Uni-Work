#include <iostream>
#include <vector>
#include <string>
#include <set>


using namespace std;


template<typename T>
istream& operator>>(istream& is, vector<T> &v){
    int nr_elem;
    T elem;
    cout<<"Introduceti numarul de elemente: ";
    is>>nr_elem;
    cout<<"Introduceti cele "<<nr_elem<<" elemente separate prin ENTER: ";
    for(int i=1;i<=nr_elem;i++){
        is>>elem;
        v.push_back(elem);
    }
    return is;
}


class Nota {
        protected:
    int value;
    string subject;
        public:
            friend istream& operator>>(istream& is,  Nota& nota);

    int getValue() const {
        return value;
    }

    const string &getSubject() const {
        return subject;
    }

};

istream& operator>>(istream& is,  Nota& nota){
    cout<<"Materie: ";
    is>>nota.subject;
    cout<<"Nota: ";
    is>>nota.value;
    return is;
}

class IoBase {
private:
public:
    // metoda citire
    virtual istream& read(istream& is) { // nu este nevoie de obiectul citit, pt ca avem this
        return is; // vom vedea ca in interfete deseori nu avem functionalitati
    }
    // metoda scriere
    virtual ostream& write(ostream& os) const { // nu este nevoie de obiectul citit, pt ca avem this
        return os; // vom vedea ca in interfete deseori nu avem functionalitati
    }

    friend ostream &operator<<(ostream &os, const IoBase &base) {
        return base.write(os);
    }

    friend istream &operator>>(istream &is, IoBase &base) {
        return base.read(is);
    }



};



// aceasta este clasa de baza/parinte
class PersoanaEvaluata: public IoBase{
protected:
    vector<Nota> note;// atributele din clasa de bază se pun sub eticheta protected:
public:
    // constructor cu toti parametrii
    PersoanaEvaluata(const vector<Nota> &note) : note(note) {}

    PersoanaEvaluata() = default;
    // metoda mean va fi comuna tuturor claselor derivate din PersoanaEvaluata
    double mean() {
        double sum = 0;
        for(auto nota : note) {
            sum += nota.getValue();
        }
        return sum / note.size();
    }

    istream &read(istream &is) override {
        IoBase::read(is);
        cout<<"Citire note:\n";
        is>>note;

        return is;
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
            cout<<"Subject: "<<n.getSubject()<<", grade: "<<n.getValue();

        }

        // e.g.
        //  subject: literature, value: 10
        //  subject: mathematics, value: 9
    }
    void gradesGroupedBySubject() {
        // TODO similar cu showGradeSheet, dar daca aveti doua note la aceiasi materie

        set<string> all_subjects;
        for(auto n : note){
            all_subjects.insert(n.getSubject());

        }

        // hint: step-by-step
        //  puteti prima data crea un vector cu toate materiile (vector<string>)

        for(auto sub: all_subjects){
            cout<<sub<<": ";

            for(auto grade: note){
                if(grade.getSubject() == sub){
                    cout<<grade.getValue()<<" ";
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

    PersoanaEvaluata p;
    cin>>p;


    return 0;
}
